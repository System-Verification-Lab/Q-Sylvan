// Benchmark was created by MQT Bench on 2022-08-30
// For more information about MQT Bench, please visit https://www.cda.cit.tum.de/mqtbench/
// MQT Bench version: 0.1.0
// Qiskit version: {'qiskit-terra': '0.20.0', 'qiskit-aer': '0.10.4', 'qiskit-ignis': '0.7.0', 'qiskit-ibmq-provider': '0.19.0', 'qiskit-aqua': None, 'qiskit': '0.36.0', 'qiskit-nature': '0.3.1', 'qiskit-finance': '0.3.1', 'qiskit-optimization': '0.3.2', 'qiskit-machine-learning': '0.4.0'}

OPENQASM 2.0;
include "qelib1.inc";
qreg q[4];
creg meas[4];
h q[0];
h q[1];
rzz(5.48443202342336) q[0],q[1];
h q[2];
rzz(5.48443202342336) q[0],q[2];
rx(-0.0541426052973364) q[0];
h q[3];
rzz(5.48443202342336) q[1],q[3];
rx(-0.0541426052973364) q[1];
rzz(-3.81470568379408) q[0],q[1];
rzz(5.48443202342336) q[2],q[3];
rx(-0.0541426052973364) q[2];
rzz(-3.81470568379408) q[0],q[2];
rx(-2.35919676382728) q[0];
rx(-0.0541426052973364) q[3];
rzz(-3.81470568379408) q[1],q[3];
rx(-2.35919676382728) q[1];
rzz(-3.81470568379408) q[2],q[3];
rx(-2.35919676382728) q[2];
rx(-2.35919676382728) q[3];
barrier q[0],q[1],q[2],q[3];
measure q[0] -> meas[0];
measure q[1] -> meas[1];
measure q[2] -> meas[2];
measure q[3] -> meas[3];
