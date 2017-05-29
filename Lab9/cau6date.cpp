#include "date.h"
#include <sstream>
using namespace std;

Date::Date() : d(28), m(05), y(2017){};
Date::Date(int d_, int m_, int y_) : d(d_), m(m_), y(y_) {};
Date::~Date() {};
ostream& operator<<(ostream& os,const Date& x)
{
	os << x.d << "/" << x.m << "/" << x.y << endl;
	return os;
}
istream& operator>>(istream& is,Date& x) {
	char temp;
	is >> x.d;
	is >> temp;
	is >> x.m;
	is >> temp;
	is >> x.y;
	//cout << x.d << "/" << x.m << "/" << x.y << endl;
	return is;
}
bool Date::operator<(Date b) {
	if (this->y < b.y)
		return true;
	else if (this->y > b.y)
		return false;
	else if (this->m < b.m)
		return true;
	else if (this->m > b.y)
		return false;
	else if (this->d < b.d)
		return true;
	else return false;
}
string Date::toString() {
	string s(to_string(Date::d)+'/'+ to_string(Date::m)+'/'+ to_string(Date::y));
	return s;
};
