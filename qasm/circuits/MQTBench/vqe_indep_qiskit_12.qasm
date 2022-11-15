// Benchmark was created by MQT Bench on 2022-08-31
// For more information about MQT Bench, please visit https://www.cda.cit.tum.de/mqtbench/
// MQT Bench version: 0.1.0
// Qiskit version: {'qiskit-terra': '0.20.0', 'qiskit-aer': '0.10.4', 'qiskit-ignis': '0.7.0', 'qiskit-ibmq-provider': '0.19.0', 'qiskit-aqua': None, 'qiskit': '0.36.0', 'qiskit-nature': '0.3.1', 'qiskit-finance': '0.3.1', 'qiskit-optimization': '0.3.2', 'qiskit-machine-learning': '0.4.0'}

OPENQASM 2.0;
include "qelib1.inc";
qreg q[12];
creg meas[12];
ry(-2.10479555646833) q[0];
ry(0.737305295126187) q[1];
cx q[0],q[1];
ry(1.3643031062671) q[2];
cx q[0],q[2];
cx q[1],q[2];
ry(0.00292473486177203) q[3];
cx q[0],q[3];
cx q[1],q[3];
cx q[2],q[3];
ry(-3.04445569980818) q[4];
cx q[0],q[4];
cx q[1],q[4];
cx q[2],q[4];
cx q[3],q[4];
ry(-0.674040326480033) q[5];
cx q[0],q[5];
cx q[1],q[5];
cx q[2],q[5];
cx q[3],q[5];
cx q[4],q[5];
ry(2.15955635782027) q[6];
cx q[0],q[6];
cx q[1],q[6];
cx q[2],q[6];
cx q[3],q[6];
cx q[4],q[6];
cx q[5],q[6];
ry(2.01191590496881) q[7];
cx q[0],q[7];
cx q[1],q[7];
cx q[2],q[7];
cx q[3],q[7];
cx q[4],q[7];
cx q[5],q[7];
cx q[6],q[7];
ry(-0.417411631722103) q[8];
cx q[0],q[8];
cx q[1],q[8];
cx q[2],q[8];
cx q[3],q[8];
cx q[4],q[8];
cx q[5],q[8];
cx q[6],q[8];
cx q[7],q[8];
ry(2.79088287480018) q[9];
cx q[0],q[9];
cx q[1],q[9];
cx q[2],q[9];
cx q[3],q[9];
cx q[4],q[9];
cx q[5],q[9];
cx q[6],q[9];
cx q[7],q[9];
cx q[8],q[9];
ry(0.760974652496823) q[10];
cx q[0],q[10];
cx q[1],q[10];
cx q[2],q[10];
cx q[3],q[10];
cx q[4],q[10];
cx q[5],q[10];
cx q[6],q[10];
cx q[7],q[10];
cx q[8],q[10];
cx q[9],q[10];
ry(-1.83938344461419) q[11];
cx q[0],q[11];
ry(-1.28064542224497) q[0];
cx q[1],q[11];
ry(1.44971983403854) q[1];
cx q[0],q[1];
cx q[2],q[11];
ry(1.7412986836451) q[2];
cx q[0],q[2];
cx q[1],q[2];
cx q[3],q[11];
ry(3.00825976146346) q[3];
cx q[0],q[3];
cx q[1],q[3];
cx q[2],q[3];
cx q[4],q[11];
ry(0.680357709836265) q[4];
cx q[0],q[4];
cx q[1],q[4];
cx q[2],q[4];
cx q[3],q[4];
cx q[5],q[11];
ry(1.41675539520798) q[5];
cx q[0],q[5];
cx q[1],q[5];
cx q[2],q[5];
cx q[3],q[5];
cx q[4],q[5];
cx q[6],q[11];
ry(1.97417052758655) q[6];
cx q[0],q[6];
cx q[1],q[6];
cx q[2],q[6];
cx q[3],q[6];
cx q[4],q[6];
cx q[5],q[6];
cx q[7],q[11];
ry(1.30439199649263) q[7];
cx q[0],q[7];
cx q[1],q[7];
cx q[2],q[7];
cx q[3],q[7];
cx q[4],q[7];
cx q[5],q[7];
cx q[6],q[7];
cx q[8],q[11];
ry(2.6833374139903) q[8];
cx q[0],q[8];
cx q[1],q[8];
cx q[2],q[8];
cx q[3],q[8];
cx q[4],q[8];
cx q[5],q[8];
cx q[6],q[8];
cx q[7],q[8];
cx q[9],q[11];
cx q[10],q[11];
ry(-1.1105413610031) q[10];
ry(0.425256119698915) q[11];
ry(-0.995171256068651) q[9];
cx q[0],q[9];
cx q[0],q[10];
cx q[0],q[11];
ry(0.246256531939752) q[0];
cx q[1],q[9];
cx q[1],q[10];
cx q[1],q[11];
ry(0.47427854040424) q[1];
cx q[2],q[9];
cx q[2],q[10];
cx q[2],q[11];
ry(0.762386626403669) q[2];
cx q[3],q[9];
cx q[3],q[10];
cx q[3],q[11];
ry(-0.917870565252279) q[3];
cx q[4],q[9];
cx q[4],q[10];
cx q[4],q[11];
ry(0.953183009132159) q[4];
cx q[5],q[9];
cx q[5],q[10];
cx q[5],q[11];
ry(1.31523159311031) q[5];
cx q[6],q[9];
cx q[6],q[10];
cx q[6],q[11];
ry(-1.23521136494091) q[6];
cx q[7],q[9];
cx q[7],q[10];
cx q[7],q[11];
ry(1.84189010407481) q[7];
cx q[8],q[9];
cx q[8],q[10];
cx q[8],q[11];
ry(-2.76907567177189) q[8];
cx q[9],q[10];
cx q[9],q[11];
cx q[10],q[11];
ry(-0.771889977454922) q[10];
ry(0.235862963684323) q[11];
ry(0.536823569729235) q[9];
barrier q[0],q[1],q[2],q[3],q[4],q[5],q[6],q[7],q[8],q[9],q[10],q[11];
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
