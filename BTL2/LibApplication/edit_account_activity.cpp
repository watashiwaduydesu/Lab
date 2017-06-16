#include "edit_account_activity.h"
#include <QDebug>

edit_account_activity::edit_account_activity(const account &acc, QWidget *parent)
    : QWidget(parent), m_account(acc)
{
    this->setUI();
    this->setListenEvent();
}

void edit_account_activity::setUI()
{
    this->move(300, 100);
    this->setMinimumWidth(650);
    this->setFont(FONT_SIZE_NORMAL);
    this->setWindowTitle("Chỉnh sửa thông tin tài khoản");

    main_layout = new QVBoxLayout(this);

    QLabel *title = new QLabel("THÔNG TIN TÀI KHOẢN");
    title->setFont(FONT_SIZE_XLARGE);
    title->setAlignment(Qt::AlignCenter);
    title->setMargin(30);
    main_layout->addWidget(title);

    QFormLayout *form = new QFormLayout();

    form = new QFormLayout();

    form->addRow("Mã tài khoản:", new QLabel(QString(m_account.getCode().c_str())));
    form->addRow("Tên tài khoản:", new QLabel(QString(m_account.getName().c_str())));

    QRegExp re;

    edt_username = new QLineEdit();
    edt_username->setMaxLength(MAX_LENGTH_INPUT);
    edt_username->setText(QString(m_account.getUsername().c_str()));
    form->addRow("Tên người dùng:", edt_username);

    edt_email = new QLineEdit();
    edt_email->setMaxLength(MAX_LENGTH_INPUT);
    re.setPattern(REGEXP_EMAIL);
    edt_email->setValidator(new QRegExpValidator(re));
    edt_email->setText(QString(m_account.getEmail().c_str()));
    form->addRow("Địa chỉ Email:", edt_email);

    edt_phone = new QLineEdit();
    edt_phone->setMaxLength(MAX_LENGTH_INPUT);
    re.setPattern(REGEXP_TELEPHONE);
    edt_phone->setValidator(new QRegExpValidator(re));
    edt_phone->setText(QString(m_account.getTel().c_str()));
    form->addRow("Điện thoại liên lạc:", edt_phone);

    edt_id = new QLineEdit();
    edt_id->setMaxLength(MAX_LENGTH_INPUT);
    re.setPattern(REGEXP_ID);
    edt_id->setValidator(new QRegExpValidator(re));
    edt_id->setText(QString(m_account.getID().c_str()));
    form->addRow("Số chứng minh nhân dân:", edt_id);

    edt_birth = new QDateEdit(m_account.getBirthDate());
    edt_birth->setCalendarPopup(true);
    edt_birth->setDisplayFormat("dd/MM/yyyy");
    edt_birth->setMaximumDate(QDate::currentDate().addYears(-16)); // toi thieu phai 16 tuoi
    edt_birth->setMinimumDate(QDate::currentDate().addYears(-120)); // toi da la 120 tuoi
    form->addRow("Ngày sinh:", edt_birth);

    grp_role = new QButtonGroup();
    btn_admin = new QRadioButton(tr("Quản trị viên (Admin)"));
    btn_lib = new QRadioButton(tr("Thủ thư (Librarian)"));
    btn_user = new QRadioButton(tr("Người dùng (User)"));
    grp_role->addButton(btn_admin);
    grp_role->addButton(btn_lib);
    grp_role->addButton(btn_user);
    QVBoxLayout *lay_role = new QVBoxLayout();
    lay_role->addWidget(btn_admin);
    lay_role->addWidget(btn_lib);
    lay_role->addWidget(btn_user);
    lay_role->setSpacing(15);

    if (m_account.getRole() == LIBRARIAN) btn_lib->setChecked(true);
    else if (m_account.getRole() == ADMIN) btn_admin->setChecked(true);
    else btn_user->setChecked(true);
    form->addRow("Vai trò tài khoản:", lay_role);

    grp_state = new QButtonGroup();
    btn_active = new QRadioButton(tr("Cho phép hoạt động / Mở khóa"));
    btn_disabled = new QRadioButton(tr("Khóa tài khoản"));
    grp_state->addButton(btn_active);
    grp_state->addButton(btn_disabled);
    QHBoxLayout *lay_state = new QHBoxLayout();
    lay_state->addWidget(btn_active);
    lay_state->addWidget(btn_disabled);
    lay_state->setSpacing(30);

    if (m_account.isActive()) btn_active->setChecked(true);
    else btn_disabled->setChecked(true);
    form->addRow("Tình trạng tài khoản:", lay_state);

    edt_password = new QLineEdit();
    edt_password->setMaxLength(MAX_LENGTH_INPUT);
    edt_password->setEchoMode(QLineEdit::Password);
    re.setPattern(REGEXP_PASSWORD);
    edt_password->setValidator(new QRegExpValidator(re));
    edt_password->setEnabled(false);
    btn_change_password = new QPushButton("Tạo mới");
    QHBoxLayout *lay2 = new QHBoxLayout();
    lay2->addWidget(edt_password, 5);
    lay2->addWidget(btn_change_password, 1);
    lay2->setSpacing(20);
    form->addRow("Mật khẩu:", lay2);

    form->setHorizontalSpacing(25);
    form->setVerticalSpacing(10);
    form->setContentsMargins(20,0,20,0);
    main_layout->addLayout(form);

    QHBoxLayout *layout_btn = new QHBoxLayout();
    btn_return = new QPushButton("Thoát");
    btn_return->setFont(FONT_SIZE_NORMAL);
    btn_update = new QPushButton("Cập nhật");
    btn_update->setFont(FONT_SIZE_NORMAL);
    btn_remove = new QPushButton("Xóa tài khoản");
    btn_remove->setFont(FONT_SIZE_NORMAL);

    layout_btn->addWidget(btn_update);
    layout_btn->addWidget(btn_return);
    layout_btn->addWidget(btn_remove);
    layout_btn->setSpacing(50);
    layout_btn->setAlignment(Qt::AlignCenter);
    layout_btn->setMargin(30);

    main_layout->addLayout(layout_btn);

    main_layout->addStretch(1);
    this->setLayout(main_layout);
}

