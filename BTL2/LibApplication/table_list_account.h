#ifndef TABLE_LIST_ACCOUNT_H
#define TABLE_LIST_ACCOUNT_H

#include "mytable.h"
#include <QPushButton>

class table_list_account: public MyTable
{
    Q_OBJECT
public:
    table_list_account(QWidget *parent = 0);

private:
    void setUI();
    void setListener();
    void refershList();

    QPushButton *btn_refresh;

public slots:
    void editAccount();
    void onClick_btn_refresh();
};

#endif // TABLE_LIST_ACCOUNT_H
