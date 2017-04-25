#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#define DATA_SIZE 20000
using namespace std;

unsigned int iterations;
double learning_rate;
double start_a, start_b, a, b;
unsigned int K = 0;
unsigned long long M = 0;
unsigned long long D = 0;

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

int main() {
	//Variables
	string str;
	string str_value;
	struct data
	{
		double x, t;
		double y;
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
		while (!cin.eof())
		{
			getline(cin, str);
			if (!str.empty())
			{
				if (!cin.fail())
				{
					M += 1;
					istringstream iss;
					//getline(cin, str);
					iss.str(str);
					iss >> input[i].x >> input[i].t;
					//cout << input[i].x << " " << input[i].t << endl;
				}
				i++;
			}
		}
	}
	D = M / K;
	for (int k = 0; k < K; k++)
	{
		bool isInTST[DATA_SIZE];
		int numberOfTSTElement = 0;
		for (int i = 0; i < M; i++) isInTST[i] = false;
		for (int i = k*D; i < M; i++)
		{
			if (i < (k + 1)*D || k == K - 1)
			{
				isInTST[i] = true;
				numberOfTSTElement++;
			}
		}
		//Find (a,b) on set TRN
		double ga = 0, gb = 0, length = 0;
		for (int i = 1; i <= iterations; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (isInTST[j] == false)
				{
					//cout << input[j].x << "," << input[j].t << endl;
					ga += (a*input[j].x + b - input[j].t)*input[j].x;
					gb += (a*input[j].x + b - input[j].t);
				}
			}
			length = sqrt(ga*ga + gb*gb);
			ga = ga / length;
			gb = gb / length;
			//cout << "length="<<length<<endl;
			//cout << ga << ";" << gb << endl;
			cap_nhat_toa_do_a_b(ga, gb);
		}


		//Find Ermsd on set TST
		double Ermsd = 0;
		for (int j = 0; j <M; j++)
		{
			if (isInTST[j] == true)
			{
				input[j].y = tinh_y(input[j].x);
				//cout << input[j].y << "~";
				Ermsd += pow(a*input[j].x + b - input[j].t, 2);
			}
		}
		Ermsd = sqrt((1 / (double)numberOfTSTElement)*Ermsd);

		//Find e_mean on set TST with ei= yi - ti
		double e_mean = 0;
		for (int j = 0; j <M; j++)
		{
			if (isInTST[j] == true)
				e_mean += input[j].y - input[j].t;
		}
		e_mean = (1 / (double)(numberOfTSTElement))*e_mean;
		//Find sigma on set TST
		double sigma = 0; // tổng bình phương (ei - e_mean)
		double ei = 0;
		for (int j = 0; j <M; j++)
		{
			if (isInTST[j] == true)
			{
				ei = input[j].y - input[j].t;
				sigma += pow(ei - e_mean, 2);
			}
		}
		sigma = sqrt(sigma / numberOfTSTElement);
		//cout << sigma << "!!";
		//Find Vmin, Vmax, freq
		double Vmin = 0, Vmax = 0, max_min = 0;;
		Vmin = e_mean - 3 * sigma;
		Vmax = e_mean + 3 * sigma;
		max_min = (Vmax - Vmin) / 10;
		//cout << Vmin << "~" << Vmax << "~" << max_min;

		struct freq_range
		{
			double r_min;
			double r_max;
		};
		freq_range range[10];
		for (int i = 0; i < 10; i++)
		{
			range[i].r_min = Vmin + (i)*(max_min);
			range[i].r_max = Vmin + (i + 1)*(max_min);
			//cout << range[i].r_min << "~" << range[i].r_max << endl;
		}
		long count[10];
		for (int i = 0; i < 10; i++)
		{
			count[i] = 0;
		}
		long total = 0;
		//Find freq on set TST
		for (int j = 0; j <M; j++)
		{
			if (isInTST[j] == true)
			{
				for (int i = 0; i < 10; i++)
				{
					if (i != 9)
					{
						if ((input[j].y - input[j].t) >= range[i].r_min && (input[j].y - input[j].t) < range[i].r_max)
						{
							total++;
							count[i]++;
							break;
						}
					}
					else
					{
						if ((input[j].y - input[j].t) >= range[i].r_min && (input[j].y - input[j].t) < range[i].r_max)
						{
							total++;
							count[i]++;
							break;
						}
					}
				}
			}
		}

		double freq[10];
		for (int i = 0; i < 10; i++)
		{
			freq[i] = (double)count[i] / total;
		}
		cout.setf(ios::fixed, ios::floatfield);
		cout.precision(5);
		cout << right << setw(10) << a << setw(10) << right << b;
		cout << setw(10) << right << Ermsd;
		for (int i = 0; i < 10; i++)
		{
			cout << setw(10) << right << freq[i];
		}
		a = start_a;
		b = start_b;
		numberOfTSTElement = 0;
		for (int i = 0; i < M; i++) isInTST[i] = 0;
		cout << endl;
	}
	return 0;
}
