#include "sign_up_activity.h"

using namespace std;

sign_up_activity::sign_up_activity(QWidget *parent) : QWidget(parent)
{
    this->setUI();
    this->setListenEvent();
}

void sign_up_activity::setUI()
{
    this->move(350, 100);
    this->setMinimumWidth(500);
    this->setFont(FONT_SIZE_NORMAL);
    this->setWindowTitle("Đăng kí tài khoản mới");

    // KHOI TAO LAYOUT CHO WIDGET
    main_layout = new QVBoxLayout(this);

    // TIEU DE CHO WIDGET
    title = new QLabel("ĐĂNG KÍ MỚI TÀI KHOẢN NGƯỜI DÙNG");
    title->setFont(FONT_SIZE_XLARGE);
    title->setAlignment(Qt::AlignCenter);
    title->setMargin(30);
    main_layout->addWidget(title);

    // LAYOUT FORM DANG KI
    form = new QFormLayout();

    account_name = new QLineEdit();
    password_1 = new QLineEdit();
    password_2 = new QLineEdit();
    id = new QLineEdit();
    email = new QLineEdit();
    username = new QLineEdit();
    telephone = new QLineEdit();
    birth_date = new QDateEdit();

    account_name->setMaxLength(MAX_LENGTH_INPUT);
    password_1->setMaxLength(MAX_LENGTH_INPUT);
    password_2->setMaxLength(MAX_LENGTH_INPUT);
    id->setMaxLength(MAX_LENGTH_INPUT);
    email->setMaxLength(MAX_LENGTH_INPUT);
    username->setMaxLength(MAX_LENGTH_INPUT);
    telephone->setMaxLength(MAX_LENGTH_INPUT);

    QRegExp re; // set CU PHAP FORMAT CHO INPUT
    re.setPattern(REGEXP_ACCOUNT_NAME);
    account_name->setValidator(new QRegExpValidator(re));
    re.setPattern(REGEXP_USERNAME);
    username->setValidator(new QRegExpValidator(re));
    re.setPattern(REGEXP_PASSWORD);
    password_1->setValidator(new QRegExpValidator(re));
    password_2->setValidator(new QRegExpValidator(re));
    password_1->setEchoMode(QLineEdit::Password);
    password_2->setEchoMode(QLineEdit::Password);
    re.setPattern(REGEXP_ID);
    id->setValidator(new QRegExpValidator(re));
    re.setPattern(REGEXP_EMAIL);
    email->setValidator(new QRegExpValidator(re));
    re.setPattern(REGEXP_TELEPHONE);
    telephone->setValidator(new QRegExpValidator(re));

    birth_date->setCalendarPopup(true);
    birth_date->setDisplayFormat("dd/MM/yyyy");
    birth_date->setMaximumDate(QDate::currentDate().addYears(-16)); // toi thieu phai 16 tuoi
    birth_date->setMinimumDate(QDate::currentDate().addYears(-120)); // toi da la 120 tuoi

    form->addRow("Tên tài khoản:", account_name);
    form->addRow("Mật khẩu:", password_1);
    form->addRow("Xác nhận mật khẩu:", password_2);
    form->addRow("Địa chỉ Email:", email);
    form->addRow("Chứng minh nhân dân:", id);
    form->addRow("Tên người dùng:", username);
    form->addRow("Số điện thoại:", telephone);
    form->addRow("Ngày sinh:", birth_date);

    form->setHorizontalSpacing(15);
    form->setVerticalSpacing(10);
    form->setContentsMargins(20,0,20,0);
    main_layout->addLayout(form);

    // LAYOUT CHO 2 BUTTON send VA cancle
    layout_btn = new QHBoxLayout();

    btn_send_sign_up = new QPushButton("Gửi");
    btn_cancle = new QPushButton("Thoát");
    layout_btn->addStretch(1);
    layout_btn->addWidget(btn_send_sign_up);
    layout_btn->addWidget(btn_cancle);
    layout_btn->addStretch(1);
    layout_btn->setSpacing(30);
    layout_btn->setMargin(20);
    main_layout->addLayout(layout_btn);

    // SET LAYOUT CHO WIDGET
    main_layout->addStretch(1);
    this->setLayout(main_layout);
}

