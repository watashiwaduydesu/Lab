#ifndef USER_H
#define USER_H

#include "library.h"
#include "macro.h"
#include "account.h"
#include "book.h"

using namespace std;

class user : public account
{
    friend class user_book;

public:
    user() {role = USER;}
    user(const account &o) {
        code = o.code; name = o.name; password = o.password; email = o.email; id = o.id; tel = o.tel;
        username = o.username; day = o.day; month = o.month; year = o.year; role = USER;
    }

    int requireBook(string code_book, QDate begin_date, QDate end_date);
};

#endif // USER_H
