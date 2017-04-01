#include <iostream>
using namespace std;

void main()
{
	long N, Ntemp;
	float temp;
	double avg = 0;
	do
	{
		system("cls");
		cout << "Nhap N:";
		cin >> N;
		Ntemp = N;
		cin.clear();
		cin.ignore();
	} while (N <= 0);
	cout << "N=" << N << endl;
	cout << "Cac so thuc bieu dien diem he 10:\n";
	while (N > 0)
	{
		temp = (rand() % 1001) / 100.0;
		N = N - 1;
		cout << temp << endl;
		avg+=temp;
	}
	avg = avg/Ntemp;
	cout << "Trung binh cua cac so tren la " << avg << endl;
	system("pause");
}
