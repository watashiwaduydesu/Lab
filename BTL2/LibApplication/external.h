#ifndef EXTERNAL_H
#define EXTERNAL_H

#include "library.h"
#include "macro.h"
#include "account.h"
#include "user.h"
#include "librarian.h"
#include "admin.h"
#include "book.h"
#include "user_book.h"

// nguoi dung chinh sau khi dang nhap thanh cong
// tuy theo loai nguoi dung ma tao cac user librarian va admin tuong ung
extern account main_account;
extern user main_user;
extern librarian main_lib;
extern admin main_admin;

// danh sach cac thong tin quan ly
extern vector<account> l_account, l_account_require;
extern vector<book> l_book;
extern vector<user_book> l_user_book, l_user_require_book;

// xu ly mat khau nguoi dung
extern int hashPassword(string password);
extern bool checkPassword(string password, int value);
extern void updatePasswordMainAccount(int password_new);

// cap phat ma id (code) cho nguoi dung cung nhu sach
extern int ID_account, ID_book;
extern string allocateIDAccount();
extern string allocateIDBook();

// ham Z xu ly tim kiem chuoi (tim sach, ten nguoi dung) (tim prefix)
extern void z_function(string pattern, string text, int &match_length, int &match_number);
extern vector<int> z_function(string s);

// cac ham khac (chua biet co dung hay khong)
extern int findBook(string code, book &found_book);
extern int findAccount(string code, account &found_account);

#endif // EXTERNAL_H
