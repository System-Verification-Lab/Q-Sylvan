// Benchmark was created by MQT Bench on 2022-08-30
// For more information about MQT Bench, please visit https://www.cda.cit.tum.de/mqtbench/
// MQT Bench version: 0.1.0
// Qiskit version: {'qiskit-terra': '0.20.0', 'qiskit-aer': '0.10.4', 'qiskit-ignis': '0.7.0', 'qiskit-ibmq-provider': '0.19.0', 'qiskit-aqua': None, 'qiskit': '0.36.0', 'qiskit-nature': '0.3.1', 'qiskit-finance': '0.3.1', 'qiskit-optimization': '0.3.2', 'qiskit-machine-learning': '0.4.0'}

OPENQASM 2.0;
include "qelib1.inc";
qreg q[4];
creg meas[4];
ry(0.580169784163287) q[0];
ry(0.261360072880478) q[1];
cx q[0],q[1];
ry(0.599110393870138) q[2];
cx q[0],q[2];
cx q[1],q[2];
ry(0.67200669204436) q[3];
cx q[0],q[3];
ry(0.184657785559301) q[0];
cx q[1],q[3];
ry(0.0609790260792745) q[1];
cx q[0],q[1];
cx q[2],q[3];
ry(0.180812204782775) q[2];
cx q[0],q[2];
cx q[1],q[2];
ry(0.598336557162399) q[3];
cx q[0],q[3];
ry(0.0433882011887894) q[0];
cx q[1],q[3];
ry(0.622486536868047) q[1];
cx q[0],q[1];
cx q[2],q[3];
ry(0.219369919322955) q[2];
cx q[0],q[2];
cx q[1],q[2];
ry(0.605325809472838) q[3];
cx q[0],q[3];
ry(0.276501277330234) q[0];
cx q[1],q[3];
ry(0.83327983568156) q[1];
cx q[2],q[3];
ry(0.254356037916955) q[2];
ry(0.235872435083127) q[3];
barrier q[0],q[1],q[2],q[3];
measure q[0] -> meas[0];
measure q[1] -> meas[1];
measure q[2] -> meas[2];
measure q[3] -> meas[3];
