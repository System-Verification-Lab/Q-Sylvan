// Benchmark was created by MQT Bench on 2022-08-30
// For more information about MQT Bench, please visit https://www.cda.cit.tum.de/mqtbench/
// MQT Bench version: 0.1.0
// Qiskit version: {'qiskit-terra': '0.20.0', 'qiskit-aer': '0.10.4', 'qiskit-ignis': '0.7.0', 'qiskit-ibmq-provider': '0.19.0', 'qiskit-aqua': None, 'qiskit': '0.36.0', 'qiskit-nature': '0.3.1', 'qiskit-finance': '0.3.1', 'qiskit-optimization': '0.3.2', 'qiskit-machine-learning': '0.4.0'}

OPENQASM 2.0;
include "qelib1.inc";
qreg eval[2];
qreg q[1];
creg meas[3];
u2(0,-pi) eval[0];
u2(0,-pi) eval[1];
u3(0.92729522,0,0) q[0];
cx eval[0],q[0];
u(-0.92729522,0,0) q[0];
cx eval[0],q[0];
u3(0.92729522,0,0) q[0];
cx eval[1],q[0];
u(-1.8545904,0,0) q[0];
cx eval[1],q[0];
u(1.8545904,0,0) q[0];
h eval[1];
cp(-pi/2) eval[0],eval[1];
h eval[0];
barrier eval[0],eval[1],q[0];
measure eval[0] -> meas[0];
measure eval[1] -> meas[1];
measure q[0] -> meas[2];
