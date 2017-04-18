#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#define MAX_DIMENSION 50
#define pi 3.14
using namespace std;
void main()
{
	typedef struct {
		double value[MAX_DIMENSION];
		double dimension;
		double length;
	} vector;
	vector A;
	vector B;
	string str;
	stringstream sstr;
	istringstream iss;
	double angle = 0;
	A.dimension = 0;
	B.dimension = 0;
	getline(cin, str);
	getline(cin, str);
	getline(cin, str);

	getline(cin, str);
	iss.str(str);
	for (int i = 0; i <MAX_DIMENSION; i++)
	{
		if (!(iss.eof()))
		{
			iss >> A.value[i];
			A.dimension++;
			//cout << A.value[i] << " ";
		}
	}
	cout << endl;
	iss.str();
	iss.clear();
	getline(cin, str);
	iss.str(str);
	for (int i = 0; i <MAX_DIMENSION; i++)
	{
		if (!(iss.eof()))
		{
			iss >> B.value[i];
			B.dimension++;
			//cout << B.value[i] << " ";
		}
	}

	if (A.dimension != B.dimension) cout << "2 vector ko cung so chieu" << endl;
	else
	{
		cout << "Chieu dai vector " << endl;
		for (int i = 0; i < A.dimension; i++)
		{
			A.length += A.value[i] * A.value[i];
		}
		A.length = sqrt(A.length);
		for (int i = 0; i < B.dimension; i++)
		{
			B.length += B.value[i] * B.value[i];
		}
		B.length = sqrt(B.length);
		cout.setf(ios::fixed, ios::floatfield);
		cout.precision(3);
		cout << "A ="<< A.length << "    B=" << B.length<< endl;
		double tvh = 0;
		for (int i = 0; i < A.dimension; i++)
		{
			tvh += A.value[i] * B.value[i];
		}
		cout << "Tich vo huong = " << tvh << endl;
		if (A.dimension == 3)
		{
			cout << "Tich huong huong = " << "(" << A.value[1] * B.value[2] - A.value[2] * B.value[1] << "," << -A.value[0] * B.value[2] + A.value[2] * B.value[1] << "," << A.value[0] * B.value[1] - A.value[1] * B.value[0] <<")"<< endl;
		}
		cout << "Goc 2 vector= " << acos((tvh) / (A.length*B.length)) << endl;
		cout << "Do dai hinh chieu a tren b = " << tvh / B.length << endl;
		cout << "Do dai hinh chieu b tren a = " << tvh / A.length << endl;
	}
}
