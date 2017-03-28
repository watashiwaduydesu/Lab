#include <iostream>
#include <cmath>
using namespace std;
void main()
{
	double a = 0, b = 0, c = 0, d = 0;
	cout << "Nhap he so:\n";
	cout << "a:"; cin >> a;
	cout << "b:"; cin >> b;
	cout << "c:"; cin >> c;
	d = (b * b) - 4 * (a*c);
	if (a == 0 && b == 0)
	{
		cout << "Phuong trinh bac 0. ";
		if (c == 0)
		{
			cout << "Vo so nghiem.\n";
		}
		else
		{
			cout << "Vo nghiem.\n";
		}
	}

	else
	{
		if (a == 0 && b != 0)
		{
			cout << "Phuong trinh bac nhat. ";
			if (c == 0)
			{
				cout << "x=" << 0;
			}
			else
			{
				cout << "x=" << -c / b;
			}
		}
		else
		{
			cout << "Phuong trinh bac 2. ";
			if (d < 0)
			{
				cout << "Vo nghiem.\n";
			}
			if (d==0)
			{
				cout << "Co nghiem kep x=" << -b / (2 * a) << endl;
			}
			if (d >0)
			{
				cout << "Co 2 nghiem phan biet.\n";
				cout << "x1=" << (-b + sqrt(d)) / (2 * a)<<endl;
				cout << "x2=" << (-b - sqrt(d)) / (2 * a)<<endl;
			}
		}
		
	}
	system("pause");
}
