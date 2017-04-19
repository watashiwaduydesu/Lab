#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#define DATA_SIZE 20000
using namespace std;

unsigned int iterations;
double learning_rate;
double start_a, start_b, a, b;
unsigned int K=0;
unsigned long long M=0;
unsigned long long D=0;
double tinhsigma(double ei,double e_)
{
	double sum = 0;
	for (int i = 1; i <= D; i++)
	{
		sum += pow(ei - e_, 2);
	}
	return sqrt(pow(D,-1)*sum);
}
double tinh_e_(double ei)
{
	double sum = 0;
	for (int i = 1; i <= D; i++) sum += ei;
	return pow(D, -1)*sum;
}
double tinhsaiso(double a, double b, double x,  double t)
{
	double sum = 0;
	for (int j = 1; j <= D; j++)
	{
		sum += pow(a*x + b - t,2);
	}
	return sqrt(pow(D,-1)*sum);
}

double tinh_y(double x)
{
	double y = a * x + b;
	return y;
}



void cap_nhat_toa_do_a_b(double ga, double gb)
{
	a = a - learning_rate*ga;
	b = b - learning_rate*gb;
}
void main() {
	//Variables
	string str;
	string str_value;
	struct data
	{
		double x, t;
	};

	getline(cin, str); //skip
	getline(cin, str); //skip
	getline(cin, str); //skip
	istringstream iss;
	//get trn_params.num_iterations = iterations
	getline(cin, str); iss.str(str);
	iss >> str_value; iss >> iterations; 
	iss.clear();
	//get trn_params.learning_rate = learning_rate
	getline(cin, str); 	iss.str(str);
	iss >> str_value; iss >> learning_rate;
	iss.clear();
	//get trn_params.start_a = start_a
	getline(cin, str); iss.str(str);
	iss >> str_value; iss >> start_a;
	iss.clear();
	//get trn_params.start_b = start_b
	getline(cin, str); 	iss.str(str);
	iss >> str_value; iss >> start_b;
	iss.clear();
	//get trn_params.num_iterations = K
	getline(cin, str); 		iss.str(str);
	iss >> str_value; iss >> K;

	a = start_a;
	b = start_b;
	//get data samples

	getline(cin, str); //skip
	getline(cin, str); //skip
	getline(cin, str); //skip

	data input[DATA_SIZE];
	for (int i = 0; i <= DATA_SIZE; i++)
	{
		if (!cin.eof())
		{
			M += 1;
			istringstream iss;
			getline(cin, str);
			iss.str(str);
			iss >> input[i].x >> input[i].t;
			//cout << input[i].x << " " << input[i].t << endl;
			iss.clear();
		}
	}
	

	D = M / K;
	
	//cout << "K=" << K << endl;
	//cout << "M=" << M << endl;
	//cout << "D=" << D << endl;
	/*
	int i = 0;
	for (i = 0; i < K-1; i++)
	{
		for (int j = i*D; j <= (i + 1)*D - 1; j++)
		{
			cout << input[j].x << " " << input[j].t << endl;
		}
		cout << "----------------------" << endl;
	}
	//cout << i << endl;
	for (int j = i*D; j < M; j++)
	{
		cout << input[j].x << " " << input[j].t << endl;
	}
	*/
	//
	for (int k = 0; k < K-1; k++)
	{
		//Thực thiện trên tập TRN, tim (a,b)
		double ga = 0, gb = 0;
		for (int i = 1; i <= iterations; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (!(j >= k*D && j <= (k + 1)*D - 1))
				{
					//cout << input[j].x << "," << input[j].t << endl;
					ga += (a*input[j].x + b - input[j].t)*input[j].x;
					gb += a*input[j].x + b - input[j].t;
				}
			}
			ga = ga / sqrt(ga*ga + gb*gb);
			gb = gb / sqrt(ga*ga + gb*gb);
			cout << ga << ";" << gb << endl;
			cap_nhat_toa_do_a_b(ga, gb);
			cout << "----------------" << endl;
		}
		

		//Thực hiện trên tập TST 
		for (int j = k*D; j <= (k + 1)*D - 1; j++)
		{
			
		}



		//cout << a << ";" << b << endl;
	}
}

