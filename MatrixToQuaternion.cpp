#include <iostream>
#include <cmath>
#include <iomanip>
#include <iomanip>
#include <cstdlib>

using namespace std;
/*This function converts a rotation matrix into a unit quaternion
since the norm of the quaternion is one,we will make use of that to extract the diagonal elements
of the rotation matrix and sove the rest as the code clearly unveils evrything below*/
void MatrixToQuaternion(double **mat);
inline double SIGN(double x) {return (x >= 0) ? +1.0 : -1.0;}
inline double NORM(double a, double b, double c, double d) {return sqrt(a * a + b * b + c * c + d * d);}

int main(int argc, char const *argv[])
	{
		double **mat = new double*[3];
	for(int i = 0; i < 3; ++i) {
	    mat[i] = new double[3];
	}
			cout<< "Hello World,enter matrix\n";
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				cin >> mat[i][j];
			}
		}
		MatrixToQuaternion(mat);
	
	return 0;
}

void MatrixToQuaternion(double **mat){
double q0 = ( mat[0][0] + mat[1][1] + mat[2][2] + 1.0) / 4.0;//entries of the quaternion we need to find
double q1 = ( mat[0][0] - mat[1][1] - mat[2][2] + 1.0) / 4.0;
double q2 = (-mat[0][0] + mat[1][1] - mat[2][2] + 1.0) / 4.0;
double q3 = (-mat[0][0] - mat[1][1] + mat[2][2] + 1.0) / 4.0;

if(q0 < 0) q0 = 0;
if(q1 < 0) q1 = 0;
if(q2 < 0) q2 = 0;
if(q3 < 0) q3 = 0;

q0 = sqrt(q0);
q1 = sqrt(q1);
q2 = sqrt(q2);
q3 = sqrt(q3);
if(q0 >= q1 && q0 >= q2 && q0 >= q3) {
    q0 *= +1.0;
    q1 *= SIGN(mat[2][1] - mat[1][2]);
    q2 *= SIGN(mat[0][2] - mat[2][0]);
    q3 *= SIGN(mat[1][0]- mat[0][1]);
} else if(q1 >= q0 && q1 >= q2 && q1 >= q3) {
    q0 *= SIGN(mat[2][1] - mat[1][2]);
    q1 *= +1.0;
    q2 *= SIGN(mat[1][0]+ mat[0][1]);
    q3 *= SIGN(mat[0][2] + mat[2][0]);
} else if(q2 >= q0 && q2 >= q1 && q2 >= q3) {
    q0 *= SIGN(mat[0][2] - mat[2][0]);
    q1 *= SIGN(mat[1][0]+ mat[0][1]);
    q2 *= +1.0;
    q3 *= SIGN(mat[2][1] + mat[1][2]);
} else if(q3 >= q0 && q3 >= q1 && q3 >= q2) {
    q0 *= SIGN(mat[1][0]- mat[0][1]);
    q1 *= SIGN(mat[2][0] + mat[0][2]);
    q2 *= SIGN(mat[2][1] + mat[1][2]);
    q3 *= +1.0;
} else {
    cerr<<"coding error\n";
}

double r = NORM(q0, q1, q2, q3);
q0 /= r;
q1 /= r;
q2 /= r;
q3 /= r;
cout<<"The quaternion obtained, z = ("<< setprecision(3) << q0 << ",( "<< q1 << " , "<< q2 << " , "<< q3<<" ))"<<endl; 

}

