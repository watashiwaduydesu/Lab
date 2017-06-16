#include "session_base_activity.h"

session_base_activity::session_base_activity(QWidget *parent) : QWidget(parent)
{
    this->setUI();
    this->setListenEvent();
}

void session_base_activity::setListenEvent() {
    connect(change_password, SIGNAL(triggered(bool)), this, SLOT(onTrigger_change_password()));
    connect(exits, SIGNAL(triggered(bool)), this, SLOT(onTrigger_exit()));
    connect(information, SIGNAL(triggered(bool)), this, SLOT(onTrigger_information()));
    connect(history, SIGNAL(triggered(bool)), this, SLOT(onTrigger_history()));
}

void session_base_activity::setUI() {
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

    this->setLayout(main_layout);
}

void session_base_activity::addMenuTop()
{
    QHBoxLayout *layout_menu_top = new QHBoxLayout();

    QMenuBar *menu_left = new QMenuBar();
    QMenuBar *menu_right = new QMenuBar();
    menu_left->setFont(FONT_SIZE_NORMAL_BOLD);
    menu_right->setFont(FONT_SIZE_NORMAL_BOLD);

    information = menu_left->addAction("THÔNG TIN NGƯỜI DÙNG");
    notification = menu_left->addAction("THÔNG BÁO");
    history = menu_left->addAction("LỊCH SỬ GIAO DỊCH");
    change_password = menu_left->addAction("ĐỔI MẬT KHẨU");
    exits = menu_right->addAction("THOÁT");

    layout_menu_top->addWidget(menu_left, 0, Qt::AlignLeft);
    layout_menu_top->addWidget(menu_right, 0, Qt::AlignRight);

    main_layout->addLayout(layout_menu_top);
    main_layout->addSpacing(10);
}
