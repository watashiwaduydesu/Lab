#ifndef BOOK_H
#define BOOK_H

#include "library.h"
#include "macro.h"

using namespace std;

class book
{
private:
    string code, name, author, information;
    int remain_number; // so sach con lai

public:
    book() {}
    book(string name_, string author_, string information_, int remain_number_, string code_ = ID_NULL)
        : name(name_), author(author_), information(information_), remain_number(remain_number_), code(code_)
    {
    }

    bool operator == (const book &o) {return code == o.code;}

    string getCode() const {return code;}
    string getName() const {return name;}
    string getAuthor() const {return author;}
    string getInformation() const {return information;}
    int getRemain() const {return remain_number;}

    // so chuoi trong tim kiem
    int match_length; // khop nhieu nhat
    int match_number; // so lan khop xap xi
    bool accept_match(int length) { // kiem tra du dieu kien de so sanh
        return match_length > length/2;
    }

private:

    friend class librarian;
    friend class admin;
    friend class user_book;
    friend class data;
};

#endif // BOOK_H
