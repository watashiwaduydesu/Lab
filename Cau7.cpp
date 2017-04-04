#include<iostream>
#include <iomanip>
using namespace std;

int main()
{
	int h=0;
	cout << "Nhap H:"; cin >> h;
	for (int i = 1; i <= h; i++)
	{
		cout << setw(h - i +1);
		for (int j = 1; j <= 2 * i - 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << setw(h+1) << "*" << endl;
	for (int i = 1; i < h; i++)
	{
		cout << setw(h - i + 1);
		cout << "*";
		cout << setw(2 * i) << "*";
		cout << endl;
	}
	for (int i = 1; i <= 2 * h + 1; i++)
	{
		cout << "*";
	}
	cout << endl;
	system("pause");
	return 0;
}
