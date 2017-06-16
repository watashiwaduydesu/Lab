#include "table_list_book.h"
#include "external.h"
#include "macro.h"
#include <QLabel>
#include "edit_book_activity.h"
#include <QDebug>

table_list_book::table_list_book(QWidget *parent): MyTable(parent)
{
    this->setUI();
    this->setListener();
}

void table_list_book::setUI()
{
    int row = (int) l_book.size(), col = 4;
    this->table->setRowCount(row);
    this->table->setColumnCount(col);

    this->table->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("ID.")));
    this->table->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("TÊN SÁCH")));
    this->table->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("TÁC GIẢ")));
    this->table->setHorizontalHeaderItem(3, new QTableWidgetItem(tr("SỐ LƯỢNG")));
    this->table->setColumnWidth(1,400);
    this->table->setColumnWidth(2,300);

    for (int i = 0; i < row; ++i) {
        this->table->setItem(i, 0, new QTableWidgetItem(tr(l_book[i].getCode().c_str())));
        this->table->setItem(i, 1, new QTableWidgetItem(tr(l_book[i].getName().c_str())));
        this->table->setItem(i, 2, new QTableWidgetItem(tr(l_book[i].getAuthor().c_str())));
        this->table->setItem(i, 3, new QTableWidgetItem(tr(std::to_string(l_book[i].getRemain()).c_str())));
    }

    QHBoxLayout *lay = new QHBoxLayout();
    QLabel *hd = new QLabel(tr("Nhấp chuột hai lần để chỉnh sửa thông tin sách\n"
                               "Nhấn nút Refersh để tải lại phiên bản mới nhất"));
    hd->setFont(FONT_SIZE_NORMAL);
    btn_refresh = new QPushButton("Refresh");
    btn_refresh->setFont(FONT_SIZE_NORMAL);
    btn_refresh->setContentsMargins(10,5,10,5);
    lay->addWidget(hd);
    lay->addStretch(1);
    lay->addWidget(btn_refresh);

    this->main_layout->addLayout(lay);
}

void table_list_book::setListener()
{
    connect(this->table, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(editBook()));
    connect(btn_refresh, SIGNAL(clicked(bool)), this, SLOT(onClick_btn_refresh()));
}

void table_list_book::editBook()
{
    int index = this->table->currentRow();
    int err = index >= (int) l_book.size();
    if (!err) {
        string code_row = this->table->item(index, 0)->text().toStdString();
        err = code_row != l_book[index].getCode();
    }
    if (err) {
        QMessageBox *message = new QMessageBox();
        message->setWindowTitle("Thông báo");
        message->setText("Sách này không còn trong hệ thống!\n"
                         "Yêu cầu nhấn nút Refresh để xem phiên bản mới nhất");
        message->setFont(FONT_SIZE_NORMAL);
        message->setContentsMargins(20, 20, 20, 20);
        message->exec();
    }
    else {
        edit_book_activity *editBook = new edit_book_activity(l_book[index]);
        editBook->show();
    }
}

void table_list_book::onClick_btn_refresh()
{
    int row = (int) l_book.size();
    this->table->setRowCount(row);
    for (int i = 0; i < row; ++i) {
        this->table->setItem(i, 0, new QTableWidgetItem(tr(l_book[i].getCode().c_str())));
        this->table->setItem(i, 1, new QTableWidgetItem(tr(l_book[i].getName().c_str())));
        this->table->setItem(i, 2, new QTableWidgetItem(tr(l_book[i].getAuthor().c_str())));
        this->table->setItem(i, 3, new QTableWidgetItem(tr(std::to_string(l_book[i].getRemain()).c_str())));
    }
}
