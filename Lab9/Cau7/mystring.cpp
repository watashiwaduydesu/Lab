#include "mystring.h"

using namespace std;
MyString::MyString(char* x) {
	MyString::m_pchar = x;
};
MyString::MyString() :m_pchar("") {};

MyString& MyString::operator=(char* c)
{
	MyString::m_pchar = c;
	return *this;
}

MyString& MyString::operator=(MyString& x) {
	MyString::m_pchar = x.m_pchar;
	return *this;
};

ostream& operator<<(ostream& os, MyString x) {
	os << x.m_pchar;
	return os;
};

istream& operator>>(istream& is, MyString x) {
	is >> x.m_pchar;
	return is;
};
//Not done yet
MyString& MyString::operator+(MyString& x) {
	MyString res;
	strcpy_s(res.m_pchar, 50,MyString::m_pchar);
	strcat_s(res.m_pchar, 50, x.m_pchar);
	return res;
};
