#include "viewinformation_activity.h"

viewInformation_activity::viewInformation_activity(QWidget *parent) : QWidget(parent)
{
    this->setUI();
    this->setListenEvent();
}

void viewInformation_activity::setListenEvent() {
    connect(btn_return, SIGNAL(clicked(bool)), this, SLOT(onClick_btn_return()));
}

void viewInformation_activity::setUI()
{
    this->move(350, 150);
    this->setMinimumWidth(600);
    this->setFont(FONT_SIZE_MEDIUM);
    this->setWindowTitle("Thông tin tài khoản");

    main_layout = new QVBoxLayout(this);

    title = new QLabel("THÔNG TIN TÀI KHOẢN CỦA BẠN");
    title->setFont(FONT_SIZE_XLARGE);
    title->setAlignment(Qt::AlignCenter);
    title->setMargin(30);
    main_layout->addWidget(title);

    form = new QFormLayout();

    form->addRow("Mã tài khoản:", new QLabel(QString(main_account.getCode().c_str())));
    form->addRow("Tên tài khoản:", new QLabel(QString(main_account.getName().c_str())));
    string role = "Người dùng (User)";
    if (main_account.getRole() == LIBRARIAN) role = "Thủ thư (Librarian)";
    else if (main_account.getRole() == ADMIN) role = "Quản trị viên (Admin)";
    form->addRow("Vai trò tài khoản:", new QLabel(QString(role.c_str())));
    form->addRow("Tên người dùng:", new QLabel(QString(main_account.getUsername().c_str())));
    form->addRow("Địa chỉ Email:", new QLabel(QString(main_account.getEmail().c_str())));
    form->addRow("Số điện thoại:", new QLabel(QString(main_account.getTel().c_str())));
    form->addRow("Số chứng minh nhân dân:", new QLabel(QString(main_account.getID().c_str())));
    stringstream ss;
    ss << main_account.getDay() << " / " << main_account.getMonth() << " / " << main_account.getYear();
    form->addRow("Ngày sinh:", new QLabel(QString(ss.str().c_str())));

    form->setHorizontalSpacing(25);
    form->setVerticalSpacing(10);
    form->setContentsMargins(20,0,20,0);
    main_layout->addLayout(form);

    layout_btn = new QHBoxLayout();
    btn_return = new QPushButton("Trở về phiên làm việc");
    btn_return->setFont(FONT_SIZE_MEDIUM);
    layout_btn->addWidget(btn_return);
    layout_btn->setAlignment(Qt::AlignCenter);
    layout_btn->setMargin(30);

    main_layout->addLayout(layout_btn);

    // set layout cho widget
    main_layout->addStretch(1);
    this->setLayout(main_layout);
}

void viewInformation_activity::reset() {
    this->hide();
    this->move(350, 150);
}