void edit_account_activity::reset()
{
    this->hide();
    this->move(350, 150);
}

void edit_account_activity::setListenEvent()
{
    connect(btn_return, SIGNAL(clicked(bool)), this, SLOT(onClick_btn_return()));
    connect(btn_update, SIGNAL(clicked(bool)), this, SLOT(onClick_btn_update()));
    connect(btn_remove, SIGNAL(clicked(bool)), this, SLOT(onClick_btn_remove()));
    connect(btn_change_password, SIGNAL(clicked(bool)), this, SLOT(onClick_btn_change_password()));
}

void edit_account_activity::onClick_btn_update()
{
    QMessageBox *message = new QMessageBox(this);
    message->setFont(FONT_SIZE_NORMAL);
    message->setWindowTitle("Thông báo");
    message->setContentsMargins(20, 20, 20, 20);
    message->setIcon(QMessageBox::Warning);

    bool success = false;
    for (;;) {
        QRegExp re(REGEXP_EMAIL);
        if (!re.exactMatch(edt_email->text())) {
            message->setText("Địa chỉ Email không hợp lệ!\n");
            break;
        }
        if (edt_id->text().toStdString().size() < 10) {
            message->setText("Số CMND ít nhất 10 số\n");
            break;
        }
        re.setPattern(REGEXP_USERNAME);
        if (re.exactMatch(edt_username->text()) == false) {
            message->setText("Tên người dùng:\n"
                             "    + là chữ việt không dấu\n"
                             "    + phải có họ và tên\n"
                             "    + không kết thúc bằng khoảng trắng\n");
            break;
        }
        if (edt_phone->text().size() < 10) {
            message->setText("Số điện thoại không hợp lệ!\n");
            break;
        }
        if (edt_password->isEnabled()) {
            if (edt_password->text().size() < 5) {
                message->setText("Mật khẩu quá yếu!\n"
                                 "Mật khẩu tối thiểu 5 kí tự!\n");
                break;
            }
        }

        string name = m_account.getName();
        int password = m_account.getPassword();
        if (edt_password->isEnabled())  password = hashPassword(edt_password->text().toStdString());
        string email = edt_email->text().toStdString();
        string id = edt_id->text().toStdString();
        string user = edt_username->text().toStdString();
        string phone = edt_phone->text().toStdString();
        int day = edt_birth->date().day();
        int month = edt_birth->date().month();
        int year = edt_birth->date().year();
        int role = USER;
        if (btn_admin->isChecked()) role = ADMIN;
        else if (btn_lib->isChecked()) role = LIBRARIAN;
        int state = ACTIVE;
        if (btn_disabled->isChecked()) state = DISABLED;
        string code = m_account.getCode();

        account acc_tmp(name, password, email, id, user, phone, day, month, year, role, state, code);
        main_admin.editAccount(code, acc_tmp);

        message->setText("Thông tin đã được cập nhật\n");
        message->setIcon(QMessageBox::Information);
        success = true;
        break;
    }

    message->exec();
    if (message->close() && success) this->reset();
}

void edit_account_activity::onClick_btn_remove()
{
    QMessageBox *message = new QMessageBox();
    message->setWindowTitle("Xác nhận xóa tài khoản");
    message->setText("Bạn thật sự muốn xóa tài khoản này khỏi hệ thống ?");
    message->setFont(FONT_SIZE_NORMAL);
    message->setContentsMargins(20, 20, 20, 20);
    message->setIcon(QMessageBox::Question);
    message->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    message->setButtonText(QMessageBox::Ok, "Xóa");
    message->setButtonText(QMessageBox::Cancel, "Quay trở về");
    message->setDefaultButton(QMessageBox::Cancel);

    int res = message->exec();
    switch (res)
    {
    case QMessageBox::Ok:
        main_admin.deleteAccount(m_account.getCode());
        this->hide();
        break;

    case QMessageBox::Cancel:
        break;
    }
}

void edit_account_activity::onClick_btn_change_password()
{
    edt_password->setEnabled(true);
}
