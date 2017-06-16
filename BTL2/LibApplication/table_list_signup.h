#ifndef TABLE_LIST_SIGNUP_H
#define TABLE_LIST_SIGNUP_H

#include "mytable.h"
#include <QPushButton>

class table_list_signup : public MyTable
{
    Q_OBJECT
public:
    explicit table_list_signup(QWidget *parent = 0);

private:
    void setUI();
    void setListener();
    void refershList();

public slots:
    void onDoubleClick_row_table();
};

#endif // TABLE_LIST_SIGNUP_H
