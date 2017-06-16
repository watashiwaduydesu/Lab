#include "table_list_userbook.h"
#include "external.h"
#include "user.h"
#include "book.h"
#include "user_book.h"
#include <QLabel>
#include "macro.h"

table_list_userbook::table_list_userbook(QWidget *parent): MyTable(parent)
{
    int row = (int) l_user_book.size(), col = 6;
    this->table->setRowCount(row);
    this->table->setColumnCount(col);

    this->table->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("ID TÀI KHOẢN")));
    this->table->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("TÊN TÀI KHOẢN")));
    this->table->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("ID SÁCH")));
    this->table->setHorizontalHeaderItem(3, new QTableWidgetItem(tr("TÊN SÁCH")));
    this->table->setHorizontalHeaderItem(4, new QTableWidgetItem(tr("NGÀY MƯỢN")));
    this->table->setHorizontalHeaderItem(5, new QTableWidgetItem(tr("NGÀY TRẢ")));
    this->table->setColumnWidth(0,120);
    this->table->setColumnWidth(1,150);
    this->table->setColumnWidth(2,120);
    this->table->setColumnWidth(3,300);
    this->table->setColumnWidth(4,110);
    this->table->setColumnWidth(5,110);

    for (int i = 0; i < row; ++i) {
        user_book p = l_user_book[i];

        this->table->setItem(i, 0, new QTableWidgetItem(tr(p.getUser().getCode().c_str())));
        this->table->setItem(i, 1, new QTableWidgetItem(tr(p.getUser().getName().c_str())));
        this->table->setItem(i, 2, new QTableWidgetItem(tr(p.getBook().getCode().c_str())));
        this->table->setItem(i, 3, new QTableWidgetItem(tr(p.getBook().getName().c_str())));
        this->table->setItem(i, 4, new QTableWidgetItem(p.getDateBegin().toString("dd/MM/yyyy")));
        this->table->setItem(i, 5, new QTableWidgetItem(p.getDateEnd().toString("dd/MM/yyyy")));
    }

    QLabel *hd = new QLabel(tr("Bạn chỉ có thể xem danh sách này"));
    hd->setFont(FONT_SIZE_NORMAL);
    this->main_layout->addWidget(hd);
}
