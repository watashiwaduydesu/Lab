#include <iostream>
using namespace std;

void main()
{
	long N;
	do
	{
		
		system("cls");
		cout << "Nhap N:";
		cin >> N;
		cin.clear();
		cin.ignore();
	} while (N <= 0);
	cout << N << endl;
	system("pause");
}
