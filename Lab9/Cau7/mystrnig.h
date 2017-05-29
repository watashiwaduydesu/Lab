#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <string.h>
using namespace std;
class MyString {
private:
	char* m_pchar;
public:
	MyString();
	MyString(char*);
	MyString& operator=(char*);
	MyString& operator=(MyString&);
	MyString& operator+(MyString&);
	friend ostream& operator<<(ostream&, MyString);
	friend istream& operator >> (istream&, MyString);
	MyString operator+=(MyString);
};


#endif
