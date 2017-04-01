#include <iostream>
using namespace std;

void main()
{
	long N,sum=0;
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
		sum += i*i;
	}
	cout << "Tong binh phuong tu cac so nguyen duong tu 1 den " << N << " la " << sum << endl;
	system("pause");
}
