#ifndef DATA_H
#define DATA_H

#include "external.h"

using namespace std;

class data
        // lop data quan li du lieu cho toan bo chuong trinh
        // load du lieu tu file, storage du lieu xuong file
        // la friend cua cac lop account, book, user, ... nen co the lay thong tin private
{
public:
    static int loadData() { // ham load du lieu tu file
        loadDataAccount();
        loadDataAccountRequire();
        loadDataBook();
        loadDataUserBook();
        loadDataUserRequireBook();
        return TRUE;
    }

    static int storageData() { // ham luu du lieu xuong file
        storageDataAccount();
        storageDataAccountRequire();
        storageDataBook();
        storageDataUserBook();
        storageDataUserRequireBook();
        return TRUE;
    }

private:
    // cac ham thanh vien trien khai load va storage
    static int loadDataAccount();
    static int loadDataAccountRequire();
    static int loadDataBook();
    static int loadDataUserBook();
    static int loadDataUserRequireBook();

    static int storageDataAccount();
    static int storageDataAccountRequire();
    static int storageDataBook();
    static int storageDataUserBook();
    static int storageDataUserRequireBook();
};

#endif // DATA_H
