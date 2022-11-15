// Benchmark was created by MQT Bench on 2022-08-30
// For more information about MQT Bench, please visit https://www.cda.cit.tum.de/mqtbench/
// MQT Bench version: 0.1.0
// Qiskit version: {'qiskit-terra': '0.20.0', 'qiskit-aer': '0.10.4', 'qiskit-ignis': '0.7.0', 'qiskit-ibmq-provider': '0.19.0', 'qiskit-aqua': None, 'qiskit': '0.36.0', 'qiskit-nature': '0.3.1', 'qiskit-finance': '0.3.1', 'qiskit-optimization': '0.3.2', 'qiskit-machine-learning': '0.4.0'}

OPENQASM 2.0;
include "qelib1.inc";
qreg eval[17];
qreg q[1];
creg meas[18];
u2(0,-pi) eval[0];
u2(0,-pi) eval[1];
u2(0,-pi) eval[2];
u2(0,-pi) eval[3];
u2(0,-pi) eval[4];
u2(0,-pi) eval[5];
u2(0,-pi) eval[6];
u2(0,-pi) eval[7];
u2(0,-pi) eval[8];
u2(0,-pi) eval[9];
u2(0,-pi) eval[10];
u2(0,-pi) eval[11];
u2(0,-pi) eval[12];
u2(0,-pi) eval[13];
u2(0,-pi) eval[14];
u2(0,-pi) eval[15];
u2(0,-pi) eval[16];
u3(0.92729522,0,0) q[0];
cx eval[0],q[0];
u(-0.92729522,0,0) q[0];
cx eval[0],q[0];
u3(0.92729522,0,0) q[0];
cx eval[1],q[0];
u(-1.8545904,0,0) q[0];
cx eval[1],q[0];
u3(1.8545904,0,0) q[0];
cx eval[2],q[0];
u(-3.7091809,0,0) q[0];
cx eval[2],q[0];
u3(2.5740044,-pi,-pi) q[0];
cx eval[3],q[0];
u(-7.4183617,0,0) q[0];
cx eval[3],q[0];
u3(1.1351764,0,0) q[0];
cx eval[4],q[0];
u(-14.836723,0,0) q[0];
cx eval[4],q[0];
u3(2.2703529,0,0) q[0];
cx eval[5],q[0];
u(-29.673447,0,0) q[0];
cx eval[5],q[0];
u3(1.7424796,-pi,-pi) q[0];
cx eval[6],q[0];
u(-59.346894,0,0) q[0];
cx eval[6],q[0];
u3(2.7982262,0,0) q[0];
cx eval[7],q[0];
u(-118.69379,0,0) q[0];
cx eval[7],q[0];
u3(0.68673293,-pi,-pi) q[0];
cx eval[8],q[0];
u(-237.38758,0,0) q[0];
cx eval[8],q[0];
u3(1.3734659,-pi,-pi) q[0];
cx eval[9],q[0];
u(-474.77515,0,0) q[0];
cx eval[9],q[0];
u3(2.7469317,-pi,-pi) q[0];
cx eval[10],q[0];
u(-949.5503,0,0) q[0];
cx eval[10],q[0];
u3(0.78932185,0,0) q[0];
cx eval[11],q[0];
u(-1899.1006,0,0) q[0];
cx eval[11],q[0];
u3(1.5786437,0,0) q[0];
cx eval[12],q[0];
u(-3798.2012,0,0) q[0];
cx eval[12],q[0];
u3(3.1258979,-pi,-pi) q[0];
cx eval[13],q[0];
u(-7596.4024,0,0) q[0];
cx eval[13],q[0];
u3(0.031389489,0,0) q[0];
cx eval[14],q[0];
u(-15192.805,0,0) q[0];
cx eval[14],q[0];
u3(0.062778978,0,0) q[0];
cx eval[15],q[0];
u(-30385.61,0,0) q[0];
cx eval[15],q[0];
u3(0.12555796,0,0) q[0];
cx eval[16],q[0];
u(-60771.219,0,0) q[0];
cx eval[16],q[0];
u(60771.219,0,0) q[0];
h eval[16];
cp(-pi/2) eval[15],eval[16];
cp(-pi/4) eval[14],eval[16];
cp(-pi/8) eval[13],eval[16];
cp(-pi/16) eval[12],eval[16];
cp(-pi/32) eval[11],eval[16];
cp(-pi/64) eval[10],eval[16];
h eval[15];
cp(-pi/2) eval[14],eval[15];
cp(-pi/4) eval[13],eval[15];
cp(-pi/8) eval[12],eval[15];
cp(-pi/16) eval[11],eval[15];
cp(-pi/32) eval[10],eval[15];
h eval[14];
cp(-pi/2) eval[13],eval[14];
cp(-pi/4) eval[12],eval[14];
cp(-pi/8) eval[11],eval[14];
cp(-pi/16) eval[10],eval[14];
h eval[13];
cp(-pi/2) eval[12],eval[13];
cp(-pi/4) eval[11],eval[13];
cp(-pi/8) eval[10],eval[13];
h eval[12];
cp(-pi/2) eval[11],eval[12];
cp(-pi/4) eval[10],eval[12];
h eval[11];
cp(-pi/2) eval[10],eval[11];
h eval[10];
cp(-pi/128) eval[9],eval[16];
cp(-pi/256) eval[8],eval[16];
cp(-pi/512) eval[7],eval[16];
cp(-pi/1024) eval[6],eval[16];
cp(-pi/2048) eval[5],eval[16];
cp(-pi/4096) eval[4],eval[16];
cp(-pi/8192) eval[3],eval[16];
cp(-pi/16384) eval[2],eval[16];
cp(-pi/32768) eval[1],eval[16];
cp(-pi/65536) eval[0],eval[16];
cp(-pi/64) eval[9],eval[15];
cp(-pi/128) eval[8],eval[15];
cp(-pi/256) eval[7],eval[15];
cp(-pi/512) eval[6],eval[15];
cp(-pi/1024) eval[5],eval[15];
cp(-pi/2048) eval[4],eval[15];
cp(-pi/4096) eval[3],eval[15];
cp(-pi/8192) eval[2],eval[15];
cp(-pi/16384) eval[1],eval[15];
cp(-pi/32768) eval[0],eval[15];
cp(-pi/32) eval[9],eval[14];
cp(-pi/64) eval[8],eval[14];
cp(-pi/128) eval[7],eval[14];
cp(-pi/256) eval[6],eval[14];
cp(-pi/512) eval[5],eval[14];
cp(-pi/1024) eval[4],eval[14];
cp(-pi/2048) eval[3],eval[14];
cp(-pi/4096) eval[2],eval[14];
cp(-pi/8192) eval[1],eval[14];
cp(-pi/16384) eval[0],eval[14];
cp(-pi/16) eval[9],eval[13];
cp(-pi/32) eval[8],eval[13];
cp(-pi/64) eval[7],eval[13];
cp(-pi/128) eval[6],eval[13];
cp(-pi/256) eval[5],eval[13];
cp(-pi/512) eval[4],eval[13];
cp(-pi/1024) eval[3],eval[13];
cp(-pi/2048) eval[2],eval[13];
cp(-pi/4096) eval[1],eval[13];
cp(-pi/8192) eval[0],eval[13];
cp(-pi/8) eval[9],eval[12];
cp(-pi/16) eval[8],eval[12];
cp(-pi/32) eval[7],eval[12];
cp(-pi/64) eval[6],eval[12];
cp(-pi/128) eval[5],eval[12];
cp(-pi/256) eval[4],eval[12];
cp(-pi/512) eval[3],eval[12];
cp(-pi/1024) eval[2],eval[12];
cp(-pi/2048) eval[1],eval[12];
cp(-pi/4096) eval[0],eval[12];
cp(-pi/4) eval[9],eval[11];
cp(-pi/8) eval[8],eval[11];
cp(-pi/16) eval[7],eval[11];
cp(-pi/32) eval[6],eval[11];
cp(-pi/64) eval[5],eval[11];
cp(-pi/128) eval[4],eval[11];
cp(-pi/256) eval[3],eval[11];
cp(-pi/512) eval[2],eval[11];
cp(-pi/1024) eval[1],eval[11];
cp(-pi/2048) eval[0],eval[11];
cp(-pi/2) eval[9],eval[10];
cp(-pi/4) eval[8],eval[10];
cp(-pi/8) eval[7],eval[10];
cp(-pi/16) eval[6],eval[10];
cp(-pi/32) eval[5],eval[10];
cp(-pi/64) eval[4],eval[10];
cp(-pi/128) eval[3],eval[10];
cp(-pi/256) eval[2],eval[10];
cp(-pi/512) eval[1],eval[10];
cp(-pi/1024) eval[0],eval[10];
h eval[9];
cp(-pi/2) eval[8],eval[9];
cp(-pi/4) eval[7],eval[9];
cp(-pi/8) eval[6],eval[9];
cp(-pi/16) eval[5],eval[9];
cp(-pi/32) eval[4],eval[9];
cp(-pi/64) eval[3],eval[9];
cp(-pi/128) eval[2],eval[9];
cp(-pi/256) eval[1],eval[9];
cp(-pi/512) eval[0],eval[9];
h eval[8];
cp(-pi/2) eval[7],eval[8];
cp(-pi/4) eval[6],eval[8];
cp(-pi/8) eval[5],eval[8];
cp(-pi/16) eval[4],eval[8];
cp(-pi/32) eval[3],eval[8];
cp(-pi/64) eval[2],eval[8];
cp(-pi/128) eval[1],eval[8];
cp(-pi/256) eval[0],eval[8];
h eval[7];
cp(-pi/2) eval[6],eval[7];
cp(-pi/4) eval[5],eval[7];
cp(-pi/8) eval[4],eval[7];
cp(-pi/16) eval[3],eval[7];
cp(-pi/32) eval[2],eval[7];
cp(-pi/64) eval[1],eval[7];
cp(-pi/128) eval[0],eval[7];
h eval[6];
cp(-pi/2) eval[5],eval[6];
cp(-pi/4) eval[4],eval[6];
cp(-pi/8) eval[3],eval[6];
cp(-pi/16) eval[2],eval[6];
cp(-pi/32) eval[1],eval[6];
cp(-pi/64) eval[0],eval[6];
h eval[5];
cp(-pi/2) eval[4],eval[5];
cp(-pi/4) eval[3],eval[5];
cp(-pi/8) eval[2],eval[5];
cp(-pi/16) eval[1],eval[5];
cp(-pi/32) eval[0],eval[5];
h eval[4];
cp(-pi/2) eval[3],eval[4];
cp(-pi/4) eval[2],eval[4];
cp(-pi/8) eval[1],eval[4];
cp(-pi/16) eval[0],eval[4];
h eval[3];
cp(-pi/2) eval[2],eval[3];
cp(-pi/4) eval[1],eval[3];
cp(-pi/8) eval[0],eval[3];
h eval[2];
cp(-pi/2) eval[1],eval[2];
cp(-pi/4) eval[0],eval[2];
h eval[1];
cp(-pi/2) eval[0],eval[1];
h eval[0];
barrier eval[0],eval[1],eval[2],eval[3],eval[4],eval[5],eval[6],eval[7],eval[8],eval[9],eval[10],eval[11],eval[12],eval[13],eval[14],eval[15],eval[16],q[0];
measure eval[0] -> meas[0];
measure eval[1] -> meas[1];
measure eval[2] -> meas[2];
measure eval[3] -> meas[3];
measure eval[4] -> meas[4];
measure eval[5] -> meas[5];
measure eval[6] -> meas[6];
measure eval[7] -> meas[7];
measure eval[8] -> meas[8];
measure eval[9] -> meas[9];
measure eval[10] -> meas[10];
measure eval[11] -> meas[11];
measure eval[12] -> meas[12];
measure eval[13] -> meas[13];
measure eval[14] -> meas[14];
measure eval[15] -> meas[15];
measure eval[16] -> meas[16];
measure q[0] -> meas[17];
