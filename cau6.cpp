#include <iostream>
using namespace std;

void main()
{
	long N;
	unsigned long long gt=1;
	do
	{
		system("cls");
		cout << "Nhap N:";
		cin >> N;
		cin.clear();
		cin.ignore();
	} while (N <= 0);
	for (int i = 1; i <= N; i++)
	{
		gt *= i;
	}
	cout << N << "! = " << gt << endl;
	system("pause");
}
