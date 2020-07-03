#ifndef SYLVAN_QDD_INT_H
#define SYLVAN_QDD_INT_H

/**
 * Complex values with lookup table
 *
 * Based on [1]
 */


#include <math.h>
#include <stdint.h>
#include "util/cmap.h"


//typedef struct complex_s {
//   long double r;   // real
//   long double i;   // imaginary
//} complex_t;


typedef uint64_t cint;

cint C_ZERO; // TODO: don't hashed
cint C_ONE; // TODO: don't hashed

// GATE_ID's (gates are initialized in qdd_complex_init)
// currently 24 bits available for this number (see GATE_OPID)
static const uint32_t GATEID_I = 0;
static const uint32_t GATEID_X = 1;
static const uint32_t GATEID_Y = 2;
static const uint32_t GATEID_Z = 3;
static const uint32_t GATEID_H = 4;
static const uint32_t GATEID_S = 5;
static const uint32_t GATEID_T = 6;
static const uint32_t GATEID_Tdag = 7;
// The next 255 gates are reserved for parameterized phase gates, which are
// initialized below. (these are GATEIDs 8 (0b00001000) through 263 (0b11111000))
// The reason why these are initialized beforhand instead of on-demand is that 
// we need a (for example) pi/16 gate always to have the same unique ID 
// throughout the entire run of the circuit.
// TODO: maybe find a better way?
void init_phase_gates(int n);
static inline uint32_t GATEID_Rk(int k) { return k + 8; };
// Another 255 parameterized phase gates, but this time with negative angles.
// (GATEIDs 264 through 519)
static inline uint32_t GATEID_Rk_dag(int k){ return k + 264; };

static const uint32_t GATEID_swap = 520; // only used as ID for caching 
// 2x2 gates, k := GATEID_U 
// gates[k][0] = u00 (top left)
// gates[k][1] = u01 (top right)
// gates[k][2] = u10 (bottom left)
// gates[k][3] = u11 (bottom right)
cint gates[521][4]; // max 2^16 gates atm


//uint32_t Ctentries;

// basic operations on complex values
// meanings are self-evident from the names
// NOTE arguments are the indices to the values 
// in the complex value table not the values themselves

// Some of these methods are exposed for unit testing, but don't need to be
// used in the qdd implementation.
complex_t Cmake (double r, double i);
double Qmake (int a, int b, int c);
cint Clookup (complex_t c);

complex_t Cvalue(cint);
void Cprint(complex_t);
void Cprint_bitvalues(cint);

bool CexactEqual(complex_t, complex_t);
bool CapproxEqual(complex_t, complex_t);
bool CepsilonClose(complex_t, complex_t, double);

cint Cnegative(cint);
cint Cadd(cint,cint);
cint Csub(cint,cint);
cint Cmul(cint,cint);
cint CintMul(cint,cint); // multiply by an integer
cint Cdiv(cint,cint);
//cint CAbs(cint); /// by PN: returns the absolut value of a complex number
//cint CUnit(cint a); ///by PN: returns whether a complex number has norm 1

//bool Ccomp(complex_t x, complex_t y);

void init_amplitude_table(int logsize);
void free_amplitude_table();
void init_new_empty_table();
void delete_old_table();
cint move_from_old_to_new(cint);


#endif
