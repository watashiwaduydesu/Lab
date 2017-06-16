#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "library.h"
#include "macro.h"
#include "book.h"

using namespace std;

class account
{
protected:
    string code, name, email, id, username, tel;
    int password, role, state;
    int day, month, year;

public:
    account() {}
    account(string name_, int password_, string email_, string id_, string username_, string tel_,
            int day_, int month_, int year_, int role_ = USER, int state_ = ACTIVE, string code_ = ID_NULL)
        : name(name_), password(password_), email(email_), id(id_), username(username_), tel(tel_),
          day(day_), month(month_), year(year_), role(role_), state(state_), code(code_)
    {}

    bool operator == (const account &o) {return code == o.code;}

    string getCode() const {return code;}
    string getName() const {return name;}
    string getEmail() const {return email;}
    string getID() const {return id;}
    string getUsername() const {return username;}
    string getTel() const {return tel;}
    QDate getBirthDate() const {return QDate(year, month, day);}
    int getDay() const {return day;}
    int getMonth() const {return month;}
    int getYear() const {return year;}
    int getRole() const {return role;}
    int getState() const {return state;}
    int getPassword() const {return password;}
    bool isActive() const {return state == ACTIVE;}
    bool isDisabled() const {return state == LOCKED_ACCOUNT;}

    // ham kiem tra mat khau co khop khong (mat khau da duoc ma hoa bang hash)
    bool checkPassword(int password_) {return password == password_;}
    void changePassword(int new_password) {password = new_password;}

    book& findBook(string code_book); // tim sach (theo ma code) trong he thong
    vector<book> findBook_code(string code_book); // size = 0 (khong tim thay) || 1 (tim thay)

    // cac ham tim kiem sach theo name, author, information
    // su dung ham Z + BST co do uu tien, do chinh xac tuong doi
    // tra ve danh sach vector
    vector<book> findBook_name(string name_book);
    vector<book> findBook_author(string author);
    vector<book> findBook_information(string information);

public:
    static int findAccount_name(string name_, account &res, int password_);

private:

    friend class data;
    friend class user;
    friend class librarian;
    friend class admin;
};

#endif // ACCOUNT_H
