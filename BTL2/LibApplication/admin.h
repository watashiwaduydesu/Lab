#ifndef ADMIN_H
#define ADMIN_H

#include "library.h"
#include "macro.h"
#include "librarian.h"
#include "user.h"
#include "account.h"
#include "book.h"

using namespace std;

class admin : public librarian
{
public:
    admin() {role = ADMIN;}
    admin(const account &o) {
        code = o.code; name = o.name; password = o.password; email = o.email; id = o.id; tel = o.tel;
        username = o.username; day = o.day; month = o.month; year = o.year; role = ADMIN;
    }

    void addAccount(account &acc);
    int deleteAccount(string code);
    int deleteAccount(account &acc);
    int deleteAccountRequire(account &acc);

    void acceptRequireSignUp(account acc);
    void rejectRequireSignUp(account acc);

    void lockAccount(account &acc) {acc.state = DISABLED;}
    void unlockAccount(account &acc) {acc.state = ACTIVE;}

    void editAccount(account &acc, account &new_acc) {acc = new_acc;}
    int editAccount(string code, account &new_acc);

    int findAccount_code(string code_, account &found_account);
    int findAccount_name(string name_, account &found_account);
    // tra ve TRUE neu tim thay, found_account la gia tri tra ve
    // tra ve FALSE neu khong tim thay
};

#endif // ADMIN_H
