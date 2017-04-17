#include <iostream>
#include <cmath>
#define MAX_SIZE 50
using namespace std;
void main()
{
	int N = 0;
	double x[MAX_SIZE], sum = 0, sum_square = 0;
	for (int i = 0; i < MAX_SIZE;i++)
	{
		cin >> x[i];
		if (x[i] < 0)
		{
			break;
		}
		N++;
		sum += x[i];
	}
	sum = sum / N;
	cout << sum << endl;
	for (int i = 0; i < N; i++)
	{
		sum_square += (x[i]-sum)*(x[i] - sum);
	}
	sum_square = sqrt((1 / (double)N)* (sum_square));
	cout << "Do lech chuan = " <<fixed << 1 / (double)N << endl;
	for (int i = 0; i < N/ 2; i++)
	{
		double temp = 0;
		temp = x[i];
		x[i] = x[N - 1 - i];
		x[N - 1 - i] = temp;
	}
	for (int i = 0; i < N; i++)
	{
		cout << x[i] << " ";
	}
	system("pause");
}
