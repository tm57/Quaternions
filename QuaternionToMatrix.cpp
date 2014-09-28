/*Tinashe Matate
Robotics Assignment 3
Problem 3
I just implemented a function to compute a rotation matrix from a given quaternion here
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void QuaternionToMatrix(double a, double b , double c, double d);

int main(int argc, char **argv){
	QuaternionToMatrix(0.2191769,0.4288243, 0.6384718, 0.6003541);//solution to the given problem
	return 0;
}

void QuaternionToMatrix(double a, double b , double c, double d){
	double *mat = new double[9];
	for(int i = 0; i < 9; i++){
		switch (i){
			case 0:
				mat[i] = a*a+b*b-c*c-d*d;
				break;
			case 1:
				mat[i] = 2*b*c-2*a*d;
				break;
			case 2:
				mat[i] = 2*b*d + 2*a*c;
				break;
			case 3:
				mat[i] = 2*b*c + 2*a*d;
				break;
			case 4:
				mat[i] = a*a-b*b+c*c-d*d;
				break;
			case 5:
				mat[i] = 2*c*d - 2*a*b;
				break;
			case 6:
				mat[i] = 2*b*d - 2*a*c;
				break;
			case 7:
				mat[i] = 2*c*d + 2*a*b;
				break;
			case 8:
				mat[i] = a*a-b*b-c*c+d*d;
				break;
			default:
				cout << endl;
		}
	}
	cout <<"Here is the rotation Matrix after the convertion from Quaternion\n\n";
	for (int j = 0; j < 3; j++)
		cout << setprecision(7) << mat[j]<< " ";
		cout << endl;
	for (int j = 3; j < 6; j++)
		cout << setprecision(7) << mat[j]<< " ";
		cout << endl;
	for (int j = 6; j < 9; j++)
		cout << setprecision(7) << mat[j]<< " ";
		cout << endl;
	
}
