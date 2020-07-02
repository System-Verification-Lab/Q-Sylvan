/*
 * Copyright 2011-2016 Formal Methods and Tools, University of Twente
 * Copyright 2016-2017 Tom van Dijk, Johannes Kepler University Linz
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* Do not include this file directly. Instead, include sylvan.h */


/**
 *
A QMDD can represent exponentially-sized vectors and matrices of complex numbers
including quantum states and gates. For those familiar with the literature on
decision diagrams, it might be helpful to understand the relation between QMDDDs
and other DD variants. Perhaps surprisingly, the QMDD data structure is more
similar to binary DDs (but additionally adorned with edge weights) than to a
multi-terminal or multi-values DDs, as its name and purpose seems to suggest.
A multi-terminal DD, aka algebraic DD or ADD, represents a function
f : B^n --> D, where D,  the domain, is an algebra, e.g., the complex numbers.
ADDs can therefore immediately be used to encode quantum systems as well,
though less efficiently [1].
A multi-valued DD represents functions f : D^n --> B and is typically used to
encode high-level systems such as programs with multi-valued variables.

Structurally, a QMDD is an Ordered and Reduced BDD (ORBDD) with weighted edges.
The root node also has a weighted start edge. As a BDD, each node has a
variable x and two outgoing edges to QMDDs: a low and a high edge representing
x=0 and x=1. Edge weights are normalized by dividing the weights of the low and
high edges by that of the low edge (unless it equals zero) and propagating alpha
upwards through the incoming edge. This normalization achieves additional
reductions in the structure and should not be confused with the normalization
of quantum states, i.e., QMDDs are more general than quantum systems.

Formally, a QMDD edge e is a pair (Q,w), where Q is (a pointer to) a QMMD node,
w in C is a weight representing a normalized amplitude. A QMDD node is either a
constant 1 or a tuple (x,l,h) where x is a (Boolean) variable and
l, h QMDD edges such that:
- x < l.Q.x, r.Q.x,         (similar to the ordering in ORBDDs)
- (x,l,h) is unique,        (similar to the reduction in ORBDDs)
- l != h, and               (similar to the deletion rule from ORBDDs)
- l.w in {0,1}.             (by normalization)

A QMDD (edge) e is thus interpreted as a function [[ e ]] : (X --> B) --> C,
where X are the variables, and B,C the Boolean / Complex domains.
Each path to the 1 leaf node represents an assignment A : X --> B to the
variables x in X of the nodes along the path (x=0 for low and x=1 for high),
and an amplitude defined by multiplying the weights along the path.
Formally, the semantics of [[ e ]] for a QMDD edge e is defined as:
[[ (1,w) ]]      := { {} --> w }
[[ (Q,w) ]]      := { {Q.x = 0} U A --> w * Q.l.w | (s,A) in [[ Q.l ]]  } U
                    { {Q.x = 1} U A --> w * Q.r.w | (s,A) in [[ Q.h ]]  }
For each assignment A in B^X, we may interpret [[ e ]](A) as usual by
interpreting unassigned variables as `don't cares`, i.e.,
 [[ e ]](A)      := w such that exists (A',w) in [[ e ]] with A' subseteq A.
 (Note that by the ordered property, such an (A',w) is unqiue in [[ e ]].)
Alternative, we might extend the QMDD of e by re-adding all deleted nodes (see
definition above). This can be done by adding `don't care` nodes (x,(Q,1),(Q,1))
between edges which skip a variable, i.e., l.x != x+1 or h.x != x+1.
Formally, we replace each node (x,l,h) with (x, n_x+1, h), where
- n_i := (i, (1,n_i+1),  (1,n_i+1) )            for i < l.x - 1, and
- n_i := (i, l, h)                              for i = l.x - 1.
And analogously for the high edges.

 */


#ifndef SYLVAN_QDD_H
#define SYLVAN_QDD_H

#include <stdbool.h>
#include <stdint.h>

