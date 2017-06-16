#include "table_list_account.h"
#include "external.h"
#include <QLabel>
#include "macro.h"
#include "edit_account_activity.h"

table_list_account::table_list_account(QWidget *parent): MyTable(parent)
{
    this->setUI();
    this->setListener();
}

void table_list_account::setUI()
{
    int row = (int) l_account.size(), col = 5;
    this->table->setRowCount(row);
    this->table->setColumnCount(col);

    this->table->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("ID.")));
    this->table->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("TÊN TÀI KHOẢN")));
    this->table->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("TÊN NGƯỜI DÙNG")));
    this->table->setHorizontalHeaderItem(3, new QTableWidgetItem(tr("LOẠI TÀI KHOẢN")));
    this->table->setHorizontalHeaderItem(4, new QTableWidgetItem(tr("TÌNH TRẠNG")));
    this->table->setColumnWidth(1,200);
    this->table->setColumnWidth(2,300);
    this->table->setColumnWidth(3,200);
    this->table->setColumnWidth(4,150);

    this->refershList();

    QHBoxLayout *lay = new QHBoxLayout();
    QLabel *hd = new QLabel(tr("Nhấp hai lần để chỉnh sửa thông tin tài khoản\n"
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

void table_list_account::setListener()
{
    connect(this->table, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(editAccount()));
    connect(btn_refresh, SIGNAL(clicked(bool)), this, SLOT(onClick_btn_refresh()));
}

void table_list_account::refershList()
{
    int row = (int) l_account.size();
    this->table->setRowCount(row);

    for (int i = 0; i < row; ++i) {
        this->table->setItem(i, 0, new QTableWidgetItem(tr(l_account[i].getCode().c_str())));
        this->table->setItem(i, 1, new QTableWidgetItem(tr(l_account[i].getName().c_str())));
        this->table->setItem(i, 2, new QTableWidgetItem(tr(l_account[i].getUsername().c_str())));

        int role = l_account[i].getRole();
        if (role == USER) this->table->setItem(i, 3, new QTableWidgetItem(tr("Người dùng")));
        else if (role == LIBRARIAN) this->table->setItem(i, 3, new QTableWidgetItem(tr("Thủ thư")));
        else if (role == ADMIN) this->table->setItem(i, 3, new QTableWidgetItem(tr("Quản trị")));
        else this->table->setItem(i, 3, new QTableWidgetItem(tr("Lỗi hệ thống")));

        int state = l_account[i].getState();
        if (state == ACTIVE) this->table->setItem(i, 4, new QTableWidgetItem(tr("Mở")));
        else if (state == DISABLED) this->table->setItem(i, 4, new QTableWidgetItem(tr("Khóa")));
        else this->table->setItem(i, 4, new QTableWidgetItem(tr("Lỗi hệ thống")));
    }
}

void table_list_account::editAccount()
{
    int index = this->table->currentRow();
    int err = index >= (int) l_account.size();
    if (!err) {
        string code_row = this->table->item(index, 0)->text().toStdString();
        err = code_row != l_account[index].getCode();
    }
    if (err) {
        QMessageBox *message = new QMessageBox();
        message->setWindowTitle("Thông báo");
        message->setText("Tài khoản này đã được xóa khỏi hệ thống!\n"
                         "Yêu cầu nhấn nút Refresh để xem phiên bản mới nhất");
        message->setFont(FONT_SIZE_NORMAL);
        message->setContentsMargins(20, 20, 20, 20);
        message->exec();
    }
    else {
        edit_account_activity *editACC = new edit_account_activity(l_account[index]);
        editACC->show();
    }
}

void table_list_account::onClick_btn_refresh()
{
    this->refershList();
}
