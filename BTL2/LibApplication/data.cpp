#include "data.h"

int data::loadDataAccount() {
    ifstream f(FILE_ACCOUNT);
    if (! f.is_open()) return NOT_ACCESS_FILE;
    f >> ID_account;
    int n = 0;
    f >> n;
    for (int i = 0; i < n; ++i) {
        account a;
        f >> a.code >> a.name >> a.password >> a.email >> a.id;
        f.get();
        getline(f, a.username);
        f >> a.tel >> a.day >> a.month >> a.year >> a.role >> a.state;
        l_account.push_back(a);
    }
    f.close();
    return TRUE;
}

int data::storageDataAccount() {
    ofstream f(FILE_ACCOUNT);
    if (! f.is_open()) return NOT_ACCESS_FILE;
    f << ID_account << endl;
    f << l_account.size() << endl;
    for (account a: l_account) {
        f << a.code << endl << a.name << endl << a.password << endl;
        f << a.email << endl << a.id << endl << a.username << endl << a.tel << endl;
        f << a.day << " " << a.month << " " << a.year << endl << a.role << endl << a.state << endl;
    }
    f.close();
    return TRUE;
}


int data::loadDataAccountRequire() {
    ifstream f(FILE_ACCOUNT_REQUIRE);
    if (! f.is_open()) return NOT_ACCESS_FILE;
    int n = 0;
    f >> n;
    for (int i = 0; i < n; ++i) {
        account a;
        f >> a.name >> a.password >> a.email >> a.id;
        f.get();
        getline(f, a.username);
        f >> a.tel >> a.day >> a.month >> a.year;
        l_account_require.push_back(a);
    }
    f.close();
    return TRUE;
}

int data::storageDataAccountRequire() {
    ofstream f(FILE_ACCOUNT_REQUIRE);
    if (! f.is_open()) return NOT_ACCESS_FILE;
    f << l_account_require.size() << endl;
    for (account a: l_account_require) {
        f << a.name << endl << a.password << endl;
        f << a.email << endl << a.id << endl << a.username << endl << a.tel << endl;
        f << a.day << " " << a.month << " " << a.year << endl;
    }
    f.close();
    return TRUE;
}

int data::loadDataBook() {
    ifstream f(FILE_BOOK);
    if (! f.is_open()) return NOT_ACCESS_FILE;
    f >> ID_book;
    int n = 0;
    f >> n;
    for (int i = 0; i < n; ++i) {
        book a;
        f.get();
        getline(f, a.code);
        getline(f, a.name);
        getline(f, a.author);
        getline(f, a.information);
        f >> a.remain_number;
        l_book.push_back(a);
    }
    f.close();
    return TRUE;
}

int data::storageDataBook() {
    ofstream f(FILE_BOOK);
    if (! f.is_open()) return NOT_ACCESS_FILE;
    f << ID_book << endl;
    f << l_book.size() << endl;
    for (book a: l_book) {
        f << a.code << endl << a.name << endl << a.author << endl;
        f << a.information << endl << a.remain_number << endl;
    }
    f.close();
    return TRUE;
}

int data::loadDataUserBook() {
    ifstream f(FILE_USER_BOOK);
    if (! f.is_open()) return NOT_ACCESS_FILE;
    int n = 0;
    f >> n;
    for (int i = 0; i < n; ++i) {
        user_book a;
        string ida, idb;
        f >> ida >> idb;
        if (findAccount(ida, a.m_user) == NOT_FIND) return ERROR;
        if (findBook(idb, a.m_book) == NOT_FIND) return ERROR;
        int d, m, y;
        f >> d >> m >> y; a.setDateBegin(d, m, y);
        f >> d >> m >> y; a.setDateEnd(d, m, y);
        l_user_book.push_back(a);
    }
    f.close();
    return TRUE;
}

int data::storageDataUserBook() {
    ofstream f(FILE_USER_BOOK);
    if (! f.is_open()) return NOT_ACCESS_FILE;
    f << l_user_book.size() << endl;
    for (user_book a : l_user_book) {
        f << a.m_user.getCode() << " " << a.m_book.getCode() << endl;
        f << a.getDateBegin().day() << " " << a.getDateBegin().month() << " " << a.getDateBegin().year() << endl;
        f << a.getDateEnd().day() << " " << a.getDateEnd().month() << " " << a.getDateEnd().year() << endl;
    }
    f.close();
    return TRUE;
}

int data::loadDataUserRequireBook() {
    ifstream f(FILE_USER_REQUIRE_BOOK);
    if (! f.is_open()) return NOT_ACCESS_FILE;
    int n = 0;
    f >> n;
    for (int i = 0; i < n; ++i) {
        user_book a;
        string ida, idb;
        f >> ida >> idb;
        if (findAccount(ida, a.m_user) == NOT_FIND) return ERROR;
        if (findBook(idb, a.m_book) == NOT_FIND) return ERROR;
        int d, m, y;
        f >> d >> m >> y; a.setDateBegin(d, m, y);
        f >> d >> m >> y; a.setDateEnd(d, m, y);
        l_user_require_book.push_back(a);
    }
    f.close();
    return TRUE;
}

int data::storageDataUserRequireBook() {
    ofstream f(FILE_USER_REQUIRE_BOOK);
    if (! f.is_open()) return NOT_ACCESS_FILE;
    f << l_user_require_book.size() << endl;
    for (user_book a : l_user_require_book) {
        f << a.m_user.getCode() << " " << a.m_book.getCode() << endl;
        f << a.getDateBegin().day() << " " << a.getDateBegin().month() << " " << a.getDateBegin().year() << endl;
        f << a.getDateEnd().day() << " " << a.getDateEnd().month() << " " << a.getDateEnd().year() << endl;
    }
    f.close();
    return TRUE;
}
