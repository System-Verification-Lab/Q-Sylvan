// Benchmark was created by MQT Bench on 2022-08-30
// For more information about MQT Bench, please visit https://www.cda.cit.tum.de/mqtbench/
// MQT Bench version: 0.1.0
// Qiskit version: {'qiskit-terra': '0.20.0', 'qiskit-aer': '0.10.4', 'qiskit-ignis': '0.7.0', 'qiskit-ibmq-provider': '0.19.0', 'qiskit-aqua': None, 'qiskit': '0.36.0', 'qiskit-nature': '0.3.1', 'qiskit-finance': '0.3.1', 'qiskit-optimization': '0.3.2', 'qiskit-machine-learning': '0.4.0'}

OPENQASM 2.0;
include "qelib1.inc";
qreg q[26];
creg meas[26];
h q[0];
h q[1];
cz q[0],q[1];
h q[2];
cz q[0],q[2];
h q[3];
h q[4];
cz q[3],q[4];
h q[5];
h q[6];
cz q[5],q[6];
h q[7];
h q[8];
cz q[5],q[8];
cz q[7],q[8];
h q[9];
h q[10];
cz q[9],q[10];
h q[11];
cz q[9],q[11];
h q[12];
h q[13];
cz q[6],q[13];
cz q[12],q[13];
h q[14];
cz q[1],q[14];
cz q[11],q[14];
h q[15];
cz q[4],q[15];
h q[16];
cz q[15],q[16];
h q[17];
h q[18];
cz q[17],q[18];
h q[19];
cz q[12],q[19];
h q[20];
cz q[19],q[20];
h q[21];
cz q[3],q[21];
cz q[16],q[21];
h q[22];
cz q[17],q[22];
cz q[20],q[22];
h q[23];
cz q[2],q[23];
cz q[18],q[23];
h q[24];
cz q[7],q[24];
h q[25];
cz q[10],q[25];
cz q[24],q[25];
barrier q[0],q[1],q[2],q[3],q[4],q[5],q[6],q[7],q[8],q[9],q[10],q[11],q[12],q[13],q[14],q[15],q[16],q[17],q[18],q[19],q[20],q[21],q[22],q[23],q[24],q[25];
measure q[0] -> meas[0];
measure q[1] -> meas[1];
measure q[2] -> meas[2];
measure q[3] -> meas[3];
measure q[4] -> meas[4];
measure q[5] -> meas[5];
measure q[6] -> meas[6];
measure q[7] -> meas[7];
measure q[8] -> meas[8];
measure q[9] -> meas[9];
measure q[10] -> meas[10];
measure q[11] -> meas[11];
measure q[12] -> meas[12];
measure q[13] -> meas[13];
measure q[14] -> meas[14];
measure q[15] -> meas[15];
measure q[16] -> meas[16];
measure q[17] -> meas[17];
measure q[18] -> meas[18];
measure q[19] -> meas[19];
measure q[20] -> meas[20];
measure q[21] -> meas[21];
measure q[22] -> meas[22];
measure q[23] -> meas[23];
measure q[24] -> meas[24];
measure q[25] -> meas[25];
