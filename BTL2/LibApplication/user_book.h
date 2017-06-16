#ifndef USER_BOOK_H
#define USER_BOOK_H

#include "library.h"
#include "user.h"
#include "book.h"

class user_book // lop quan li nguoi dung - muon sach
{
    friend class data;
private:
    user m_user;
    book m_book;
    QDate begin, end;

public:
    user_book() {}
    user_book(const user &user, const book &book) : m_user(user), m_book(book){}
    user_book(const user &user, const book &book, QDate st, QDate en) : user_book(user, book) {
        begin = st; end = en;
    }

    user getUser() {return m_user;}
    book getBook() {return m_book;}
    QDate getDateBegin() {return begin;}
    QDate getDateEnd() {return end;}

    void setDateBegin(QDate o) {begin = o;}
    void setDateBegin(int d, int m, int y) {
        begin.setDate(y, m, d);
    }

    void setDateEnd(QDate o) {end = o;}
    void setDateEnd(int d, int m, int y) {
        end.setDate(y, m, d);
    }
};

#endif // USER_BOOK_H
