// Benchmark was created by MQT Bench on 2022-08-30
// For more information about MQT Bench, please visit https://www.cda.cit.tum.de/mqtbench/
// MQT Bench version: 0.1.0
// Qiskit version: {'qiskit-terra': '0.20.0', 'qiskit-aer': '0.10.4', 'qiskit-ignis': '0.7.0', 'qiskit-ibmq-provider': '0.19.0', 'qiskit-aqua': None, 'qiskit': '0.36.0', 'qiskit-nature': '0.3.1', 'qiskit-finance': '0.3.1', 'qiskit-optimization': '0.3.2', 'qiskit-machine-learning': '0.4.0'}

OPENQASM 2.0;
include "qelib1.inc";
qreg q[29];
creg meas[29];
ry(0.551759499796868) q[0];
ry(0.485463068341734) q[1];
cx q[0],q[1];
ry(0.596446525585601) q[2];
cx q[0],q[2];
cx q[1],q[2];
ry(0.61488593348132) q[3];
cx q[0],q[3];
cx q[1],q[3];
cx q[2],q[3];
ry(0.998784249158013) q[4];
cx q[0],q[4];
cx q[1],q[4];
cx q[2],q[4];
cx q[3],q[4];
ry(0.522764193774673) q[5];
cx q[0],q[5];
cx q[1],q[5];
cx q[2],q[5];
cx q[3],q[5];
cx q[4],q[5];
ry(0.0715815525553942) q[6];
cx q[0],q[6];
cx q[1],q[6];
cx q[2],q[6];
cx q[3],q[6];
cx q[4],q[6];
cx q[5],q[6];
ry(0.914010443636566) q[7];
cx q[0],q[7];
cx q[1],q[7];
cx q[2],q[7];
cx q[3],q[7];
cx q[4],q[7];
cx q[5],q[7];
cx q[6],q[7];
ry(0.462055505128672) q[8];
cx q[0],q[8];
cx q[1],q[8];
cx q[2],q[8];
cx q[3],q[8];
cx q[4],q[8];
cx q[5],q[8];
cx q[6],q[8];
cx q[7],q[8];
ry(0.417453178844134) q[9];
cx q[0],q[9];
cx q[1],q[9];
cx q[2],q[9];
cx q[3],q[9];
cx q[4],q[9];
cx q[5],q[9];
cx q[6],q[9];
cx q[7],q[9];
cx q[8],q[9];
ry(0.378046819783735) q[10];
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
ry(0.645226930124816) q[11];
cx q[0],q[11];
cx q[1],q[11];
cx q[2],q[11];
cx q[3],q[11];
cx q[4],q[11];
cx q[5],q[11];
cx q[6],q[11];
cx q[7],q[11];
cx q[8],q[11];
cx q[9],q[11];
cx q[10],q[11];
ry(0.842514737969432) q[12];
cx q[0],q[12];
cx q[1],q[12];
cx q[2],q[12];
cx q[3],q[12];
cx q[4],q[12];
cx q[5],q[12];
cx q[6],q[12];
cx q[7],q[12];
cx q[8],q[12];
cx q[9],q[12];
cx q[10],q[12];
cx q[11],q[12];
ry(0.594406520681015) q[13];
cx q[0],q[13];
cx q[1],q[13];
cx q[2],q[13];
cx q[3],q[13];
cx q[4],q[13];
cx q[5],q[13];
cx q[6],q[13];
cx q[7],q[13];
cx q[8],q[13];
cx q[9],q[13];
cx q[10],q[13];
cx q[11],q[13];
cx q[12],q[13];
ry(0.160691002725148) q[14];
cx q[0],q[14];
cx q[1],q[14];
cx q[2],q[14];
cx q[3],q[14];
cx q[4],q[14];
cx q[5],q[14];
cx q[6],q[14];
cx q[7],q[14];
cx q[8],q[14];
cx q[9],q[14];
cx q[10],q[14];
cx q[11],q[14];
cx q[12],q[14];
cx q[13],q[14];
ry(0.574619805806729) q[15];
cx q[0],q[15];
cx q[1],q[15];
cx q[2],q[15];
cx q[3],q[15];
cx q[4],q[15];
cx q[5],q[15];
cx q[6],q[15];
cx q[7],q[15];
cx q[8],q[15];
cx q[9],q[15];
cx q[10],q[15];
cx q[11],q[15];
cx q[12],q[15];
cx q[13],q[15];
cx q[14],q[15];
ry(0.789228292425696) q[16];
cx q[0],q[16];
cx q[1],q[16];
cx q[2],q[16];
cx q[3],q[16];
cx q[4],q[16];
cx q[5],q[16];
cx q[6],q[16];
cx q[7],q[16];
cx q[8],q[16];
cx q[9],q[16];
cx q[10],q[16];
cx q[11],q[16];
cx q[12],q[16];
cx q[13],q[16];
cx q[14],q[16];
cx q[15],q[16];
ry(0.214405679444135) q[17];
cx q[0],q[17];
cx q[1],q[17];
cx q[2],q[17];
cx q[3],q[17];
cx q[4],q[17];
cx q[5],q[17];
cx q[6],q[17];
cx q[7],q[17];
cx q[8],q[17];
cx q[9],q[17];
cx q[10],q[17];
cx q[11],q[17];
cx q[12],q[17];
cx q[13],q[17];
cx q[14],q[17];
cx q[15],q[17];
cx q[16],q[17];
ry(0.505515745090324) q[18];
cx q[0],q[18];
cx q[1],q[18];
cx q[2],q[18];
cx q[3],q[18];
cx q[4],q[18];
cx q[5],q[18];
cx q[6],q[18];
cx q[7],q[18];
cx q[8],q[18];
cx q[9],q[18];
cx q[10],q[18];
cx q[11],q[18];
cx q[12],q[18];
cx q[13],q[18];
cx q[14],q[18];
cx q[15],q[18];
cx q[16],q[18];
cx q[17],q[18];
ry(0.256666695792629) q[19];
cx q[0],q[19];
cx q[1],q[19];
cx q[2],q[19];
cx q[3],q[19];
cx q[4],q[19];
cx q[5],q[19];
cx q[6],q[19];
cx q[7],q[19];
cx q[8],q[19];
cx q[9],q[19];
cx q[10],q[19];
cx q[11],q[19];
cx q[12],q[19];
cx q[13],q[19];
cx q[14],q[19];
cx q[15],q[19];
cx q[16],q[19];
cx q[17],q[19];
cx q[18],q[19];
ry(0.741437592572185) q[20];
cx q[0],q[20];
cx q[1],q[20];
cx q[2],q[20];
cx q[3],q[20];
cx q[4],q[20];
cx q[5],q[20];
cx q[6],q[20];
cx q[7],q[20];
cx q[8],q[20];
cx q[9],q[20];
cx q[10],q[20];
cx q[11],q[20];
cx q[12],q[20];
cx q[13],q[20];
cx q[14],q[20];
cx q[15],q[20];
cx q[16],q[20];
cx q[17],q[20];
cx q[18],q[20];
cx q[19],q[20];
ry(0.261571308894859) q[21];
cx q[0],q[21];
cx q[1],q[21];
cx q[2],q[21];
cx q[3],q[21];
cx q[4],q[21];
cx q[5],q[21];
cx q[6],q[21];
cx q[7],q[21];
cx q[8],q[21];
cx q[9],q[21];
cx q[10],q[21];
cx q[11],q[21];
cx q[12],q[21];
cx q[13],q[21];
cx q[14],q[21];
cx q[15],q[21];
cx q[16],q[21];
cx q[17],q[21];
cx q[18],q[21];
cx q[19],q[21];
cx q[20],q[21];
ry(0.272944167779813) q[22];
cx q[0],q[22];
cx q[1],q[22];
cx q[2],q[22];
cx q[3],q[22];
cx q[4],q[22];
cx q[5],q[22];
cx q[6],q[22];
cx q[7],q[22];
cx q[8],q[22];
cx q[9],q[22];
cx q[10],q[22];
cx q[11],q[22];
cx q[12],q[22];
cx q[13],q[22];
cx q[14],q[22];
cx q[15],q[22];
cx q[16],q[22];
cx q[17],q[22];
cx q[18],q[22];
cx q[19],q[22];
cx q[20],q[22];
cx q[21],q[22];
ry(0.243780352962737) q[23];
cx q[0],q[23];
cx q[1],q[23];
cx q[2],q[23];
cx q[3],q[23];
cx q[4],q[23];
cx q[5],q[23];
cx q[6],q[23];
cx q[7],q[23];
cx q[8],q[23];
cx q[9],q[23];
cx q[10],q[23];
cx q[11],q[23];
cx q[12],q[23];
cx q[13],q[23];
cx q[14],q[23];
cx q[15],q[23];
cx q[16],q[23];
cx q[17],q[23];
cx q[18],q[23];
cx q[19],q[23];
cx q[20],q[23];
cx q[21],q[23];
cx q[22],q[23];
ry(0.79603415065419) q[24];
cx q[0],q[24];
cx q[1],q[24];
cx q[2],q[24];
cx q[3],q[24];
cx q[4],q[24];
cx q[5],q[24];
cx q[6],q[24];
cx q[7],q[24];
cx q[8],q[24];
cx q[9],q[24];
cx q[10],q[24];
cx q[11],q[24];
cx q[12],q[24];
cx q[13],q[24];
cx q[14],q[24];
cx q[15],q[24];
cx q[16],q[24];
cx q[17],q[24];
cx q[18],q[24];
cx q[19],q[24];
cx q[20],q[24];
cx q[21],q[24];
cx q[22],q[24];
cx q[23],q[24];
ry(0.43268703564259) q[25];
cx q[0],q[25];
cx q[1],q[25];
cx q[2],q[25];
cx q[3],q[25];
cx q[4],q[25];
cx q[5],q[25];
cx q[6],q[25];
cx q[7],q[25];
cx q[8],q[25];
cx q[9],q[25];
cx q[10],q[25];
cx q[11],q[25];
cx q[12],q[25];
cx q[13],q[25];
cx q[14],q[25];
cx q[15],q[25];
cx q[16],q[25];
cx q[17],q[25];
cx q[18],q[25];
cx q[19],q[25];
cx q[20],q[25];
cx q[21],q[25];
cx q[22],q[25];
cx q[23],q[25];
cx q[24],q[25];
ry(0.809889287385633) q[26];
cx q[0],q[26];
cx q[1],q[26];
cx q[2],q[26];
cx q[3],q[26];
cx q[4],q[26];
cx q[5],q[26];
cx q[6],q[26];
cx q[7],q[26];
cx q[8],q[26];
cx q[9],q[26];
cx q[10],q[26];
cx q[11],q[26];
cx q[12],q[26];
cx q[13],q[26];
cx q[14],q[26];
cx q[15],q[26];
cx q[16],q[26];
cx q[17],q[26];
cx q[18],q[26];
cx q[19],q[26];
cx q[20],q[26];
cx q[21],q[26];
cx q[22],q[26];
cx q[23],q[26];
cx q[24],q[26];
cx q[25],q[26];
ry(0.662056607531747) q[27];
cx q[0],q[27];
cx q[1],q[27];
cx q[2],q[27];
cx q[3],q[27];
cx q[4],q[27];
cx q[5],q[27];
cx q[6],q[27];
cx q[7],q[27];
cx q[8],q[27];
cx q[9],q[27];
cx q[10],q[27];
cx q[11],q[27];
cx q[12],q[27];
cx q[13],q[27];
cx q[14],q[27];
cx q[15],q[27];
cx q[16],q[27];
cx q[17],q[27];
cx q[18],q[27];
cx q[19],q[27];
cx q[20],q[27];
cx q[21],q[27];
cx q[22],q[27];
cx q[23],q[27];
cx q[24],q[27];
cx q[25],q[27];
cx q[26],q[27];
ry(0.834030554854759) q[28];
cx q[0],q[28];
ry(0.271975720198877) q[0];
cx q[1],q[28];
ry(0.868072546626869) q[1];
cx q[0],q[1];
cx q[2],q[28];
ry(0.997405659120783) q[2];
cx q[0],q[2];
cx q[1],q[2];
cx q[3],q[28];
ry(0.311164998574163) q[3];
cx q[0],q[3];
cx q[1],q[3];
cx q[2],q[3];
cx q[4],q[28];
ry(0.53049107700319) q[4];
cx q[0],q[4];
cx q[1],q[4];
cx q[2],q[4];
cx q[3],q[4];
cx q[5],q[28];
ry(0.532364563307222) q[5];
cx q[0],q[5];
cx q[1],q[5];
cx q[2],q[5];
cx q[3],q[5];
cx q[4],q[5];
cx q[6],q[28];
ry(0.721370769863643) q[6];
cx q[0],q[6];
cx q[1],q[6];
cx q[2],q[6];
cx q[3],q[6];
cx q[4],q[6];
cx q[5],q[6];
cx q[7],q[28];
ry(0.499667231626405) q[7];
cx q[0],q[7];
cx q[1],q[7];
cx q[2],q[7];
cx q[3],q[7];
cx q[4],q[7];
cx q[5],q[7];
cx q[6],q[7];
cx q[8],q[28];
ry(0.981088275215557) q[8];
cx q[0],q[8];
cx q[1],q[8];
cx q[2],q[8];
cx q[3],q[8];
cx q[4],q[8];
cx q[5],q[8];
cx q[6],q[8];
cx q[7],q[8];
cx q[9],q[28];
cx q[10],q[28];
ry(0.66248024939228) q[10];
cx q[11],q[28];
ry(0.0978790706283946) q[11];
cx q[12],q[28];
ry(0.172136244925011) q[12];
cx q[13],q[28];
ry(0.423296364503177) q[13];
cx q[14],q[28];
ry(0.289933277770818) q[14];
cx q[15],q[28];
ry(0.330601213535152) q[15];
cx q[16],q[28];
ry(0.639412788343367) q[16];
cx q[17],q[28];
ry(0.154634985159339) q[17];
cx q[18],q[28];
ry(0.539819009326495) q[18];
cx q[19],q[28];
ry(0.513321999152515) q[19];
cx q[20],q[28];
ry(0.237004221346239) q[20];
cx q[21],q[28];
ry(0.528613698793089) q[21];
cx q[22],q[28];
ry(0.455439895141899) q[22];
cx q[23],q[28];
ry(0.997969491091718) q[23];
cx q[24],q[28];
ry(0.106177620982758) q[24];
cx q[25],q[28];
ry(0.0100484224729016) q[25];
cx q[26],q[28];
ry(0.0385993050838865) q[26];
cx q[27],q[28];
ry(0.623324741831419) q[27];
ry(0.899953048585635) q[28];
ry(0.759603216506237) q[9];
cx q[0],q[9];
cx q[0],q[10];
cx q[0],q[11];
cx q[0],q[12];
cx q[0],q[13];
cx q[0],q[14];
cx q[0],q[15];
cx q[0],q[16];
cx q[0],q[17];
cx q[0],q[18];
cx q[0],q[19];
cx q[0],q[20];
cx q[0],q[21];
cx q[0],q[22];
cx q[0],q[23];
cx q[0],q[24];
cx q[0],q[25];
cx q[0],q[26];
cx q[0],q[27];
cx q[0],q[28];
ry(0.567771353641342) q[0];
cx q[1],q[9];
cx q[1],q[10];
cx q[1],q[11];
cx q[1],q[12];
cx q[1],q[13];
cx q[1],q[14];
cx q[1],q[15];
cx q[1],q[16];
cx q[1],q[17];
cx q[1],q[18];
cx q[1],q[19];
cx q[1],q[20];
cx q[1],q[21];
cx q[1],q[22];
cx q[1],q[23];
cx q[1],q[24];
cx q[1],q[25];
cx q[1],q[26];
cx q[1],q[27];
cx q[1],q[28];
ry(0.499119124107831) q[1];
cx q[0],q[1];
cx q[2],q[9];
cx q[2],q[10];
cx q[2],q[11];
cx q[2],q[12];
cx q[2],q[13];
cx q[2],q[14];
cx q[2],q[15];
cx q[2],q[16];
cx q[2],q[17];
cx q[2],q[18];
cx q[2],q[19];
cx q[2],q[20];
cx q[2],q[21];
cx q[2],q[22];
cx q[2],q[23];
cx q[2],q[24];
cx q[2],q[25];
cx q[2],q[26];
cx q[2],q[27];
cx q[2],q[28];
ry(0.575988290122925) q[2];
cx q[0],q[2];
cx q[1],q[2];
cx q[3],q[9];
cx q[3],q[10];
cx q[3],q[11];
cx q[3],q[12];
cx q[3],q[13];
cx q[3],q[14];
cx q[3],q[15];
cx q[3],q[16];
cx q[3],q[17];
cx q[3],q[18];
cx q[3],q[19];
cx q[3],q[20];
cx q[3],q[21];
cx q[3],q[22];
cx q[3],q[23];
cx q[3],q[24];
cx q[3],q[25];
cx q[3],q[26];
cx q[3],q[27];
cx q[3],q[28];
ry(0.768025223486595) q[3];
cx q[0],q[3];
cx q[1],q[3];
cx q[2],q[3];
cx q[4],q[9];
cx q[4],q[10];
cx q[4],q[11];
cx q[4],q[12];
cx q[4],q[13];
cx q[4],q[14];
cx q[4],q[15];
cx q[4],q[16];
cx q[4],q[17];
cx q[4],q[18];
cx q[4],q[19];
cx q[4],q[20];
cx q[4],q[21];
cx q[4],q[22];
cx q[4],q[23];
cx q[4],q[24];
cx q[4],q[25];
cx q[4],q[26];
cx q[4],q[27];
cx q[4],q[28];
ry(0.0870429383759818) q[4];
cx q[0],q[4];
cx q[1],q[4];
cx q[2],q[4];
cx q[3],q[4];
cx q[5],q[9];
cx q[5],q[10];
cx q[5],q[11];
cx q[5],q[12];
cx q[5],q[13];
cx q[5],q[14];
cx q[5],q[15];
cx q[5],q[16];
cx q[5],q[17];
cx q[5],q[18];
cx q[5],q[19];
cx q[5],q[20];
cx q[5],q[21];
cx q[5],q[22];
cx q[5],q[23];
cx q[5],q[24];
cx q[5],q[25];
cx q[5],q[26];
cx q[5],q[27];
cx q[5],q[28];
ry(0.622553407310353) q[5];
cx q[0],q[5];
cx q[1],q[5];
cx q[2],q[5];
cx q[3],q[5];
cx q[4],q[5];
cx q[6],q[9];
cx q[6],q[10];
cx q[6],q[11];
cx q[6],q[12];
cx q[6],q[13];
cx q[6],q[14];
cx q[6],q[15];
cx q[6],q[16];
cx q[6],q[17];
cx q[6],q[18];
cx q[6],q[19];
cx q[6],q[20];
cx q[6],q[21];
cx q[6],q[22];
cx q[6],q[23];
cx q[6],q[24];
cx q[6],q[25];
cx q[6],q[26];
cx q[6],q[27];
cx q[6],q[28];
ry(0.373480412199386) q[6];
cx q[0],q[6];
cx q[1],q[6];
cx q[2],q[6];
cx q[3],q[6];
cx q[4],q[6];
cx q[5],q[6];
cx q[7],q[9];
cx q[7],q[10];
cx q[7],q[11];
cx q[7],q[12];
cx q[7],q[13];
cx q[7],q[14];
cx q[7],q[15];
cx q[7],q[16];
cx q[7],q[17];
cx q[7],q[18];
cx q[7],q[19];
cx q[7],q[20];
cx q[7],q[21];
cx q[7],q[22];
cx q[7],q[23];
cx q[7],q[24];
cx q[7],q[25];
cx q[7],q[26];
cx q[7],q[27];
cx q[7],q[28];
ry(0.0433780269831369) q[7];
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
cx q[8],q[12];
cx q[8],q[13];
cx q[8],q[14];
cx q[8],q[15];
cx q[8],q[16];
cx q[8],q[17];
cx q[8],q[18];
cx q[8],q[19];
cx q[8],q[20];
cx q[8],q[21];
cx q[8],q[22];
cx q[8],q[23];
cx q[8],q[24];
cx q[8],q[25];
cx q[8],q[26];
cx q[8],q[27];
cx q[8],q[28];
ry(0.258111452891401) q[8];
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
cx q[9],q[12];
cx q[10],q[12];
cx q[11],q[12];
cx q[9],q[13];
cx q[10],q[13];
cx q[11],q[13];
cx q[12],q[13];
cx q[9],q[14];
cx q[10],q[14];
cx q[11],q[14];
cx q[12],q[14];
cx q[13],q[14];
cx q[9],q[15];
cx q[10],q[15];
cx q[11],q[15];
cx q[12],q[15];
cx q[13],q[15];
cx q[14],q[15];
cx q[9],q[16];
cx q[10],q[16];
cx q[11],q[16];
cx q[12],q[16];
cx q[13],q[16];
cx q[14],q[16];
cx q[15],q[16];
cx q[9],q[17];
cx q[10],q[17];
cx q[11],q[17];
cx q[12],q[17];
cx q[13],q[17];
cx q[14],q[17];
cx q[15],q[17];
cx q[16],q[17];
cx q[9],q[18];
cx q[10],q[18];
cx q[11],q[18];
cx q[12],q[18];
cx q[13],q[18];
cx q[14],q[18];
cx q[15],q[18];
cx q[16],q[18];
cx q[17],q[18];
cx q[9],q[19];
cx q[10],q[19];
cx q[11],q[19];
cx q[12],q[19];
cx q[13],q[19];
cx q[14],q[19];
cx q[15],q[19];
cx q[16],q[19];
cx q[17],q[19];
cx q[18],q[19];
cx q[9],q[20];
cx q[10],q[20];
cx q[11],q[20];
cx q[12],q[20];
cx q[13],q[20];
cx q[14],q[20];
cx q[15],q[20];
cx q[16],q[20];
cx q[17],q[20];
cx q[18],q[20];
cx q[19],q[20];
cx q[9],q[21];
cx q[10],q[21];
cx q[11],q[21];
cx q[12],q[21];
cx q[13],q[21];
cx q[14],q[21];
cx q[15],q[21];
cx q[16],q[21];
cx q[17],q[21];
cx q[18],q[21];
cx q[19],q[21];
cx q[20],q[21];
cx q[9],q[22];
cx q[10],q[22];
cx q[11],q[22];
cx q[12],q[22];
cx q[13],q[22];
cx q[14],q[22];
cx q[15],q[22];
cx q[16],q[22];
cx q[17],q[22];
cx q[18],q[22];
cx q[19],q[22];
cx q[20],q[22];
cx q[21],q[22];
cx q[9],q[23];
cx q[10],q[23];
cx q[11],q[23];
cx q[12],q[23];
cx q[13],q[23];
cx q[14],q[23];
cx q[15],q[23];
cx q[16],q[23];
cx q[17],q[23];
cx q[18],q[23];
cx q[19],q[23];
cx q[20],q[23];
cx q[21],q[23];
cx q[22],q[23];
cx q[9],q[24];
cx q[10],q[24];
cx q[11],q[24];
cx q[12],q[24];
cx q[13],q[24];
cx q[14],q[24];
cx q[15],q[24];
cx q[16],q[24];
cx q[17],q[24];
cx q[18],q[24];
cx q[19],q[24];
cx q[20],q[24];
cx q[21],q[24];
cx q[22],q[24];
cx q[23],q[24];
cx q[9],q[25];
cx q[10],q[25];
cx q[11],q[25];
cx q[12],q[25];
cx q[13],q[25];
cx q[14],q[25];
cx q[15],q[25];
cx q[16],q[25];
cx q[17],q[25];
cx q[18],q[25];
cx q[19],q[25];
cx q[20],q[25];
cx q[21],q[25];
cx q[22],q[25];
cx q[23],q[25];
cx q[24],q[25];
cx q[9],q[26];
cx q[10],q[26];
cx q[11],q[26];
cx q[12],q[26];
cx q[13],q[26];
cx q[14],q[26];
cx q[15],q[26];
cx q[16],q[26];
cx q[17],q[26];
cx q[18],q[26];
cx q[19],q[26];
cx q[20],q[26];
cx q[21],q[26];
cx q[22],q[26];
cx q[23],q[26];
cx q[24],q[26];
cx q[25],q[26];
cx q[9],q[27];
cx q[10],q[27];
cx q[11],q[27];
cx q[12],q[27];
cx q[13],q[27];
cx q[14],q[27];
cx q[15],q[27];
cx q[16],q[27];
cx q[17],q[27];
cx q[18],q[27];
cx q[19],q[27];
cx q[20],q[27];
cx q[21],q[27];
cx q[22],q[27];
cx q[23],q[27];
cx q[24],q[27];
cx q[25],q[27];
cx q[26],q[27];
cx q[9],q[28];
cx q[10],q[28];
ry(0.898845458917399) q[10];
cx q[11],q[28];
ry(0.46799624355105) q[11];
cx q[12],q[28];
ry(0.505038758492549) q[12];
cx q[13],q[28];
ry(0.825267861474364) q[13];
cx q[14],q[28];
ry(0.855514750183821) q[14];
cx q[15],q[28];
ry(0.328718955391868) q[15];
cx q[16],q[28];
ry(0.585969175295513) q[16];
cx q[17],q[28];
ry(0.925064248986989) q[17];
cx q[18],q[28];
ry(0.273778333890455) q[18];
cx q[19],q[28];
ry(0.828926664822097) q[19];
cx q[20],q[28];
ry(0.175095904124103) q[20];
cx q[21],q[28];
ry(0.207554575557911) q[21];
cx q[22],q[28];
ry(0.454429713364178) q[22];
cx q[23],q[28];
ry(0.726094292679521) q[23];
cx q[24],q[28];
ry(0.234146429304142) q[24];
cx q[25],q[28];
ry(0.244764378829462) q[25];
cx q[26],q[28];
ry(0.320463398120126) q[26];
cx q[27],q[28];
ry(0.721816455228549) q[27];
ry(0.669149906687289) q[28];
ry(0.963073235917731) q[9];
cx q[0],q[9];
cx q[0],q[10];
cx q[0],q[11];
cx q[0],q[12];
cx q[0],q[13];
cx q[0],q[14];
cx q[0],q[15];
cx q[0],q[16];
cx q[0],q[17];
cx q[0],q[18];
cx q[0],q[19];
cx q[0],q[20];
cx q[0],q[21];
cx q[0],q[22];
cx q[0],q[23];
cx q[0],q[24];
cx q[0],q[25];
cx q[0],q[26];
cx q[0],q[27];
cx q[0],q[28];
ry(0.34938922301152) q[0];
cx q[1],q[9];
cx q[1],q[10];
cx q[1],q[11];
cx q[1],q[12];
cx q[1],q[13];
cx q[1],q[14];
cx q[1],q[15];
cx q[1],q[16];
cx q[1],q[17];
cx q[1],q[18];
cx q[1],q[19];
cx q[1],q[20];
cx q[1],q[21];
cx q[1],q[22];
cx q[1],q[23];
cx q[1],q[24];
cx q[1],q[25];
cx q[1],q[26];
cx q[1],q[27];
cx q[1],q[28];
ry(0.0116303614549635) q[1];
cx q[2],q[9];
cx q[2],q[10];
cx q[2],q[11];
cx q[2],q[12];
cx q[2],q[13];
cx q[2],q[14];
cx q[2],q[15];
cx q[2],q[16];
cx q[2],q[17];
cx q[2],q[18];
cx q[2],q[19];
cx q[2],q[20];
cx q[2],q[21];
cx q[2],q[22];
cx q[2],q[23];
cx q[2],q[24];
cx q[2],q[25];
cx q[2],q[26];
cx q[2],q[27];
cx q[2],q[28];
ry(0.634945093922937) q[2];
cx q[3],q[9];
cx q[3],q[10];
cx q[3],q[11];
cx q[3],q[12];
cx q[3],q[13];
cx q[3],q[14];
cx q[3],q[15];
cx q[3],q[16];
cx q[3],q[17];
cx q[3],q[18];
cx q[3],q[19];
cx q[3],q[20];
cx q[3],q[21];
cx q[3],q[22];
cx q[3],q[23];
cx q[3],q[24];
cx q[3],q[25];
cx q[3],q[26];
cx q[3],q[27];
cx q[3],q[28];
ry(0.210232268970289) q[3];
cx q[4],q[9];
cx q[4],q[10];
cx q[4],q[11];
cx q[4],q[12];
cx q[4],q[13];
cx q[4],q[14];
cx q[4],q[15];
cx q[4],q[16];
cx q[4],q[17];
cx q[4],q[18];
cx q[4],q[19];
cx q[4],q[20];
cx q[4],q[21];
cx q[4],q[22];
cx q[4],q[23];
cx q[4],q[24];
cx q[4],q[25];
cx q[4],q[26];
cx q[4],q[27];
cx q[4],q[28];
ry(0.440515588100445) q[4];
cx q[5],q[9];
cx q[5],q[10];
cx q[5],q[11];
cx q[5],q[12];
cx q[5],q[13];
cx q[5],q[14];
cx q[5],q[15];
cx q[5],q[16];
cx q[5],q[17];
cx q[5],q[18];
cx q[5],q[19];
cx q[5],q[20];
cx q[5],q[21];
cx q[5],q[22];
cx q[5],q[23];
cx q[5],q[24];
cx q[5],q[25];
cx q[5],q[26];
cx q[5],q[27];
cx q[5],q[28];
ry(0.881157377266804) q[5];
cx q[6],q[9];
cx q[6],q[10];
cx q[6],q[11];
cx q[6],q[12];
cx q[6],q[13];
cx q[6],q[14];
cx q[6],q[15];
cx q[6],q[16];
cx q[6],q[17];
cx q[6],q[18];
cx q[6],q[19];
cx q[6],q[20];
cx q[6],q[21];
cx q[6],q[22];
cx q[6],q[23];
cx q[6],q[24];
cx q[6],q[25];
cx q[6],q[26];
cx q[6],q[27];
cx q[6],q[28];
ry(0.942925683997446) q[6];
cx q[7],q[9];
cx q[7],q[10];
cx q[7],q[11];
cx q[7],q[12];
cx q[7],q[13];
cx q[7],q[14];
cx q[7],q[15];
cx q[7],q[16];
cx q[7],q[17];
cx q[7],q[18];
cx q[7],q[19];
cx q[7],q[20];
cx q[7],q[21];
cx q[7],q[22];
cx q[7],q[23];
cx q[7],q[24];
cx q[7],q[25];
cx q[7],q[26];
cx q[7],q[27];
cx q[7],q[28];
ry(0.00628205734034915) q[7];
cx q[8],q[9];
cx q[8],q[10];
cx q[8],q[11];
cx q[8],q[12];
cx q[8],q[13];
cx q[8],q[14];
cx q[8],q[15];
cx q[8],q[16];
cx q[8],q[17];
cx q[8],q[18];
cx q[8],q[19];
cx q[8],q[20];
cx q[8],q[21];
cx q[8],q[22];
cx q[8],q[23];
cx q[8],q[24];
cx q[8],q[25];
cx q[8],q[26];
cx q[8],q[27];
cx q[8],q[28];
ry(0.744708944890086) q[8];
cx q[9],q[10];
cx q[9],q[11];
cx q[10],q[11];
cx q[9],q[12];
cx q[10],q[12];
cx q[11],q[12];
cx q[9],q[13];
cx q[10],q[13];
cx q[11],q[13];
cx q[12],q[13];
cx q[9],q[14];
cx q[10],q[14];
cx q[11],q[14];
cx q[12],q[14];
cx q[13],q[14];
cx q[9],q[15];
cx q[10],q[15];
cx q[11],q[15];
cx q[12],q[15];
cx q[13],q[15];
cx q[14],q[15];
cx q[9],q[16];
cx q[10],q[16];
cx q[11],q[16];
cx q[12],q[16];
cx q[13],q[16];
cx q[14],q[16];
cx q[15],q[16];
cx q[9],q[17];
cx q[10],q[17];
cx q[11],q[17];
cx q[12],q[17];
cx q[13],q[17];
cx q[14],q[17];
cx q[15],q[17];
cx q[16],q[17];
cx q[9],q[18];
cx q[10],q[18];
cx q[11],q[18];
cx q[12],q[18];
cx q[13],q[18];
cx q[14],q[18];
cx q[15],q[18];
cx q[16],q[18];
cx q[17],q[18];
cx q[9],q[19];
cx q[10],q[19];
cx q[11],q[19];
cx q[12],q[19];
cx q[13],q[19];
cx q[14],q[19];
cx q[15],q[19];
cx q[16],q[19];
cx q[17],q[19];
cx q[18],q[19];
cx q[9],q[20];
cx q[10],q[20];
cx q[11],q[20];
cx q[12],q[20];
cx q[13],q[20];
cx q[14],q[20];
cx q[15],q[20];
cx q[16],q[20];
cx q[17],q[20];
cx q[18],q[20];
cx q[19],q[20];
cx q[9],q[21];
cx q[10],q[21];
cx q[11],q[21];
cx q[12],q[21];
cx q[13],q[21];
cx q[14],q[21];
cx q[15],q[21];
cx q[16],q[21];
cx q[17],q[21];
cx q[18],q[21];
cx q[19],q[21];
cx q[20],q[21];
cx q[9],q[22];
cx q[10],q[22];
cx q[11],q[22];
cx q[12],q[22];
cx q[13],q[22];
cx q[14],q[22];
cx q[15],q[22];
cx q[16],q[22];
cx q[17],q[22];
cx q[18],q[22];
cx q[19],q[22];
cx q[20],q[22];
cx q[21],q[22];
cx q[9],q[23];
cx q[10],q[23];
cx q[11],q[23];
cx q[12],q[23];
cx q[13],q[23];
cx q[14],q[23];
cx q[15],q[23];
cx q[16],q[23];
cx q[17],q[23];
cx q[18],q[23];
cx q[19],q[23];
cx q[20],q[23];
cx q[21],q[23];
cx q[22],q[23];
cx q[9],q[24];
cx q[10],q[24];
cx q[11],q[24];
cx q[12],q[24];
cx q[13],q[24];
cx q[14],q[24];
cx q[15],q[24];
cx q[16],q[24];
cx q[17],q[24];
cx q[18],q[24];
cx q[19],q[24];
cx q[20],q[24];
cx q[21],q[24];
cx q[22],q[24];
cx q[23],q[24];
cx q[9],q[25];
cx q[10],q[25];
cx q[11],q[25];
cx q[12],q[25];
cx q[13],q[25];
cx q[14],q[25];
cx q[15],q[25];
cx q[16],q[25];
cx q[17],q[25];
cx q[18],q[25];
cx q[19],q[25];
cx q[20],q[25];
cx q[21],q[25];
cx q[22],q[25];
cx q[23],q[25];
cx q[24],q[25];
cx q[9],q[26];
cx q[10],q[26];
cx q[11],q[26];
cx q[12],q[26];
cx q[13],q[26];
cx q[14],q[26];
cx q[15],q[26];
cx q[16],q[26];
cx q[17],q[26];
cx q[18],q[26];
cx q[19],q[26];
cx q[20],q[26];
cx q[21],q[26];
cx q[22],q[26];
cx q[23],q[26];
cx q[24],q[26];
cx q[25],q[26];
cx q[9],q[27];
cx q[10],q[27];
cx q[11],q[27];
cx q[12],q[27];
cx q[13],q[27];
cx q[14],q[27];
cx q[15],q[27];
cx q[16],q[27];
cx q[17],q[27];
cx q[18],q[27];
cx q[19],q[27];
cx q[20],q[27];
cx q[21],q[27];
cx q[22],q[27];
cx q[23],q[27];
cx q[24],q[27];
cx q[25],q[27];
cx q[26],q[27];
cx q[9],q[28];
cx q[10],q[28];
ry(0.384115610548274) q[10];
cx q[11],q[28];
ry(0.338183010030888) q[11];
cx q[12],q[28];
ry(0.106127146696181) q[12];
cx q[13],q[28];
ry(0.755633919621646) q[13];
cx q[14],q[28];
ry(0.79149851538046) q[14];
cx q[15],q[28];
ry(0.0074295945525279) q[15];
cx q[16],q[28];
ry(0.603873573275181) q[16];
cx q[17],q[28];
ry(0.953451553027155) q[17];
cx q[18],q[28];
ry(0.344998883757925) q[18];
cx q[19],q[28];
ry(0.89477568680025) q[19];
cx q[20],q[28];
ry(0.970806632063513) q[20];
cx q[21],q[28];
ry(0.908457896305265) q[21];
cx q[22],q[28];
ry(0.0341837457259172) q[22];
cx q[23],q[28];
ry(0.932103184116167) q[23];
cx q[24],q[28];
ry(0.663243544573272) q[24];
cx q[25],q[28];
ry(0.350259330783938) q[25];
cx q[26],q[28];
ry(0.950596188101001) q[26];
cx q[27],q[28];
ry(0.717863540005035) q[27];
ry(0.575126068764215) q[28];
ry(0.769623071568869) q[9];
barrier q[0],q[1],q[2],q[3],q[4],q[5],q[6],q[7],q[8],q[9],q[10],q[11],q[12],q[13],q[14],q[15],q[16],q[17],q[18],q[19],q[20],q[21],q[22],q[23],q[24],q[25],q[26],q[27],q[28];
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
measure q[26] -> meas[26];
measure q[27] -> meas[27];
measure q[28] -> meas[28];
