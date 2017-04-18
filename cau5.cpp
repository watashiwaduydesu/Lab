#include <iostream>
#include <sstream>
#include <cmath>
#define N_MIN 2
#define M_MIN 2
#define MAX 100
using namespace std;
struct vector_matrix
{
	double value[MAX][MAX];
};

void main()
{
	vector_matrix x;
	string str;
	istringstream iss;
	int M=0,N=1;

	getline(cin, str);
	iss.str(str);

	for (int i = 0; i < MAX; i++)
	{
		if (!iss.eof())
		{
			M++;
			iss >> x.value[0][i];
			//cout << x.value[0][i] <<" ";
		}
		else
		{
			i = MAX;
		}
	}
	cout <<  endl;
	int j = 1;
	double t;
	while (getline(cin, str))
	{
		iss.clear();
		iss.str(str);
		N++;
		for (int k = 0; k < M; k++)
		{
			iss >> x.value[j][k];
			//cout << x.value[j][k] <<" ";
		}
		j++;
		cout << endl;
	}
	//cout << N + 1 << endl;
	double sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < M; j++)
		{
			sum += x.value[i][1] * x.value[i][j];
		}
		cout << sum << " ";
		sum = 0;
	}
}
