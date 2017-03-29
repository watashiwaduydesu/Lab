#include <iostream>
using namespace std;
int main()
{
	int N;
	cout << "Nhap N:";
	cin >> N;
	if (N >= 100 || N <= 0)
	{
		cout << "Loi.\n";
		system("pause");
		return 0;
	}
	unsigned long long a[99] = {1};
	unsigned long long b[99] = {1,1};
	for (int k = 1; k <= N - 2; k++)
	{
		for (int i = 0; i < 100; i++)
		{
			a[i] = b[i];
		}

		for (int i = 1; i < 100; i++)
		{
			b[i] = a[i - 1] + a[i];
		}
		
	}
	for (int i = 0; i < 99; i++)
	{
		if (b[i] != 0)
		{
			cout << b[i] << " ";
		}
	}
	cout << endl;
	system("pause");
	return 0;
}
