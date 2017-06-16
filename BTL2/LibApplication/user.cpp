#include "user.h"
#include "external.h"

int user::requireBook(string code_book, QDate begin_date, QDate end_date) {
    vector<book> l_bk = findBook_code(code_book);
    if (l_bk.size() == 0) return NOT_FIND;
    book bk = l_bk[0];
    if (bk.getRemain() == 0) return FALSE;
    l_user_require_book.push_back(user_book(*this, bk, begin_date, end_date));
    return SUCCESS;
}
