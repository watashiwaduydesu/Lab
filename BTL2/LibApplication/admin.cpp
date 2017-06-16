#include "admin.h"
#include "external.h"
#include <QDebug>

void admin::addAccount(account &acc) {
    l_account.push_back(acc);
}

int admin::deleteAccount(string code) {
    if (code == ID_NULL) return ERROR;
    for (int i = 0; i < (int) l_account.size(); ++i) {
        if (l_account[i].getCode() == code) {
            l_account[i] = l_account[(int) l_account.size()-1];
            l_account.pop_back();
            return TRUE;
        }
    }
    return FALSE;
}

int admin::deleteAccount(account &acc) {
    if (code == ID_NULL) return ERROR;
    for (int i = 0; i < (int) l_account.size(); ++i) {
        if (l_account[i] == acc) {
            l_account[i] = l_account[(int) l_account.size()-1];
            l_account.pop_back();
            return TRUE;
        }
    }
    return FALSE;
}

int admin::deleteAccountRequire(account &acc) {
    int sz = (int) l_account_require.size();
    for (int i = 0; i < sz; ++i) {
        if (l_account_require[i].getName() == acc.getName()) {
            l_account_require[i] = l_account_require[sz-1];
            l_account_require.pop_back();
            return TRUE;
        }
    }
    return FALSE;
}

void admin::acceptRequireSignUp(account acc) {
    deleteAccountRequire(acc);
    acc.code = allocateIDAccount();
    addAccount(acc);
}

void admin::rejectRequireSignUp(account acc) {
    deleteAccountRequire(acc);
}

int admin::editAccount(string code, account &new_acc) {
    for (int pos = 0; pos < l_account.size(); ++pos) {
        if (code == l_account[pos].getCode()) {
            l_account[pos] = new_acc;
            return TRUE;
        }
    }
    return FALSE;
}

int admin::findAccount_code(string code_, account &found_account) {
    for (int pos = 0; pos < l_account.size(); ++pos) {
        if (code_ == l_account[pos].getCode()) {
            found_account = l_account[pos];
            return TRUE;
        }
    }
    return FALSE;
}

int admin::findAccount_name(string name_, account &found_account) {
    for (int pos = 0; pos < l_account.size(); ++pos) {
        if (name_ == l_account[pos].getName()) {
            found_account = l_account[pos];
            return TRUE;
        }
    }
    return FALSE;
}
