#include <iostream>
#include <cmath>
#define epsilon 1.0E-10
#define pi 3.14
using namespace std;
unsigned long long gt(unsigned long long x)
{
	unsigned long long g = 1;
	for (unsigned long long i = 1; i <= x; i++)
	{
		g *= i;
	}
	return g;
}
void main()
{
	double xd = 0, x = 0, A = 0, pt = 0, tong=0;
	long B = 0, C = 0;
	cout << "Nhap x:"; cin >> xd;
	
	x = xd*pi / 180;
	for (int n = 0; n <= 8; n++)
	{
		A = pow(x, 2 * n + 1);
		B = gt(2 * n + 1);
		C = pow(-1, n);
		pt = C*A / B;
		tong += pt;
		if (abs(pt) < epsilon)
		{
			break;
		}
	}
	cout << "sin(" << xd << ") = " << tong << endl;
	system("pause");
}
