// Benchmark was created by MQT Bench on 2022-08-30
// For more information about MQT Bench, please visit https://www.cda.cit.tum.de/mqtbench/
// MQT Bench version: 0.1.0
// Qiskit version: {'qiskit-terra': '0.20.0', 'qiskit-aer': '0.10.4', 'qiskit-ignis': '0.7.0', 'qiskit-ibmq-provider': '0.19.0', 'qiskit-aqua': None, 'qiskit': '0.36.0', 'qiskit-nature': '0.3.1', 'qiskit-finance': '0.3.1', 'qiskit-optimization': '0.3.2', 'qiskit-machine-learning': '0.4.0'}

OPENQASM 2.0;
include "qelib1.inc";
qreg q[12];
creg meas[12];
ry(0.840847634150005) q[0];
ry(-2.42126090170097) q[1];
cx q[0],q[1];
ry(-1.6770420106553) q[2];
cx q[0],q[2];
cx q[1],q[2];
ry(1.67912483173346) q[3];
cx q[0],q[3];
cx q[1],q[3];
cx q[2],q[3];
ry(3.06069206791039) q[4];
cx q[0],q[4];
cx q[1],q[4];
cx q[2],q[4];
cx q[3],q[4];
ry(1.93522785619371) q[5];
cx q[0],q[5];
cx q[1],q[5];
cx q[2],q[5];
cx q[3],q[5];
cx q[4],q[5];
ry(2.15491669540479) q[6];
cx q[0],q[6];
cx q[1],q[6];
cx q[2],q[6];
cx q[3],q[6];
cx q[4],q[6];
cx q[5],q[6];
ry(1.85782906173718) q[7];
cx q[0],q[7];
cx q[1],q[7];
cx q[2],q[7];
cx q[3],q[7];
cx q[4],q[7];
cx q[5],q[7];
cx q[6],q[7];
ry(-0.271174068343224) q[8];
cx q[0],q[8];
cx q[1],q[8];
cx q[2],q[8];
cx q[3],q[8];
cx q[4],q[8];
cx q[5],q[8];
cx q[6],q[8];
cx q[7],q[8];
ry(1.49961207864086) q[9];
cx q[0],q[9];
cx q[1],q[9];
cx q[2],q[9];
cx q[3],q[9];
cx q[4],q[9];
cx q[5],q[9];
cx q[6],q[9];
cx q[7],q[9];
cx q[8],q[9];
ry(0.492947256773052) q[10];
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
ry(-0.309537563115402) q[11];
cx q[0],q[11];
ry(-1.43869601499927) q[0];
cx q[1],q[11];
ry(2.29086913378154) q[1];
cx q[0],q[1];
cx q[2],q[11];
ry(-2.71021638223584) q[2];
cx q[0],q[2];
cx q[1],q[2];
cx q[3],q[11];
ry(1.9901013023381) q[3];
cx q[0],q[3];
cx q[1],q[3];
cx q[2],q[3];
cx q[4],q[11];
ry(2.39914005472468) q[4];
cx q[0],q[4];
cx q[1],q[4];
cx q[2],q[4];
cx q[3],q[4];
cx q[5],q[11];
ry(-0.480560676903264) q[5];
cx q[0],q[5];
cx q[1],q[5];
cx q[2],q[5];
cx q[3],q[5];
cx q[4],q[5];
cx q[6],q[11];
ry(2.09374153044345) q[6];
cx q[0],q[6];
cx q[1],q[6];
cx q[2],q[6];
cx q[3],q[6];
cx q[4],q[6];
cx q[5],q[6];
cx q[7],q[11];
ry(-0.998921452334193) q[7];
cx q[0],q[7];
cx q[1],q[7];
cx q[2],q[7];
cx q[3],q[7];
cx q[4],q[7];
cx q[5],q[7];
cx q[6],q[7];
cx q[8],q[11];
ry(0.124353705645581) q[8];
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
ry(-1.92970957359207) q[10];
ry(-1.04792920912747) q[11];
ry(0.309173239420352) q[9];
cx q[0],q[9];
cx q[0],q[10];
cx q[0],q[11];
ry(-1.39785441925538) q[0];
cx q[1],q[9];
cx q[1],q[10];
cx q[1],q[11];
ry(-0.266665092400975) q[1];
cx q[0],q[1];
cx q[2],q[9];
cx q[2],q[10];
cx q[2],q[11];
ry(1.09858744116203) q[2];
cx q[0],q[2];
cx q[1],q[2];
cx q[3],q[9];
cx q[3],q[10];
cx q[3],q[11];
ry(1.15504561362644) q[3];
cx q[0],q[3];
cx q[1],q[3];
cx q[2],q[3];
cx q[4],q[9];
cx q[4],q[10];
cx q[4],q[11];
ry(0.148365595721051) q[4];
cx q[0],q[4];
cx q[1],q[4];
cx q[2],q[4];
cx q[3],q[4];
cx q[5],q[9];
cx q[5],q[10];
cx q[5],q[11];
ry(-0.223853747778386) q[5];
cx q[0],q[5];
cx q[1],q[5];
cx q[2],q[5];
cx q[3],q[5];
cx q[4],q[5];
cx q[6],q[9];
cx q[6],q[10];
cx q[6],q[11];
ry(0.0542198680554078) q[6];
cx q[0],q[6];
cx q[1],q[6];
cx q[2],q[6];
cx q[3],q[6];
cx q[4],q[6];
cx q[5],q[6];
cx q[7],q[9];
cx q[7],q[10];
cx q[7],q[11];
ry(-1.10204377020477) q[7];
cx q[0],q[7];
cx q[1],q[7];
cx q[2],q[7];
cx q[3],q[7];
cx q[4],q[7];
cx q[5],q[7];
cx q[6],q[7];
cx q[8],q[9];
cx q[8],q[10];
cx q[8],q[11];
ry(-2.0571104424665) q[8];
cx q[0],q[8];
cx q[1],q[8];
cx q[2],q[8];
cx q[3],q[8];
cx q[4],q[8];
cx q[5],q[8];
cx q[6],q[8];
cx q[7],q[8];
cx q[9],q[10];
cx q[9],q[11];
cx q[10],q[11];
ry(0.933475741965452) q[10];
ry(-2.73497061229015) q[11];
ry(-1.26082511631692) q[9];
cx q[0],q[9];
cx q[0],q[10];
cx q[0],q[11];
ry(0.840114867237831) q[0];
cx q[1],q[9];
cx q[1],q[10];
cx q[1],q[11];
ry(-1.3885744066224) q[1];
cx q[2],q[9];
cx q[2],q[10];
cx q[2],q[11];
ry(-1.97317199291756) q[2];
cx q[3],q[9];
cx q[3],q[10];
cx q[3],q[11];
ry(-0.0688126618779186) q[3];
cx q[4],q[9];
cx q[4],q[10];
cx q[4],q[11];
ry(-0.919323745828007) q[4];
cx q[5],q[9];
cx q[5],q[10];
cx q[5],q[11];
ry(-2.53713753590652) q[5];
cx q[6],q[9];
cx q[6],q[10];
cx q[6],q[11];
ry(1.31671062734335) q[6];
cx q[7],q[9];
cx q[7],q[10];
cx q[7],q[11];
ry(1.83230626959971) q[7];
cx q[8],q[9];
cx q[8],q[10];
cx q[8],q[11];
ry(-2.86317528573076) q[8];
cx q[9],q[10];
cx q[9],q[11];
cx q[10],q[11];
ry(-1.57166153222488) q[10];
ry(-0.457062513843978) q[11];
ry(0.791195967990987) q[9];
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
