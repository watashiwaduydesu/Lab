#include <iostream>
#include <iomanip>
#include <math.h>
#define MAX_VERT 50
#define len(a,b) sqrt(pow((a.x - b.x),2)+ pow((a.y - b.y),2))
using namespace std;
void main()
{
	float N=0;
	float cv = 0;
	struct vertice {
		float x;
		float y;
	};
	vertice Vertices[MAX_VERT];
	do
	{
		
		cout << "Nhap N=";
		cin >> N;
		cin.clear();
		cin.ignore();
	} while ( (N<=2 || N > MAX_VERT) || N - (int)N != 0||!cin.good());
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		Vertices[i].x = pow(-1, rand() % 2)*(rand() % 100001)/100;
		Vertices[i].y = pow(-1, rand() % 2)*(rand() % 100001)/100;
		cout << Vertices[i].x << "," << Vertices[i].y << endl;
	}
	
	for (int i = 0; i < MAX_VERT-1; i++)
	{
		cv += len(Vertices[i], Vertices[i + 1]);
	}
	cv += len(Vertices[0], Vertices[(int)N - 1]);
	cout.setf(ios::fixed, ios::floatfield);
	cout <<"cv="<< cv << endl;
	system("pause");
}
