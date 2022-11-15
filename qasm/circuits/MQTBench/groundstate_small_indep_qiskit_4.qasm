// Benchmark was created by MQT Bench on 2022-08-30
// For more information about MQT Bench, please visit https://www.cda.cit.tum.de/mqtbench/
// MQT Bench version: 0.1.0
// Qiskit version: {'qiskit-terra': '0.20.0', 'qiskit-aer': '0.10.4', 'qiskit-ignis': '0.7.0', 'qiskit-ibmq-provider': '0.19.0', 'qiskit-aqua': None, 'qiskit': '0.36.0', 'qiskit-nature': '0.3.1', 'qiskit-finance': '0.3.1', 'qiskit-optimization': '0.3.2', 'qiskit-machine-learning': '0.4.0'}

OPENQASM 2.0;
include "qelib1.inc";
qreg q[4];
creg meas[4];
u2(0,3.0570059) q[0];
u2(0,2.8753698) q[1];
cz q[0],q[1];
u2(0,2.6992779) q[2];
cz q[0],q[2];
cz q[1],q[2];
u2(0,-1.0118404) q[3];
cz q[0],q[3];
u2(0,1.9810096) q[0];
cz q[1],q[3];
u2(0,-2.4361481) q[1];
cz q[0],q[1];
cz q[2],q[3];
u2(0,1.9254609) q[2];
cz q[0],q[2];
cz q[1],q[2];
u2(0,-0.57175798) q[3];
cz q[0],q[3];
u2(0,0.59083032) q[0];
cz q[1],q[3];
u2(0,1.541681) q[1];
cz q[2],q[3];
u2(0,2.1796296) q[2];
u2(0,-1.494846) q[3];
barrier q[0],q[1],q[2],q[3];
measure q[0] -> meas[0];
measure q[1] -> meas[1];
measure q[2] -> meas[2];
measure q[3] -> meas[3];
