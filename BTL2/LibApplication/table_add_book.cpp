#include "table_add_book.h"
#include "macro.h"
#include "library.h"
#include "external.h"

table_add_book::table_add_book(QWidget *parent): MyTable(parent)
{
    this->setUI();
    this->setListener();
}

void table_add_book::setUI()
{
    this->table->setEditTriggers(QAbstractItemView::AllEditTriggers);
    this->table->setSelectionBehavior(QAbstractItemView::SelectItems);

    this->table->setRowCount(5);
    this->table->setColumnCount(4);
    this->table->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("TÊN SÁCH")));
    this->table->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("TÁC GIẢ")));
    this->table->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("MÔ TẢ")));
    this->table->setHorizontalHeaderItem(3, new QTableWidgetItem(tr("SỐ LƯỢNG")));
    this->table->setColumnWidth(0,300);
    this->table->setColumnWidth(1,300);
    this->table->setColumnWidth(2,400);
    this->table->setColumnWidth(3,120);

    btn_add = new QPushButton(" Thêm sách ");
    btn_del = new QPushButton(" Xóa sách ");
    btn_upd = new QPushButton(" Cập nhật ");

    btn_add->setFont(FONT_SIZE_NORMAL);
    btn_del->setFont(FONT_SIZE_NORMAL);
    btn_upd->setFont(FONT_SIZE_NORMAL);

    QHBoxLayout *lay_btn = new QHBoxLayout();
    lay_btn->addStretch(1);
    lay_btn->addWidget(btn_add);
    lay_btn->addWidget(btn_del);
    lay_btn->addWidget(btn_upd);
    lay_btn->setContentsMargins(0,5,30,0);
    lay_btn->setSpacing(20);

    this->main_layout->addLayout(lay_btn);

    QHBoxLayout *label = new QHBoxLayout();
    QLabel *hd1 = new QLabel(tr("Hướng dẫn:\n"
                                "Nhấn vào nút || Thêm sách || để tạo sách mới\n"
                                "Nhấn vào nút || Xóa sách || để xóa sách đang chọn\n"
                                "Nhấn vào nút || Cập nhật || để thêm sách vào hệ thống"));
    QLabel *hd2 = new QLabel(tr("\n"
                                "Tên sách và tên tác giả: tối thiểu 10 kí tự không dấu\n"
                                "Phần mô tả sách: tối thiểu 50 kí tự không dấu\n"
                                "Số lượng (cuốn): tối thiểu 1, tối đa 1000"));

    hd1->setFont(FONT_SIZE_NORMAL);
    hd2->setFont(FONT_SIZE_NORMAL);
    label->addWidget(hd1);
    label->addStretch(1);
    label->addWidget(hd2);
    main_layout->addLayout(label);
}

void table_add_book::setListener()
{
    connect(btn_add, SIGNAL(clicked(bool)), this, SLOT(addRow()));
    connect(btn_del, SIGNAL(clicked(bool)), this, SLOT(deleteRow()));
    connect(btn_upd, SIGNAL(clicked(bool)), this, SLOT(update_data()));
}

void table_add_book::update_data()
{
    stack<int> row_remove;
    for (int i = 0; i < this->table->rowCount(); ++i) {
        QString name, author, info;
        int number, ok = 1;
        for (int j = 0; j < 4; ++j) {
            QTableWidgetItem *item = this->table->item(i, j);
            if (!item) {ok = 0; break;}
            if (j == 0) {
                if (item->text().size() < 10) {ok = 0; break;}
                name = item->text();
            }
            if (j == 1) {
                if (item->text().size() < 10) {ok = 0; break;}
                author = item->text();
            }
            if (j == 2) {
                if (item->text().size() < 50) {ok = 0; break;}
                info = item->text();
            }
            if (j == 3) {
                bool flag;
                number = item->text().toInt(&flag);
                if (!flag || number <= 0 || number > 1000) {ok = 0; break;}
            }
        }
        if (ok) {
            row_remove.push(i);
            l_book.push_back(book(name.toStdString(), author.toStdString(), info.toStdString(),
                                  number, allocateIDBook()));
        }
    }
    while (row_remove.size()) {
        this->table->removeRow(row_remove.top());
        row_remove.pop();
    }
    if (this->table->rowCount() == 0) this->table->setRowCount(5);
}
