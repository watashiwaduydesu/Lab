#ifndef TABLE_LIST_REQUIRE_H
#define TABLE_LIST_REQUIRE_H

#include "mytable.h"
#include <QPushButton>

class table_list_require: public MyTable
{
    Q_OBJECT
public:
    table_list_require(QWidget *parent = 0);

private:
    void setUI();
    void setListener();

public slots:
    void onDoubleClick_row_table();
};

#endif // TABLE_LIST_REQUIRE_H
