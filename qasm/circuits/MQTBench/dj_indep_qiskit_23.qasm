// Benchmark was created by MQT Bench on 2022-08-30
// For more information about MQT Bench, please visit https://www.cda.cit.tum.de/mqtbench/
// MQT Bench version: 0.1.0
// Qiskit version: {'qiskit-terra': '0.20.0', 'qiskit-aer': '0.10.4', 'qiskit-ignis': '0.7.0', 'qiskit-ibmq-provider': '0.19.0', 'qiskit-aqua': None, 'qiskit': '0.36.0', 'qiskit-nature': '0.3.1', 'qiskit-finance': '0.3.1', 'qiskit-optimization': '0.3.2', 'qiskit-machine-learning': '0.4.0'}

OPENQASM 2.0;
include "qelib1.inc";
qreg q[23];
creg c[22];
h q[0];
h q[1];
u2(0,0) q[2];
h q[3];
h q[4];
u2(0,0) q[5];
u2(0,0) q[6];
u2(0,0) q[7];
h q[8];
u2(0,0) q[9];
h q[10];
u2(0,0) q[11];
u2(0,0) q[12];
h q[13];
h q[14];
h q[15];
u2(0,0) q[16];
h q[17];
u2(0,0) q[18];
u2(0,0) q[19];
u2(0,0) q[20];
u2(0,0) q[21];
u2(-pi,-pi) q[22];
cx q[0],q[22];
h q[0];
cx q[1],q[22];
h q[1];
cx q[2],q[22];
u2(-pi,-pi) q[2];
cx q[3],q[22];
h q[3];
cx q[4],q[22];
h q[4];
cx q[5],q[22];
u2(-pi,-pi) q[5];
cx q[6],q[22];
u2(-pi,-pi) q[6];
cx q[7],q[22];
u2(-pi,-pi) q[7];
cx q[8],q[22];
h q[8];
cx q[9],q[22];
cx q[10],q[22];
h q[10];
cx q[11],q[22];
u2(-pi,-pi) q[11];
cx q[12],q[22];
u2(-pi,-pi) q[12];
cx q[13],q[22];
h q[13];
cx q[14],q[22];
h q[14];
cx q[15],q[22];
h q[15];
cx q[16],q[22];
u2(-pi,-pi) q[16];
cx q[17],q[22];
h q[17];
cx q[18],q[22];
u2(-pi,-pi) q[18];
cx q[19],q[22];
u2(-pi,-pi) q[19];
cx q[20],q[22];
u2(-pi,-pi) q[20];
cx q[21],q[22];
u2(-pi,-pi) q[21];
u2(-pi,-pi) q[9];
barrier q[0],q[1],q[2],q[3],q[4],q[5],q[6],q[7],q[8],q[9],q[10],q[11],q[12],q[13],q[14],q[15],q[16],q[17],q[18],q[19],q[20],q[21],q[22];
measure q[0] -> c[0];
measure q[1] -> c[1];
measure q[2] -> c[2];
measure q[3] -> c[3];
measure q[4] -> c[4];
measure q[5] -> c[5];
measure q[6] -> c[6];
measure q[7] -> c[7];
measure q[8] -> c[8];
measure q[9] -> c[9];
measure q[10] -> c[10];
measure q[11] -> c[11];
measure q[12] -> c[12];
measure q[13] -> c[13];
measure q[14] -> c[14];
measure q[15] -> c[15];
measure q[16] -> c[16];
measure q[17] -> c[17];
measure q[18] -> c[18];
measure q[19] -> c[19];
measure q[20] -> c[20];
measure q[21] -> c[21];
