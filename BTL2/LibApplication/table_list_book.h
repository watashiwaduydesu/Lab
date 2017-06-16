#ifndef TABLE_LIST_BOOK_H
#define TABLE_LIST_BOOK_H

#include "mytable.h"
#include <QPushButton>

class table_list_book: public MyTable
{
    Q_OBJECT
public:
    table_list_book(QWidget *parent = 0);

private:
    void setUI();
    void setListener();

    QPushButton *btn_refresh;

public slots:
    void editBook();
    void onClick_btn_refresh();
};

#endif // TABLE_LIST_BOOK_H
