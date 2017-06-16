#include "table_list_require.h"
#include "external.h"
#include "user.h"
#include "book.h"
#include "user_book.h"
#include <QLabel>
#include "macro.h"
#include "library_ui.h"

table_list_require::table_list_require(QWidget *parent): MyTable(parent)
{
    this->setUI();
    this->setListener();
}

void table_list_require::setUI()
{
    int row = (int) l_user_require_book.size(), col = 7;
    this->table->setRowCount(row);
    this->table->setColumnCount(col);

    this->table->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("ID TÀI KHOẢN")));
    this->table->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("TÊN TÀI KHOẢN")));
    this->table->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("ID SÁCH")));
    this->table->setHorizontalHeaderItem(3, new QTableWidgetItem(tr("TÊN SÁCH")));
    this->table->setHorizontalHeaderItem(4, new QTableWidgetItem(tr("HIỆN CÓ")));
    this->table->setHorizontalHeaderItem(5, new QTableWidgetItem(tr("NGÀY MƯỢN")));
    this->table->setHorizontalHeaderItem(6, new QTableWidgetItem(tr("NGÀY TRẢ")));
    this->table->setColumnWidth(0,120);
    this->table->setColumnWidth(1,130);
    this->table->setColumnWidth(2,100);
    this->table->setColumnWidth(3,250);
    this->table->setColumnWidth(4,80);
    this->table->setColumnWidth(5,110);
    this->table->setColumnWidth(6,110);

    for (int i = 0; i < row; ++i) {
        user_book p = l_user_require_book[i];

        this->table->setItem(i, 0, new QTableWidgetItem(tr(p.getUser().getCode().c_str())));
        this->table->setItem(i, 1, new QTableWidgetItem(tr(p.getUser().getName().c_str())));
        this->table->setItem(i, 2, new QTableWidgetItem(tr(p.getBook().getCode().c_str())));
        this->table->setItem(i, 3, new QTableWidgetItem(tr(p.getBook().getName().c_str())));
        this->table->setItem(i, 4, new QTableWidgetItem(tr(std::to_string(p.getBook().getRemain()).c_str())));
        this->table->setItem(i, 5, new QTableWidgetItem(p.getDateBegin().toString("dd/MM/yyyy")));
        this->table->setItem(i, 6, new QTableWidgetItem(p.getDateEnd().toString("dd/MM/yyyy")));
    }

    QLabel *hd = new QLabel(tr("Nhấp hai lần để xử lí yêu cầu"));
    hd->setFont(FONT_SIZE_NORMAL);
    this->main_layout->addWidget(hd);
}

void table_list_require::setListener()
{
    connect(this->table, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(onDoubleClick_row_table()));
}

void table_list_require::onDoubleClick_row_table()
{
    QMessageBox *message = new QMessageBox();
    message->setWindowTitle("Xác nhận yêu cầu mượn sách");
    message->setText("Bạn có đồng ý yêu cầu này từ người dùng ?");
    message->setFont(FONT_SIZE_NORMAL);
    message->setContentsMargins(20, 20, 20, 20);
    message->setIcon(QMessageBox::Question);
    message->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel | QMessageBox::Close);
    message->setButtonText(QMessageBox::Ok, "Đồng ý");
    message->setButtonText(QMessageBox::Cancel, "Hủy yêu cầu");
    message->setButtonText(QMessageBox::Close, "Trở về");
    message->setDefaultButton(QMessageBox::Close);

    int row = this->table->currentRow();

    int res = message->exec();
    switch (res)
    {
    case QMessageBox::Ok:
        main_lib.acceptRequireBook(table->item(row, 0)->text().toStdString(),
                                   table->item(row, 2)->text().toStdString());

        this->table->removeRow(this->table->currentRow());
        break;

    case QMessageBox::Cancel:
        main_lib.rejectRequireBook(table->item(row, 0)->text().toStdString(),
                                   table->item(row, 2)->text().toStdString());

        this->table->removeRow(this->table->currentRow());
        break;

    case QMessageBox::Close:
        break;
    }
}
