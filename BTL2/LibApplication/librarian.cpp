#include "librarian.h"
#include "external.h"

void librarian::addBook(book &bk, int number)
{
    if (bk.getCode() == ID_NULL) {
        bk.code = "12312";
        bk.remain_number = number;
        l_book.push_back(bk);
    }
    else {
        for (int i = 0; i < (int) l_book.size(); i++) {
            if (l_book[i].getCode() == bk.getCode()) {
                l_book[i].remain_number += number;
                break;
            }
        }
    }
}

int librarian::eraseBook(book &bk, int number)
{
    if (bk.getCode() == ID_NULL) return ERROR;
    if (bk.remain_number < number) return ERROR;
    bk.remain_number -= number;
    return TRUE;
}

int librarian::eraseBook(string code, int number)
{
    book &bk = this->findBook(code);
    if (bk.getCode() == ID_NULL) return NOT_FIND;
    this->eraseBook(bk, number);
    return TRUE;
}

int librarian::removeBook(string code)
{
    if (code == ID_NULL) return ERROR;
    int sz = (int) l_book.size();
    for (int i = 0; i < sz; ++i) {
        if (l_book[i].getCode() == code) {
            l_book[i] = l_book[sz-1];
            l_book.pop_back();
            return TRUE;
        }
    }
    return FALSE;
}

int librarian::removeBook(book &bk)
{
    return this->removeBook(bk.getCode());
}

int librarian::acceptRequireBook(string user_code, string book_code)
{
    int sz = (int) l_user_require_book.size();
    for (int i = 0; i < sz; i++)
        if (l_user_require_book[i].getUser().getCode() == user_code
                && l_user_require_book[i].getBook().getCode() == book_code)
        {
            l_user_require_book[i] = l_user_require_book[sz-1];
            l_user_require_book.pop_back();

            return TRUE;
        }

    this->eraseBook(book_code);
    return NOT_FIND;
}

int librarian::rejectRequireBook(string user_code, string book_code)
{
    int sz = (int) l_user_require_book.size();
    for (int i = 0; i < sz; i++)
        if (l_user_require_book[i].getUser().getCode() == user_code
                && l_user_require_book[i].getBook().getCode() == book_code)
        {
            l_user_book.push_back(l_user_require_book[i]);
            l_user_require_book[i] = l_user_require_book[sz-1];
            l_user_require_book.pop_back();
            return TRUE;
        }
    return NOT_FIND;
}
