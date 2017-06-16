#include "sign_in_activity.h"

sign_in_activity::sign_in_activity(QWidget *parent) : QWidget(parent)
{
    this->setUI();
    this->setListenEvent();
}

void sign_in_activity::reset() {
    this->hide();
    account_name->setText("");
    password->setText("");
    this->move(350, 150);
}

void sign_in_activity::setListenEvent() {
    connect(btn_send_sign_in, SIGNAL(clicked(bool)), this, SLOT(onClick_btn_send_sign_in()));
    connect(btn_cancle, SIGNAL(clicked(bool)), this, SLOT(onClick_btn_cancle()));
}

void sign_in_activity::onClick_btn_send_sign_in()
{
    QMessageBox *message = new QMessageBox(this);
    message->setFont(FONT_SIZE_NORMAL);
    message->setWindowTitle("Thông báo");
    message->setContentsMargins(20, 20, 20, 20);

    string m_account_name = account_name->text().toStdString();
    string m_password = password->text().toStdString();

    account account_found;
    int res = account::findAccount_name(m_account_name, account_found, hashPassword(m_password));
    switch (res) {
    case SUCCESS:
        message->setText("Bạn đã đăng nhập thành công!\n");
        message->setIcon(QMessageBox::Information);
        break;
    case WRONG_PASSWORD:
        message->setText("Sai mật khẩu!\n");
        message->setIcon(QMessageBox::Critical);
        break;
    case LOCKED_ACCOUNT:
        message->setText("Tài khoản này đã bị khóa!\n");
        message->setIcon(QMessageBox::Critical);
        break;
    case NOT_FIND:
        message->setText("Không tồn tại tài khoản này!\n");
        message->setIcon(QMessageBox::Critical);
        break;
    default:
        message->setText("Lỗi hệ thống!\n");
        message->setIcon(QMessageBox::Critical);
    }

    message->exec();

    if (message->close() && res == SUCCESS) {
        this->reset();
        main_account = account_found;
        main_admin = admin(main_account);
        main_lib = librarian(main_account);
        main_user = user(main_account);

        emit signInSucceed();
    }
}

void sign_in_activity::setUI()
{
    this->move(350, 150);
    this->setMinimumWidth(500);
    this->setFont(FONT_SIZE_NORMAL);
    this->setWindowTitle("Đăng nhập");

    // khoi tao layout cua widget
    main_layout = new QVBoxLayout(this);

    // tieu de widget
    title = new QLabel("ĐĂNG NHẬP TÀI KHOẢN");
    title->setFont(FONT_SIZE_XLARGE);
    title->setAlignment(Qt::AlignCenter);
    title->setMargin(30);
    main_layout->addWidget(title);

    // form sign up
    form = new QFormLayout();

    account_name = new QLineEdit();
    password = new QLineEdit();

    account_name->setMaxLength(MAX_LENGTH_INPUT);
    password->setMaxLength(MAX_LENGTH_INPUT);
    password->setEchoMode(QLineEdit::Password);

    account_name->setValidator(new QRegExpValidator(QRegExp(REGEXP_ACCOUNT_NAME)));
    password->setValidator(new QRegExpValidator(QRegExp(REGEXP_PASSWORD)));

    form->addRow("Tên tài khoản:", account_name);
    form->addRow("Nhập mật khẩu:", password);

    form->setHorizontalSpacing(15);
    form->setVerticalSpacing(10);
    form->setContentsMargins(20,0,20,0);
    main_layout->addLayout(form);

    // layout cho button
    layout_btn = new QHBoxLayout();

    btn_send_sign_in = new QPushButton("Đăng nhập");
    btn_cancle = new QPushButton("Thoát");

    layout_btn->addStretch(1);
    layout_btn->addWidget(btn_send_sign_in);
    layout_btn->addWidget(btn_cancle);
    layout_btn->addStretch(1);
    layout_btn->setSpacing(30);
    layout_btn->setMargin(20);
    main_layout->addLayout(layout_btn);

    // set layout cho widget
    main_layout->addStretch(1);
    this->setLayout(main_layout);
}
