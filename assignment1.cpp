#include <iostream>
#include <cmath>
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
	cout << "---------------------------------------------------------------------------------" << endl;
	cout << "Output of the validation" << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
	for (int k = 0; k < K-1; k++)
	{
		//Thực thiện trên tập TRN, tìm (a,b)
		double ga = 0, gb = 0, length=0;
		for (int i = 1; i <= iterations; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (!(j >= k*D && j <= (k + 1)*D - 1))
				{
					//cout << input[j].x << "," << input[j].t << endl;
					ga += (a*input[j].x + b - input[j].t)*input[j].x;
					gb += (a*input[j].x + b - input[j].t);
				}
			}
			length = sqrt(ga*ga + gb*gb);
			ga = ga / length;
			gb = gb / length;
			//cout << ga << ";" << gb << endl;
			cap_nhat_toa_do_a_b(ga, gb);
		}
		

		//Thực hiện trên tập TST tính sai số dự báo
		double Ermsd = 0;
		for (int j = k*D; j <= (k + 1)*D - 1; j++)
		{
			input[j].y = tinh_y(input[j].x);
			Ermsd += pow(a*input[j].x + b - input[j].t, 2);
		}
		Ermsd = sqrt((1 / (double)D)*Ermsd);

		//Tính e_mean trên TST với ei= yi - ti
		double e_mean = 0;
		for (int j = k*D; j <= (k + 1)*D - 1; j++)
		{
			e_mean += input[j].y - input[j].t;
		}
		e_mean = (1/(double)D)*e_mean;
		//Tính sigma trên TST
		double sigma = 0; // tổng bình phương (ei - e_mean)
		double ei = 0;
		for (int j = k*D; j <= (k + 1)*D - 1; j++)
		{
			ei = input[j].y - input[j].t;
			sigma = pow(ei - e_mean,2);
		}
		sigma = sqrt((1 / (double)D)*sigma);
		//Tính Vmin, Vmax, mảng tần suất
		double Vmin = 0, Vmax = 0, max_min = 0;;
		Vmin = e_mean - 3 * sigma;
		Vmax = e_mean + 3 * sigma;
		max_min = (Vmax - Vmin)/10;
		struct freq_range
		{
			double r_min;
			double r_max;
		};
		freq_range range[10];
		for (int i = 0; i < 10; i++)
		{
			range[i].r_min = (i)*(max_min);
			range[i].r_max = (i + 1)*(max_min);
			//cout << range[i].r_min << "~" << range[i].r_max << endl;
		}
		long count[10];
		long total=0;
		//Cho ei vào tính tần suất trên tập TST
		for (int j = k*D; j <= (k + 1)*D - 1; j++)
		{
			for (int i = 0; i < 10; i++)
			{
				if ((input[j].y - input[j].t) >= range[i].r_min && (input[j].y - input[j].t) < range[i].r_max)
				{
					total++;
					count[i]++;
					break;
				}
			}
		}
		//Tính tần suất
		double freq[10];
		for (int i = 0; i < 10; i++)
		{
			freq[i] = (double)count[i]/total;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(3);
		cout << right << setw(7) << a << setw(7) << right << b;
		cout << setw(7) << right << Ermsd;
		for (int i = 0; i < 10; i++)
		{
			cout << setw(7) << right << freq[i];
		}
		a = start_a;
		b = start_b;

		cout << endl;
	}

	//Tập thứ K(cuối cùng)

	//Thực thiện trên tập TRN, tim (a,b)
	double ga = 0, gb = 0, length = 0;
	for (int i = 1; i <= iterations; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!(j >= (K-1)*D && j <= M)) // Từ K*D đến M
			{
				//cout << input[j].x << "," << input[j].t << endl;
				ga += (a*input[j].x + b - input[j].t)*input[j].x;
				gb += (a*input[j].x + b - input[j].t);
			}
		}
		length = sqrt(ga*ga + gb*gb);
		ga = ga / length;
		gb = gb / length;
		//cout << ga << ";" << gb << endl;
		cap_nhat_toa_do_a_b(ga, gb);
	}
	//Thực hiện trên tập TST tính sai số dự báo
	double Ermsd = 0;
	for (int j = (K-1)*D; j <= M; j++)
	{
		input[j].y = tinh_y(input[j].x);
		Ermsd += pow(a*input[j].x + b - input[j].t, 2);
	}
	Ermsd = sqrt((1 / (double)D)*Ermsd);

	//Tính e_mean trên TST với ei= yi - ti
	double e_mean = 0;
	for (int j = (K-1)*D; j <= M; j++)
	{
		e_mean += input[j].y - input[j].t;
	}
	e_mean = (1 / (double)D)*e_mean;

	//Tính sigma trên TST
	double sigma = 0; // tổng bình phương (ei - e_mean)
	double ei = 0;
	for (int j = (K-1)*D; j <= M; j++)
	{
		ei = input[j].y - input[j].t;
		//cout << ei << endl;
		sigma = pow(ei - e_mean, 2);
	}
	sigma = sqrt((1 / (double)D)*sigma);
	//Tính Vmin, Vmax, mảng tần suất
	double Vmin = 0, Vmax = 0, max_min = 0;;
	Vmin = e_mean - 3 * sigma;
	Vmax = e_mean + 3 * sigma;
	max_min = (Vmax - Vmin) / 10;
	struct freq_range
	{
		double r_min;
		double r_max;
	};
	freq_range range[10];
	for (int i = 0; i < 10; i++)
	{
		range[i].r_min = (i)*(max_min);
		range[i].r_max = (i + 1)*(max_min);
		//cout << range[i].r_min << "~" << range[i].r_max << endl;
	}
	long count[10];
	long total = 0;
	//Cho ei vào tính tần suất trên tập TST
	for (int j = (K-1)*D; j <= M; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			if ((input[j].y - input[j].t) >= range[i].r_min && (input[j].y - input[j].t) < range[i].r_max)
			{
				total++;
				count[i]++;
				break;
			}
		}
	}
	//Tính tần suất
	//cout << "total=" << total << endl;
	double freq[10];
	for (int i = 0; i < 10; i++)
	{
		freq[i] = (double)count[i] / total;
	}
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(3);
	cout << right << setw(7) << a << setw(7) << right << b;
	cout << setw(7) << right << Ermsd;
	for (int i = 0; i < 10; i++)
	{
		cout << setw(7) << right << freq[i];
	}
	a = start_a;
	b = start_b;

}
