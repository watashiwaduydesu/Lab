#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int cong(int a, int b)
{
	return a + b;
}
int tru(int a, int b)
{
	return a - b;
}
int nhan(int a, int b)
{
	return a * b;
}
int chia(int a, int b)
{
	return a / b;
}
void main()
{
	int operand_1 = 0, operand_2 = 0, answer = 0;
	string input, iop1; 
	char _operator;
	cout << "Nhap:\n";
	getline(cin,input);
	stringstream(input) >> operand_1;
	iop1 = to_string(operand_1);
	input.erase(input.begin(), input.begin() + iop1.size());
//	cout<<input<<endl;
	stringstream(input) >> _operator;
	input.erase(input.begin(), input.begin() + 1);
	stringstream(input) >> operand_2;
//	cout << operand_1 <<endl;
//	cout << _operator << endl;
//	cout << operand_2 << endl;

	switch (_operator)
	{
	case '+': answer = cong(operand_1,operand_2); break;
	case '-': answer = tru(operand_1, operand_2); break;
	case '*': answer = nhan(operand_1, operand_2); break;
	case '/': answer = chia(operand_1, operand_2); break;
	}
	cout << answer << endl;
	system("pause");
}
