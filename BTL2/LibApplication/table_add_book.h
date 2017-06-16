#ifndef TABLE_ADD_BOOK_H
#define TABLE_ADD_BOOK_H

#include "mytable.h"
#include "library_ui.h"

class table_add_book: public MyTable
{
    Q_OBJECT
public:
    table_add_book(QWidget *parent = 0);

private:
    QPushButton *btn_add, *btn_del, *btn_upd;
    void setUI();
    void setListener();

public slots:
    void update_data();
};

#endif // TABLE_ADD_BOOK_H
