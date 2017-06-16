#include "external.h"

account main_account;
user main_user;
librarian main_lib;
admin main_admin;

vector<account> l_account, l_account_require;
vector<book> l_book;
vector<user_book> l_user_book, l_user_require_book;
int ID_account = 0, ID_book = 0;

// ------------------------------------------------------

int hashPassword(string password) {
    long long value = 0ll, MOD = 1000000009ll;
    for (int i = 0; i < (int) password.size(); ++i) {
        value = (value * 307 + password[i]) % MOD;
    }
    return (int) value;
}

bool checkPassword(string password, int value) {
    return (hashPassword(password) == value);
}

// ------------------------------------------------------

void updatePasswordMainAccount(int password_new) {
    main_account.changePassword(password_new);
    for (int i = 0; i < (int) l_account.size(); ++i) {
        if (l_account[i].getCode() == main_account.getCode()) {
            l_account[i].changePassword(password_new);
            return;
        }
    }
}

// -------------------------------------------------------

string allocateIDAccount() {
    ++ID_account;
    stringstream ss;
    ss << "IDA" << setw(7) << setfill('0') << ID_account;
    return ss.str();
}

string allocateIDBook() {
    ++ID_book;
    stringstream ss;
    ss << "IDB" << setw(7) << setfill('0') << ID_book;
    return ss.str();
}

// ------------------------------------------------------
void z_function(string pattern, string text, int &match_length, int &match_number) {
    string s = pattern + "#" + text;
    for (int i = 0; i < s.size(); ++i) {
        if ('A' <= s[i] && s[i] <= 'Z') s[i] += 'a' - 'A';
    }
    vector<int> z = z_function(s);
    match_length = match_number = 0;
    int p = (int) pattern.size();
    for (int i = 1; i <= text.size(); ++i) {
        match_length = max(match_length, z[p+i]);
        if (z[p+i] > (p+1)/2) match_number++;
    }
}

vector<int> z_function(string s) {
    int n = (int) s.size(), l = 0, r = 0;
    vector<int> z(n);
    for (int i = 0; i < n; ++i) {
        if (i <= r) z[i] = min(z[i-l], r-i+1);
        while (i+z[i] < n && s[i+z[i]] == s[z[i]]) z[i]++;
        if (i+z[i]-1 > r) {
            l = i; r = i+z[i]-1;
        }
    }
    return z;
}

// ------------------------------------------------------

int findAccount(string code_, account &res) {
    for (account a : l_account) {
        if (a.getCode() == code_) {
            res = a;
            return TRUE;
        }
    }
    return NOT_FIND;
}

int findBook(string code, book &found_book) {
    for (book bk : l_book) {
        if (bk.getCode() == code) {
            found_book = bk;
            return TRUE;
        }
    }
    return NOT_FIND;
}

