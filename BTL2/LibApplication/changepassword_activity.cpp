#include "changepassword_activity.h"

changePassword_activity::changePassword_activity(QWidget *parent) : QWidget(parent)
{
    this->setUI();
    this->setListenEvent();
}

void changePassword_activity::setListenEvent() {
    connect(btn_submit, SIGNAL(clicked(bool)), this, SLOT(onClick_btn_submit()));
    connect(btn_cancle, SIGNAL(clicked(bool)), this, SLOT(onClick_btn_cancle()));
}

void changePassword_activity::onClick_btn_submit()
{
    QMessageBox *message = new QMessageBox(this);
    message->setFont(FONT_SIZE_NORMAL);
    message->setWindowTitle("Thông báo");
    message->setContentsMargins(20, 20, 20, 20);
    message->setIcon(QMessageBox::Warning);
    string m_pass_cur = password_cur->text().toStdString();
    string m_pass_new = password_new->text().toStdString();
    string m_pass_again = password_again->text().toStdString();

    bool flag = 0;
    for (;;) {
        if (main_account.checkPassword(hashPassword(m_pass_cur)) == false) {
            message->setText("Sai mật khẩu !\n");
            break;
        }
        if (m_pass_new != m_pass_again) {
            message->setText("Mật khẩu mới không khớp !\n");
            break;
        }
        if (m_pass_new.size() < 5) {
            message->setText("Mật khẩu mới quá yếu!\n"
                             "Mật khẩu tối thiểu 5 kí tự!\n");
            break;
        }
        updatePasswordMainAccount(hashPassword(m_pass_new));
        message->setText("Đổi mật khẩu thành công !\n");
        message->setIcon(QMessageBox::Information);
        flag = 1;
        break;
    }

    message->exec();

    if (message->close()) {
        if (flag) this->reset();
    }
}

void changePassword_activity::setUI()
{
    this->move(350, 150);
    this->setMinimumWidth(500);
    this->setFont(FONT_SIZE_NORMAL);
    this->setWindowTitle("Thay đổi mật khẩu");

    main_layout = new QVBoxLayout(this);

    title = new QLabel("THAY ĐỔI MẬT KHẨU");
    title->setFont(FONT_SIZE_XLARGE);
    title->setAlignment(Qt::AlignCenter);
    title->setMargin(30);
    main_layout->addWidget(title);

    form = new QFormLayout();

    password_cur = new QLineEdit();
    password_new = new QLineEdit();
    password_again = new QLineEdit();

    password_cur->setMaxLength(MAX_LENGTH_INPUT);
    password_cur->setEchoMode(QLineEdit::Password);
    password_cur->setValidator(new QRegExpValidator(QRegExp(REGEXP_PASSWORD)));
    password_new->setMaxLength(MAX_LENGTH_INPUT);
    password_new->setEchoMode(QLineEdit::Password);
    password_new->setValidator(new QRegExpValidator(QRegExp(REGEXP_PASSWORD)));
    password_again->setMaxLength(MAX_LENGTH_INPUT);
    password_again->setEchoMode(QLineEdit::Password);
    password_again->setValidator(new QRegExpValidator(QRegExp(REGEXP_PASSWORD)));

    form->addRow("Mật khẩu hiện tại:", password_cur);
    form->addRow("Mật khẩu mới:", password_new);
    form->addRow("Nhập lại mật khẩu:", password_again);

    form->setHorizontalSpacing(15);
    form->setVerticalSpacing(10);
    form->setContentsMargins(20,0,20,0);
    main_layout->addLayout(form);

    // layout cho button
    layout_btn = new QHBoxLayout();

    btn_submit = new QPushButton("Gửi yêu cầu");
    btn_cancle = new QPushButton("Hủy yêu cầu");

    layout_btn->addStretch(1);
    layout_btn->addWidget(btn_submit);
    layout_btn->addWidget(btn_cancle);
    layout_btn->addStretch(1);
    layout_btn->setSpacing(30);
    layout_btn->setMargin(20);
    main_layout->addLayout(layout_btn);

    // set layout cho widget
    main_layout->addStretch(1);
    this->setLayout(main_layout);
}

void changePassword_activity::reset() {
    this->hide();
    password_cur->setText("");
    password_new->setText("");
    password_again->setText("");
    this->move(350, 150);
}
