#include "start_activity.h"


#include "sign_in_activity.h"
#include "sign_up_activity.h"
#include "session_user_activity.h"
#include "session_librarian_activity.h"
#include "session_admin_activity.h"

start_activity::start_activity(QWidget *parent) : QWidget(parent)
{
    this->setUI();
    window_sign_up = new sign_up_activity();
    window_sign_in = new sign_in_activity();
    this->setListenEvent();
}

void start_activity::setListenEvent() {
    connect(btn_sign_up, SIGNAL(clicked(bool)), this, SLOT(onClick_btn_sign_up()));
    connect(btn_sign_in, SIGNAL(clicked(bool)), this, SLOT(onClick_btn_sign_in()));
    connect(btn_quit, SIGNAL(clicked(bool)), this, SLOT(onClick_btn_quit()));
    connect(window_sign_in, SIGNAL(signInSucceed()), this, SLOT(open_window_session()));
}

void start_activity::onClick_btn_sign_up() {
    window_sign_up->show();
}

void start_activity::onClick_btn_sign_in() {
    window_sign_in->show();
}

void start_activity::open_window_session() {
    if (main_account.getRole() == USER) {
        window_user_session = new session_user_activity();
        window_user_session->show();
    }
    else if (main_account.getRole() == LIBRARIAN) {
        window_lib_session = new session_librarian_activity();
        window_lib_session->show();
    }
    else if (main_account.getRole() == ADMIN) {
        window_admin_session = new session_admin_activity();
        window_admin_session->show();
    }
    this->hide();
}

void start_activity::setUI()
{
    this->setMinimumSize(600, 400);
    this->setFont(FONT_SIZE_NORMAL);
    this->setWindowTitle("Chương trình quản lí thư viện");

    // khoi tao layout cua widget
    main_layout = new QVBoxLayout(this);

    // layout cho button sign up and sign in
    layout_top = new QHBoxLayout();

    btn_sign_up = new QPushButton("Đăng kí");
    btn_sign_in = new QPushButton("Đăng nhập");
    btn_quit = new QPushButton("Thoát");

    layout_top->addStretch(1);
    layout_top->addWidget(btn_sign_up);
    layout_top->addWidget(btn_sign_in);
    layout_top->addWidget(btn_quit);
    layout_top->setSpacing(5);
    layout_top->setMargin(5);
    main_layout->addLayout(layout_top);

    // tieu de widget
    title = new QLabel("CHƯƠNG TRÌNH QUẢN LÍ THƯ VIỆN");
    title->setFont(FONT_SIZE_XLARGE);
    title->setAlignment(Qt::AlignCenter);
    title->setMargin(30);
    main_layout->addWidget(title);

    // text 1
    text_1 = new QLabel();
    QString text_content("Nhập từ khóa tìm kiếm: (tối đa ");
    text_content.append(QString::number(MAX_LENGTH_SEARCH));
    text_content.append(" kí tự)");
    text_1->setText(text_content);
    text_1->setFont(FONT_SIZE_NORMAL);
    text_1->setAlignment(Qt::AlignLeft);
    text_1->setMargin(10);
    main_layout->addWidget(text_1);

    // layout search: gom line_edit va button search
    layout_search = new QHBoxLayout();

    // edit text search
    edt_search = new QLineEdit();
    edt_search->setMaxLength(MAX_LENGTH_SEARCH);
    edt_search->setTextMargins(15,5,15,5);
    edt_search->setPlaceholderText("Ví dụ: Lap trinh C++");
    edt_search->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout_search->addWidget(edt_search, 5);

    // button search
    btn_search = new QPushButton("Tìm kiếm");
    layout_search->addWidget(btn_search, 1);

    layout_search->setAlignment(Qt::AlignCenter);
    layout_search->setContentsMargins(20, 5, 20, 5);
    main_layout->addLayout(layout_search);

    // set layout cho widget
    main_layout->addStretch(1);
    this->setLayout(main_layout);
}

