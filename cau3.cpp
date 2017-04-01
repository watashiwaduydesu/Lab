#include <iostream>
using namespace std;

void main()
{
	long N;
	unsigned long long sum=0;
	do
	{
		system("cls");
		cout << "Nhap N:";
		cin >> N;
		cin.clear();
		cin.ignore();
	} while (N <= 0);
	for (int i = 1; i <= N; i+=2)
	{
		sum += i*i;
	}
	cout << "Tong binh phuong tu cac so le tu 1 den " << N << " la " << sum << endl;
	system("pause");
}
