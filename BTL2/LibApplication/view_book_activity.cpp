#include "view_book_activity.h"

view_book_activity::view_book_activity(const book &bk, const user &user, QWidget *parent)
    : QWidget(parent), m_book(bk), m_user(user)
{
    enableRequire = checkEnableRequire();
    this->setUI();
    this->setListenEvent();
}

void view_book_activity::setListenEvent() {
    connect(btn_return, SIGNAL(clicked(bool)), this, SLOT(onClick_btn_return()));
    connect(btn_require, SIGNAL(clicked(bool)), this, SLOT(onClick_btn_require()));
}

void view_book_activity::addDateRequire()
{
    QHBoxLayout *layout_date = new QHBoxLayout();

    beginDate = new QDateEdit();
    beginDate->setCalendarPopup(true);
    beginDate->setDisplayFormat("dd/MM/yyyy");
    beginDate->setDate(QDate::currentDate());
    beginDate->setMinimumDate(QDate::currentDate());
    beginDate->setMaximumDate(QDate::currentDate().addDays(120));

    endDate = new QDateEdit();
    endDate->setCalendarPopup(true);
    endDate->setDisplayFormat("dd/MM/yyyy");
    endDate->setDate(beginDate->date().addDays(1));
    endDate->setMinimumDate(beginDate->date().addDays(1));
    endDate->setMaximumDate(beginDate->date().addDays(200));

    layout_date->addWidget(new QLabel(QString("Ngày mượn: ")));
    layout_date->addWidget(beginDate);
    layout_date->addWidget(new QLabel(QString("Ngày trả: ")));
    layout_date->addWidget(endDate);
    layout_date->setSpacing(30);
    layout_date->setMargin(20);
    main_layout->addLayout(layout_date);
}

bool view_book_activity::checkEnableRequire()
{
    for (user_book pair : l_user_book)
        if (pair.getUser() == m_user && pair.getBook() == m_book)
            return false;
    for (user_book pair : l_user_require_book)
        if (pair.getUser() == m_user && pair.getBook() == m_book)
            return false;
    return true;
}

void view_book_activity::onClick_btn_require()
{
    QMessageBox *message = new QMessageBox(this);
    message->setFont(FONT_SIZE_NORMAL);
    message->setWindowTitle("Thông báo");
    message->setContentsMargins(20, 20, 20, 20);

    bool res = 0;
    if (beginDate->date() >= endDate->date()) {
        message->setIcon(QMessageBox::Critical);
        message->setText("Ngày trả lại tối thiểu một ngày kể từ ngày mượn");
    } else {
        message->setIcon(QMessageBox::Information);
        message->setText("Yêu cầu đã gửi và đang chờ xét duyệt");
        l_user_require_book.push_back(user_book(m_user, m_book, beginDate->date(), endDate->date()));
        res = 1;
    }

    message->exec();
    if (message->close() && res) this->reset();
}

void view_book_activity::setUI()
{
    this->move(350, 150);
    this->setMinimumWidth(600);
    this->setFont(FONT_SIZE_MEDIUM);
    this->setWindowTitle("Mượn sách");

    main_layout = new QVBoxLayout(this);

    QLabel *title = new QLabel("THÔNG TIN SÁCH");
    title->setFont(FONT_SIZE_XLARGE);
    title->setAlignment(Qt::AlignCenter);
    title->setMargin(30);
    main_layout->addWidget(title);

    QFormLayout *form = new QFormLayout();
    form->addRow("Mã sách:", new QLabel(QString(m_book.getCode().c_str())));
    form->addRow("Tên sách:", new QLabel(QString(m_book.getName().c_str())));
    form->addRow("Tác giả:", new QLabel(QString(m_book.getAuthor().c_str())));

    QLabel *info = new QLabel(QString(m_book.getInformation().c_str()));
    info->setWordWrap(true);
    form->addRow("Mô tả:", info);
    form->addRow("Số lượng:", new QLabel(QString(std::to_string(m_book.getRemain()).c_str())));

    form->setHorizontalSpacing(25);
    form->setVerticalSpacing(10);
    form->setContentsMargins(20,0,20,0);
    main_layout->addLayout(form);

    if (enableRequire) addDateRequire();

    QHBoxLayout *layout_btn = new QHBoxLayout();
    btn_return = new QPushButton("Quay về phiên làm việc");
    btn_return->setFont(FONT_SIZE_MEDIUM_BOLD);

    btn_require = new QPushButton();
    btn_require->setFont(FONT_SIZE_MEDIUM_BOLD);
    if (enableRequire) {
        btn_require->setText("Gửi yêu cầu");
    }
    else {
        btn_require->setText("Đã gửi/mượn");
        btn_require->setEnabled(false);
    }

    layout_btn->addWidget(btn_require);
    layout_btn->addWidget(btn_return);
    layout_btn->setSpacing(50);
    layout_btn->setAlignment(Qt::AlignCenter);
    layout_btn->setMargin(30);

    main_layout->addLayout(layout_btn);

    // set layout cho widget
    main_layout->addStretch(1);
    this->setLayout(main_layout);
}

void view_book_activity::reset() {
    this->hide();
    this->move(350, 150);
}
