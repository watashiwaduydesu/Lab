#include <iostream>
using namespace std;
void main()
{
	float n=0;
	int previous=1, current=1, next;
	do
	{
		system("cls");
		cout << "Nhap N:";
		cin >> n;
		cin.clear();
		cin.ignore();
		if (n - (int)n != 0)
		{
			n = -2;
			continue;
		}
	} while (n<0);
	for (int i = 0; i <n-2; i++)
	{
		if (n == 1)
		{
			current = 1;
			break;
		}
		if (n == 2)
		{
			current = 1;
			break;
		}
		else
		{
			next = previous + current;
			previous = current;
			current = next;
		}
	}
	cout << "F(" << n << ") = " << current << endl;
	system("pause");
}
