#include "history_session_activity.h"

history_session_activity::history_session_activity(QWidget *parent) : QWidget(parent)
{
    this->setUI();
}

void history_session_activity::setUI()
{
    this->move(350, 150);
    this->setMinimumWidth(600);
    this->setFont(FONT_SIZE_MEDIUM);
    this->setWindowTitle("Lịch sử các phiên hoạt động");

    main_layout = new QVBoxLayout(this);

    QLabel *title = new QLabel("LỊCH SỬ CÁC PHIÊN HOẠT ĐỘNG");
    title->setFont(FONT_SIZE_XLARGE);
    title->setAlignment(Qt::AlignCenter);
    title->setMargin(30);
    main_layout->addWidget(title);


    // set layout cho widget
    main_layout->addStretch(1);
    this->setLayout(main_layout);
}

void history_session_activity::reset() {
    this->hide();
    this->move(350, 150);
}