#include <sylvan_mtbdd.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * 
 * QDD : essentially an edge, containing [var, amp, pointer]
 *  - var: the variable/qubit numer (unclear whether this variable refers to the
 *         node this edge is an outgoing edge of, or the node this edge is an 
 *         incomming edge to.)
 *  - amp: the (index of) the amplitude on this edge.
 *  - pointer: a number which identifies the node this edge is pointing _to_.
 * qddnote_t : essentially a node, containing two edges (to its children).
 */

/**
 * low 40 bits          = pointer
 * high 20/24 bits      = amplitude (normalized)
 * 0x[0][00000][0000000000]
 */
typedef uint64_t QDD; // QDD edge
typedef uint64_t AMP; // amplitude index
typedef uint64_t PTR; // node index (TODO: rename PTR to something else to avoid
                      // ambiguity with actual pointers)


/**
 * QDD with pointer value 1, and amplitude 1. However we need to be able to 
 * point to the root with amplitudes other than 1?
 * NOTE: renamed ONE -> QDD_ONE for now because of conflict with Bdd ONE
 */
static const QDD        QDD_ONE = (1ULL << 40) | 1; // 0x[0][00001][0000000001]
//static const QDD        QDD_TERMINAL = 1; // 0x[0][00000][0000000001]
static const PTR        QDD_TERMINAL = 1;


static const AMP        NIL = 0;


#define qdd_plus(a,b) (CALL(qdd_plus,a,b));
TASK_DECL_2(QDD, qdd_plus, QDD, QDD);

#define qdd_gate(q,gate,qubit) (CALL(qdd_gate,q,gate,qubit));
TASK_DECL_3(QDD, qdd_gate, QDD, uint32_t, BDDVAR);

#define qdd_cgate(q,gate,c,t) (CALL(qdd_cgate,q,gate,c,t));
TASK_DECL_4(QDD, qdd_cgate, QDD, uint32_t, BDDVAR, BDDVAR);

/**
 * Applies a swap gate on the given qubits.
 */
QDD qdd_swap_gate(QDD qdd, BDDVAR qubit1, BDDVAR qubit2);

/**
 * Applies a controlled swap gate, with the given control and targets.
 */
#define qdd_cswap_gate(qdd, c, t1, t2) (CALL(qdd_cswap_gate,qdd,c,t1,t2));
TASK_DECL_4(QDD, qdd_cswap_gate, QDD, BDDVAR, BDDVAR, BDDVAR);

/**
 * Applies a phase of -1 to a single basis state |x>.
 * This is a CZ gate where we control on all qubits and when x_k = 0 we control
 * qubit k on 0, and where x_k = 1 we control qubit k on 1.
 * 
 * @param qdd A QDD encoding some quantum state |\psi>.
 * @param n Number of qubits.
 * @param x A bitstring x of some computational basis state |x>.
 * 
 * TODO: generalize this to control on some but not all qubits.
 */
#define qdd_all_control_phase(qdd, n, x) (CALL(qdd_all_control_phase,qdd,0,n,x));
TASK_DECL_4(QDD, qdd_all_control_phase, QDD, BDDVAR, BDDVAR, bool*);

/**
 * Executes the QFT circuit on qubits `first` through `last`.
 * 
 * @param swap Yes or no swapping of qubit order.
 */
QDD qdd_QFT(QDD qdd, BDDVAR first, BDDVAR last, bool swap);

/**
 * Executes the inverse QFT circuit on qubits `first` through `last`.
 * 
 * @param swap Yes or no swapping of qubit order.
 */
QDD qdd_QFT_inv(QDD qdd, BDDVAR first, BDDVAR last, bool swap);


/**
 * Exectutes Grover on an n qubit circuit with a single flagged element.
 * 
 * @param n Number of qubits.
 * @param flag Binary representation of some integer in [0, 2^n]
 */
QDD qdd_grover(BDDVAR n, bool* flag);

