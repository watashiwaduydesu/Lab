#include "session_activity.h"

session_activity::session_activity(QWidget *parent) : QWidget(parent)
{
    this->setUI();
    this->setListenEvent();
}

void session_activity::setListenEvent() {
    connect(change_password, SIGNAL(triggered(bool)), this, SLOT(onTrigger_change_password()));
    connect(exit, SIGNAL(triggered(bool)), this, SLOT(onTrigger_exit()));
    connect(information, SIGNAL(triggered(bool)), this, SLOT(onTrigger_information()));
    if (main_account.getRole() == USER) {
        connect(act_book_code, SIGNAL(triggered(bool)), this, SLOT(onTrigger_act_book_code()));
        connect(act_book_name, SIGNAL(triggered(bool)), this, SLOT(onTrigger_act_book_name()));
        connect(act_book_author, SIGNAL(triggered(bool)), this, SLOT(onTrigger_act_book_author()));
        connect(act_book_information, SIGNAL(triggered(bool)), this, SLOT(onTrigger_act_book_information()));
    }
    else if (main_account.getRole() == LIBRARIAN) {
        connect(act_add_book, SIGNAL(triggered(bool)), this, SLOT(onTrigger_act_add_book()));
        connect(act_find_book, SIGNAL(triggered(bool)), this, SLOT(onTrigger_act_find_book()));
        connect(act_require_book, SIGNAL(triggered(bool)), this, SLOT(onTrigger_act_require_book()));
        connect(act_borrow_book, SIGNAL(triggered(bool)), this, SLOT(onTrigger_act_borrow_book()));
        connect(act_owe_book, SIGNAL(triggered(bool)), this, SLOT(onTrigger_act_owe_book()));
    }
    else if (main_account.getRole() == ADMIN) {

    }
}

void session_activity::setUI() {
    this->setFont(FONT_SIZE_NORMAL);
    this->setMinimumSize(1000, 500);
    this->setWindowTitle("Phiên làm việc");

    main_layout = new QVBoxLayout(this);

    this->addMenuTop();

    QLabel *tit = new QLabel("PHIÊN LÀM VIỆC CỦA BẠN");
    tit->setFont(FONT_SIZE_XLARGE);
    tit->setAlignment(Qt::AlignCenter);
    main_layout->addWidget(tit);
    main_layout->addSpacing(10);

    if (main_account.getRole() == USER) this->addFunctionUser();
    else if (main_account.getRole() == ADMIN) this->addFunctionAdmin();
    else if (main_account.getRole() == LIBRARIAN) this->addFunctionLibrarian();

    area = new QGridLayout();
    scrollarea = new QScrollArea();
    scrollarea->setLayout(area);
    main_layout->addWidget(scrollarea, 1);

    this->setLayout(main_layout);
}

void session_activity::addMenuTop()
{
    layout_menu_top = new QHBoxLayout();

    menu_left = new QMenuBar();
    menu_right = new QMenuBar();
    menu_left->setFont(FONT_SIZE_NORMAL_BOLD);
    menu_right->setFont(FONT_SIZE_NORMAL_BOLD);

    information = menu_left->addAction("THÔNG TIN NGƯỜI DÙNG");
    notification = menu_left->addAction("THÔNG BÁO");
    history = menu_left->addAction("LỊCH SỬ GIAO DỊCH");
    change_password = menu_left->addAction("ĐỔI MẬT KHẨU");
    exit = menu_right->addAction("THOÁT");

    layout_menu_top->addWidget(menu_left, 0, Qt::AlignLeft);
    layout_menu_top->addWidget(menu_right, 0, Qt::AlignRight);

    main_layout->addLayout(layout_menu_top);
    main_layout->addSpacing(10);
}

