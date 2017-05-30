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
MyString& MyString::operator+(MyString& x) {
	size_t t = strlen(MyString::m_pchar)+strlen(x.m_pchar);
	char * res_char= new char[t];
	MyString* res = new MyString(res_char);
	strcpy_s(res->m_pchar,t+1,this->m_pchar);
	strcat_s(res->m_pchar, t + 1, x.m_pchar);
	return *res;
	delete res_char;
};
MyString& MyString::operator+(const char* x) {
	size_t t = strlen(MyString::m_pchar) + strlen(x);
	char * res_char = new char[t];
	MyString* res = new MyString(res_char);
	strcpy_s(res->m_pchar, t + 1, this->m_pchar);
	strcat_s(res->m_pchar, t + 1, x);
	return *res;
	delete res_char;
};