/**
 * The flollowing functions are a breakdown of the components needed for Shor
 * as in Beauregard, "Circuit for Shor's algorithm using 2n+ 3 qubits." (2002).
 */
/**
 * Implements circuit in Fig. 3.
 * Addition in Fourier space. Important here to note is the endianess (which I 
 * often struggel with to get the right way around). If |x> is a basis state
 * written like |q0, q1, q2>, and a is a bit-vector a[0], a[1], a[1], both are/ 
 * should be encoded with the MSB in the q0/a[0] position. That way, if we index
 * x/a "forwards" we have the "normal" binary representation of an integer.
 * Carries happen from q(k) -> q(k-1) (so e.g. from q1 to q0), so if we write
 * the state as |q0, q1, q2> carries go to the left (as normal).
 * 
 * @param qdd A QDD encoding a state |phi(x)> = QFT|x> with |x> a z-basis state.
 * @param a A big-endian (MSB first) encoding of some integer.
 * 
 * Returns A QDD encoding |phi(x + a)>, with (x+a)
 */
QDD qdd_phi_add(QDD qdd, BDDVAR first, BDDVAR last, bool* a);
QDD qdd_phi_add_inv(QDD qdd, BDDVAR first, BDDVAR last, bool* a);
QDD qdd_phi_add_mod();
QDD qdd_cmult();
QDD qdd_shor();


/**
 * Computational basis measurement on qubit q0.
 * 
 * @param qdd A QDD encoding of some n qubit state.
 * @param m Return of measurement outcome (0 or 1)
 * 
 * @return QDD of post-measurement state corresponding to measurement outcome.
 */
QDD qdd_measure_q0(QDD qdd, int *m, double *p);

/**
 * (Recursive) helper function for obtaining probabilities for measurements
 */
#define _qdd_unnormed_prob(qdd) (CALL(_qdd_unnormed_prob, qdd));
TASK_DECL_1(QDD, _qdd_unnormed_prob, QDD);

/**
 * Get amplitude of given basis state.
 * 
 * @param qdd A QDD encoding some quantum state |\psi>.
 * @param basis_state A bitstring x of some computational basis state |x>.
 * 
 * @return The amplitude <x|\psi>.
 */
extern AMP qdd_get_amplitude(QDD qdd, bool* basis_state);

double _prob(AMP a);

/**
 * Creates a QDD for an n-qubit state |00...0>.
 * 
 * @param n Number of qubits.
 * 
 * @return A QDD encoding the n-qubit state |00..0>.
 */
extern QDD qdd_create_all_zero_state(int n);

/**
 * Creates a QDD for an n-qubit state |x>.
 * 
 * @param n Number of qubits.
 * @param x A bitstring x \in {0,1}^n. 
 * 
 * @return A QDD encoding of the n-qubit state |x>.
 */
extern QDD qdd_create_basis_state(int n, bool* x);


/**
 * Checks if the states represented by two QDDs are the same. In principle the
 * root edges of these QDDs should always be the same if they represent the
 * same state, so this is mostly a debug/testing function.
 * 
 * @param a A QDD representing a quantum state |\psi>
 * @param b A QDD representing a quantum state |\phi>
 * @param n Number of qubits
 * @param exact If true, |\psi> should equal |\phi> exactly (float equal),
 * otherwise allow for preset float equivalence margine.
 * 
 * @returns True iff |\psi> == |\phi>.
 */
extern bool qdd_equivalent(QDD a, QDD b, int n, bool exact, bool verbose);


// counts the nodes by recursively marking them (and unmarks when done)
extern uint64_t qdd_countnodes(QDD qdd);

/**
 * Write a .dot representation of a given QDD
 */
void qdd_fprintdot(FILE *out, QDD qdd);


// debug stuff
extern void qdd_printnodes(QDD q);
bool _next_bitstring(bool *x, int n);
void _print_bitstring(bool *x, int n);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
