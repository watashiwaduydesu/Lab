#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "library.h"
#include "macro.h"
#include "account.h"
#include "book.h"

using namespace std;

class librarian : public account
{
public:
    librarian() {role = LIBRARIAN;}
    librarian(const account &o) {
        code = o.code; name = o.name; password = o.password; email = o.email; id = o.id; tel = o.tel;
        username = o.username; day = o.day; month = o.month; year = o.year; role = LIBRARIAN;
    }

    void addBook(book &bk, int number = 1);

    int eraseBook(book &bk, int number = 1); // xoa so luong sach
    int eraseBook(string code, int number = 1); // xoa sach co ma la code

    int removeBook(string code); // loai sach co ma code khoi he thong
    int removeBook(book &bk); // loai sach khoi he thong

    int acceptRequireBook(string user_code, string book_code); // dong y yeu cau muon sach
    int rejectRequireBook(string user_code, string book_code); // huy yeu cau muon sach

    void editBook_name(book &bk, string new_name) {bk.name = new_name;}
    void editBook_author(book &bk, string new_author) {bk.author = new_author;}
    void editBook_information(book &bk, string new_information) {bk.information = new_information;}
    void editBook_remain_number(book &bk, int new_number) {bk.remain_number = new_number;}

    void editBook(book &bk, string new_name, string new_author, string new_information, int new_number) {
        bk.name = new_name;
        bk.author = new_author;
        bk.information = new_information;
        bk.remain_number = new_number;
    }
};

#endif // LIBRARIAN_H
