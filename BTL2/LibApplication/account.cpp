#include "account.h"
#include "external.h"

book &account::findBook(string code_book)
{
    int i;
    for (i = 0; i < (int) l_book.size(); ++i)
        if (l_book[i].getCode() == code_book) break;
    return l_book[i];
}

vector<book> account::findBook_code(string code_book) {
    vector<book> res;
    for (book bk : l_book) {
        if (bk.getCode() == code_book)
            res.push_back(bk);
    }
    return res;
}

struct compareatorLevensteinDistance {
    // cau truc so sanh (comparator) hai quyen sach dua tren Levenstein Distance
    bool operator() (const book &bk1, const book &bk2) const {
        return bk1.match_length > bk2.match_length ||
                (bk1.match_length == bk2.match_length && bk1.match_number > bk2.match_number);
    }
};

vector<book> account::findBook_author(string author) {
    vector<book> res;
    // BST books (BST : Binary Search Tree)
    multiset<book, compareatorLevensteinDistance> st;
    for (book bk : l_book) {
        z_function(author, bk.getAuthor(), bk.match_length, bk.match_number);
        if (bk.accept_match((int) author.length())) st.insert(bk);
    }
    while (!st.empty()) {
        book bk = *st.begin();
        st.erase(st.begin());
        res.push_back(bk);
    }
    return res;
}

vector<book> account::findBook_name(string name) {
    vector<book> res;
    // BST books (BST : Binary Search Tree)
    multiset<book, compareatorLevensteinDistance> st;
    for (book bk : l_book) {
        z_function(name, bk.getName(), bk.match_length, bk.match_number);
        if (bk.accept_match((int) name.length())) st.insert(bk);
    }
    while (!st.empty()) {
        book bk = *st.begin();
        st.erase(st.begin());
        res.push_back(bk);
    }
    return res;
}

vector<book> account::findBook_information(string information) {
    vector<book> res;
    // BST books (BST : Binary Search Tree)
    multiset<book, compareatorLevensteinDistance> st;
    for (book bk : l_book) {
        string all_information = bk.getCode()+" "+bk.getName()+" "+bk.getAuthor()+" "+bk.getInformation();
        z_function(information, all_information, bk.match_length, bk.match_number);
        if (bk.accept_match((int) information.length())) st.insert(bk);
    }
    while (!st.empty()) {
        book bk = *st.begin();
        st.erase(st.begin());
        res.push_back(bk);
    }
    return res;
}

// ----------------------- static -------------------------

int account::findAccount_name(string name_, account &res, int password_) {
    for (account a : l_account) {
        if (a.getName() == name_) {
            if (a.checkPassword(password_)) {
                if (a.getState() == DISABLED) return LOCKED_ACCOUNT;
                res = a;
                return SUCCESS;
            }
            return WRONG_PASSWORD;
        }
    }
    return NOT_FIND;
}
