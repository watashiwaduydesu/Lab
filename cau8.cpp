#include <iostream>
using namespace std;
#define MAX_SIZE 20
void main()
{
	char input[MAX_SIZE];
	int size = 0;
	int start = 0, end = 0;
	for (int i = 0; i < MAX_SIZE; i++) input[i] = '-';
	cin.getline(input,MAX_SIZE);
	for (int i = 0; i <MAX_SIZE; i++)
	{
		if (input[i]!='-'&&input[i]!='\0')
		size++;
	}
	for (int i = 0; i < size / 2; i++)
	{
		char temp=input[i];
		input[i] = input[size - 1 - i];
		input[size - 1 - i]=temp;
	}
	for (int i = 0; i <= size; i++)
	{
		cout << input[i];
	}
	cout << endl;
	for (int i =0; i <= size;i++)
	{
		if (input[i] == ' '|| input[i]=='\0')
		{
			start = i;
			for (int j = start-1; j >= end; j--)
			{
				cout << input[j];
			}
			end = start;
			cout << " ";
		}
	}
	cout << endl;
	system("pause");
}