void sign_up_activity::reset() {
    this->hide();
    this->move(350, 100);
    account_name->setText("");
    password_1->setText("");
    password_2->setText("");
    id->setText("");
    email->setText("");
    username->setText("");
    telephone->setText("");
}

void sign_up_activity::setListenEvent() {
    connect(btn_send_sign_up, SIGNAL(clicked(bool)), this, SLOT(onClick_btn_send_sign_up()));
    connect(btn_cancle, SIGNAL(clicked(bool)), this, SLOT(onClick_btn_cancle()));
}

void sign_up_activity::onClick_btn_send_sign_up()
{
    QMessageBox *message = new QMessageBox(this);
    message->setFont(FONT_SIZE_NORMAL);
    message->setWindowTitle("Thông báo");
    message->setContentsMargins(20, 20, 20, 20);
    message->setIcon(QMessageBox::Warning);

    string m_account_name = account_name->text().toStdString();
    string m_password_1 = password_1->text().toStdString();
    string m_password_2 = password_2->text().toStdString();
    string m_id = id->text().toStdString();
    string m_email = email->text().toStdString();
    string m_username = username->text().toStdString();
    string m_telephone = telephone->text().toStdString();
    int m_day = birth_date->date().day();
    int m_month = birth_date->date().month();
    int m_year = birth_date->date().year();

    // KIEM TRA THONG TIN DANG KI
    bool success = false;
    for (;;) {
        // account name ?
        if (m_account_name.size() < 5) {
            message->setText("Tên tài khoản tối thiêu 5 kí tự");
            break;
        }
        account account_found;
        if (account::findAccount_name(m_account_name, account_found, -1) != NOT_FIND) {
            message->setText("Tên tài khoản đã được dùng!\n");
            break;
        }
        // password_1 == password_2 ?
        if (m_password_1 != m_password_2) {
            message->setText("Mật khẩu không khớp!\n");
            break;
        }
        if (m_password_1.size() < 5) {
            message->setText("Mật khẩu quá yếu!\n"
                             "Mật khẩu tối thiểu 5 kí tự!\n");
            break;
        }
        // email ?
        QRegExp re(REGEXP_EMAIL);
        if (!re.exactMatch(email->text())) {
            message->setText("Địa chỉ Email không hợp lệ!\n");
            break;
        }
        // cmnd id ?
        if (id->text().toStdString().size() < 10) {
            message->setText("Số CMND ít nhất 10 số\n");
            break;
        }
        // username ?
        re.setPattern(REGEXP_USERNAME);
        if (re.exactMatch(username->text()) == false) {
            message->setText("Tên người dùng:\n"
                             "    + là chữ việt không dấu\n"
                             "    + phải có họ và tên\n"
                             "    + không kết thúc bằng khoảng trắng\n");
            break;
        }
        // so dien thoai tel ?
        if (m_telephone.size() < 10) {
            message->setText("Số điện thoại không hợp lệ!\n");
            break;
        }
        // luu du lieu dang ki
        account m_account = account(m_account_name, hashPassword(m_password_1), m_email, m_id, m_username, m_telephone, m_day, m_month, m_year);
        l_account_require.push_back(m_account);
        message->setText("Đăng kí thành công!\n"
                         "Yêu cầu của bạn sẽ được Quản lý người dùng xét duyệt!\n"
                         "Bạn cần đến thư viện để hoàn tất việc đăng kí!");
        message->setIcon(QMessageBox::Information);
        success = true;
        break;
    }
    // KET THUC KIEM TRA DANG KI

    message->exec();

    if (message->close()) {
        if (success) {
            this->reset();
        }
    }
}
