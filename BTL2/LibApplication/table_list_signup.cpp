#include "table_list_signup.h"
#include "external.h"
#include "macro.h"
#include "library_ui.h"
#include "account.h"
#include <QDebug>

table_list_signup::table_list_signup(QWidget *parent) : MyTable(parent)
{
    this->setUI();
    this->setListener();
}

void table_list_signup::setUI()
{
    int row = (int) l_account_require.size(), col = 6;
    this->table->setRowCount(row);
    this->table->setColumnCount(col);

    this->table->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("TÊN TÀI KHOẢN")));
    this->table->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("ĐỊA CHỈ EMAIL")));
    this->table->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("CMND")));
    this->table->setHorizontalHeaderItem(3, new QTableWidgetItem(tr("TÊN NGƯỜI DÙNG")));
    this->table->setHorizontalHeaderItem(4, new QTableWidgetItem(tr("ĐIỆN THOẠI")));
    this->table->setHorizontalHeaderItem(5, new QTableWidgetItem(tr("NGÀY SINH")));
    this->table->setColumnWidth(0,200);
    this->table->setColumnWidth(1,250);
    this->table->setColumnWidth(2,130);
    this->table->setColumnWidth(3,200);
    this->table->setColumnWidth(4,120);
    this->table->setColumnWidth(5,120);

    this->refershList();

    QLabel *hd = new QLabel(tr("Nhấp chuột hai lần để xác nhận tài khoản được đăng kí"));
    hd->setFont(FONT_SIZE_NORMAL);
    this->main_layout->addWidget(hd);
}

void table_list_signup::setListener()
{
    connect(this->table, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(onDoubleClick_row_table()));
}

void table_list_signup::refershList()
{
    int row = (int) l_account_require.size();
    this->table->setRowCount(row);

    for (int i = 0; i < row; ++i) {
        account p = l_account_require[i];

        this->table->setItem(i, 0, new QTableWidgetItem(tr(p.getName().c_str())));
        this->table->setItem(i, 1, new QTableWidgetItem(tr(p.getEmail().c_str())));
        this->table->setItem(i, 2, new QTableWidgetItem(tr(p.getID().c_str())));
        this->table->setItem(i, 3, new QTableWidgetItem(tr(p.getUsername().c_str())));
        this->table->setItem(i, 4, new QTableWidgetItem(tr(p.getTel().c_str())));
        this->table->setItem(i, 5, new QTableWidgetItem(p.getBirthDate().toString("dd/MM/yyyy")));
    }
}

void table_list_signup::onDoubleClick_row_table()
{
    int row = this->table->currentRow();
    qDebug() << row;

    QMessageBox *message = new QMessageBox();
    message->setWindowTitle("Xác nhận đăng kí tài khoản");
    QString text = "Tài khoản đăng kí mới: ";
    text.append(tr(l_account_require[row].getName().c_str()));
    text.append("\nBạn đồng ý xác nhận tài khoản mới này vào hệ thống ?");
    message->setText(text);
    message->setFont(FONT_SIZE_NORMAL);
    message->setContentsMargins(20, 20, 20, 20);
    message->setIcon(QMessageBox::Question);
    message->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel | QMessageBox::Close);
    message->setButtonText(QMessageBox::Ok, "Đồng ý");
    message->setButtonText(QMessageBox::Cancel, "Hủy yêu cầu");
    message->setButtonText(QMessageBox::Close, "Trở về");
    message->setDefaultButton(QMessageBox::Close);

    int n = (int) l_account_require.size(), i = 0;
    for (i = 0 ; i < n ; i++)
        if (this->table->item(row,0)->text().toStdString() == l_account_require[i].getName())
            break;
    qDebug() << i;

    int res = message->exec();
    switch (res)
    {
    case QMessageBox::Ok:
        main_admin.acceptRequireSignUp(l_account_require[i]);
        this->refershList();
        break;

    case QMessageBox::Cancel:
        main_admin.rejectRequireSignUp(l_account_require[i]);
        this->refershList();
        break;

    case QMessageBox::Close:
        break;
    }
}