void session_activity::addFunctionUser()
{
    QLabel *title = new QLabel("Chức năng của người dùng (User):");
    title->setFont(FONT_SIZE_NORMAL_BOLD);
    this->setContentsMargins(10, 5, 0, 10);
    main_layout->addWidget(title);
    main_layout->addSpacing(15);

    edt_search = new QLineEdit();
    edt_search->setMaxLength(MAX_LENGTH_SEARCH);
    edt_search->setTextMargins(15,5,15,5);
    edt_search->setPlaceholderText("Ví dụ: IDB0000010 | Lap trinh C++ |  Nguyen Minh Man | huong doi tuong | ngon ngu C++ | ...");
    edt_search->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QHBoxLayout *layout_edt = new QHBoxLayout();
    layout_edt->addStretch(1);
    layout_edt->addWidget(edt_search, 5);
    layout_edt->addStretch(1);
    main_layout->addLayout(layout_edt);

    QMenuBar *menu_user = new QMenuBar();
    menu_user->setFont(FONT_SIZE_NORMAL);
    act_book_code = menu_user->addAction("1. Tìm theo mã sách");
    act_book_name = menu_user->addAction("2. Tìm theo tên sách");
    act_book_author = menu_user->addAction("3. Tìm theo tác giả");
    act_book_information = menu_user->addAction("4. Tìm tất cả thông tin");

    QHBoxLayout *layout_menu = new QHBoxLayout();
    layout_menu->addWidget(menu_user, 0, Qt::AlignCenter);
    layout_menu->setContentsMargins(10, 10, 10, 10);
    main_layout->addLayout(layout_menu);
}

void session_activity::addFunctionLibrarian()
{
    QLabel *title = new QLabel("Chức năng của thủ thư (Librarian):");
    title->setFont(FONT_SIZE_NORMAL_BOLD);
    this->setContentsMargins(10, 5, 0, 10);
    main_layout->addWidget(title);
    main_layout->addSpacing(15);

    QMenuBar *menu_lib = new QMenuBar();
    menu_lib->setFont(FONT_SIZE_NORMAL);
    act_find_book = menu_lib->addAction("1. Tìm sách");
    act_add_book = menu_lib->addAction("2. Thêm sách mới");
    act_require_book = menu_lib->addAction("3. Xử lí yêu cầu mượn sách");
    act_borrow_book = menu_lib->addAction("4. Người dùng đang mượn sách");
    act_owe_book = menu_lib->addAction("5. Người dùng đang nợ sách");

    QHBoxLayout *layout_menu = new QHBoxLayout();
    layout_menu->addWidget(menu_lib);
    layout_menu->setContentsMargins(10,0,10,10);
    main_layout->addLayout(layout_menu);

    edt_search = new QLineEdit();
    edt_search->setMaxLength(MAX_LENGTH_SEARCH);
    edt_search->setTextMargins(15,5,15,5);
    edt_search->setPlaceholderText("Ví dụ: IDB0000010 | Lap trinh C++ |  Nguyen Minh Man | huong doi tuong | ngon ngu C++ | ...");
    edt_search->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QHBoxLayout *layout_edt = new QHBoxLayout();
    layout_edt->addStretch(1);
    layout_edt->addWidget(edt_search, 5);
    layout_edt->addStretch(1);
    main_layout->addLayout(layout_edt);
}

void session_activity::addFunctionAdmin()
{

}

void session_activity::showBook(book &bk) {
    QFormLayout *lay = new QFormLayout();
    lay->addRow("Mã sách:", new QLabel(QString(bk.getCode().c_str())));
    lay->addRow("Tên sách:", new QLabel(QString(bk.getName().c_str())));
    lay->addRow("Tác giả:", new QLabel(QString(bk.getAuthor().c_str())));
    lay->addRow("Mô tả:", new QLabel(QString(bk.getInformation().c_str())));
    lay->addRow("Số lượng", new QLabel(QString(std::to_string(bk.getRemain()).c_str())));
}

void session_activity::onTrigger_act_book_code() {
    string text = edt_search->text().toStdString();
    vector<book> res = main_account.findBook_code(text);
    if (res.size() == 0) {
        main_layout->addWidget(new QLabel("Không tìm thấy yêu cầu của bạn"));
        return;
    }
    showBook(res[0]);
}

void session_activity::onTrigger_act_book_name() {

}

void session_activity::onTrigger_act_book_author() {

}

void session_activity::onTrigger_act_book_information() {

}

void session_activity::onTrigger_act_add_book() {

}

void session_activity::onTrigger_act_find_book() {

}

void session_activity::onTrigger_act_borrow_book() {

}


void session_activity::onTrigger_act_require_book() {

}

void session_activity::onTrigger_act_owe_book() {

}
