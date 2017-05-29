#ifndef DATE
#define DATE
#include <iostream>
#include <string>
using namespace std;
class Date
{
public:
	int d , m, y;
public:
	Date();
	Date(int, int, int);
	~Date();
	friend ostream& operator<<(ostream& os, const Date&);
	friend istream& operator>>(istream&, Date&);
	bool operator< (Date);
	string toString();
};
#endif
