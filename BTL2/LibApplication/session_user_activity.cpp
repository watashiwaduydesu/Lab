#include "session_user_activity.h"
#include "view_book_activity.h"

session_user_activity::session_user_activity(QWidget *parent) : session_base_activity(parent)
{
    this->setUI2();
    this->setListenEvent2();
}

void session_user_activity::setUI2()
{
    this->setMinimumHeight(600);
    this->setMinimumWidth(1000);
    QLabel *title = new QLabel("Chức năng của người dùng (User):");
    title->setFont(FONT_SIZE_NORMAL_BOLD);
    this->setContentsMargins(10, 5, 0, 10);
    main_layout->addWidget(title);
    main_layout->addSpacing(15);

    edt_search = new QLineEdit();
    edt_search->setMaxLength(MAX_LENGTH_SEARCH);
    edt_search->setTextMargins(15,5,15,5);
    edt_search->setPlaceholderText("Ví dụ: IDB0000033 | The C++ Standard Library |  Joshua Bloch | ngon ngu Java | Android Studio | ...");
    edt_search->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    btn_reset = new QPushButton("Reset");
    btn_reset->setFont(FONT_SIZE_NORMAL);

    QHBoxLayout *layout_edt = new QHBoxLayout();
    layout_edt->addStretch(1);
    layout_edt->addWidget(edt_search, 10);
    layout_edt->addWidget(btn_reset,1);
    layout_edt->addStretch(1);
    layout_edt->setSpacing(15);
    main_layout->addLayout(layout_edt);

    QMenuBar *menu_user = new QMenuBar();
    menu_user->setFont(FONT_SIZE_NORMAL);
    act_book_code = menu_user->addAction("1. Tìm theo mã sách");
    act_book_name = menu_user->addAction("2. Tìm theo tên sách");
    act_book_author = menu_user->addAction("3. Tìm theo tác giả");
    act_book_information = menu_user->addAction("4. Tìm tất cả thông tin");

    QHBoxLayout *layout_menu = new QHBoxLayout();
    layout_menu->addWidget(menu_user);
    layout_menu->setContentsMargins(10, 10, 10, 10);
    main_layout->addLayout(layout_menu);

    this->setUiListBook();
}

void session_user_activity::setListenEvent2() {
    connect(btn_reset, SIGNAL(clicked(bool)), this, SLOT(onClick_btn_reset()));
    connect(act_book_code, SIGNAL(triggered(bool)), this, SLOT(onTrigger_act_book_code()));
    connect(act_book_name, SIGNAL(triggered(bool)), this, SLOT(onTrigger_act_book_name()));
    connect(act_book_author, SIGNAL(triggered(bool)), this, SLOT(onTrigger_act_book_author()));
    connect(act_book_information, SIGNAL(triggered(bool)), this, SLOT(onTrigger_act_book_information()));
    connect(m_table, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(onDoubleClick_list_book()));
}

void session_user_activity::refershList()
{
    m_table->setRowCount((int) lbooks.size());
    for (int i = 0; i < (int) lbooks.size(); ++i) {
        m_table->setItem(i, 0, new QTableWidgetItem(tr(l_book[i].getCode().c_str())));
        m_table->setItem(i, 1, new QTableWidgetItem(tr(l_book[i].getName().c_str())));
        m_table->setItem(i, 2, new QTableWidgetItem(tr(l_book[i].getAuthor().c_str())));
        m_table->setItem(i, 3, new QTableWidgetItem(tr(l_book[i].getInformation().c_str())));
        m_table->setItem(i, 4, new QTableWidgetItem(tr(std::to_string(l_book[i].getRemain()).c_str())));
    }
}

void session_user_activity::setUiListBook()
{
    m_table = new QTableWidget();

    m_table->setWordWrap(true);
    m_table->setAlternatingRowColors(true);
    m_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_table->setFont(FONT_SIZE_NORMAL);

    m_table->setColumnCount(5);
    m_table->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("ID.")));
    m_table->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("TÊN SÁCH")));
    m_table->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("TÁC GIẢ")));
    m_table->setHorizontalHeaderItem(3, new QTableWidgetItem(tr("MÔ TẢ")));
    m_table->setHorizontalHeaderItem(4, new QTableWidgetItem(tr("SỐ LƯỢNG")));
    m_table->setColumnWidth(1,300);
    m_table->setColumnWidth(2,200);
    m_table->setColumnWidth(3,300);

    for (int i = 0;i < (int) l_book.size(); ++i)
        lbooks.push_back(l_book[i]);
    this->refershList();

    QLabel *hd = new QLabel(tr("Nhấp chuột hai lần để thực hiện yêu cầu mượn sách\n"
                               "Nhấn nút Reset để xem đầy đủ sách"));
    hd->setFont(FONT_SIZE_NORMAL);

    main_layout->addWidget(m_table, 1);
    main_layout->addWidget(hd);
}

void session_user_activity::onClick_btn_reset()
{
    lbooks.clear();
    for (int i = 0;i < (int) l_book.size(); ++i)
        lbooks.push_back(l_book[i]);
    this->refershList();
    edt_search->clear();
}

void session_user_activity::onDoubleClick_list_book() {
    int row = m_table->currentRow();
    view_book_activity *view_book = new view_book_activity(lbooks[row], main_user);
    view_book->show();
}

void session_user_activity::onTrigger_act_book_code() {
    string text = edt_search->text().toStdString();
    lbooks = main_account.findBook_code(text);
    this->refershList();
}

void session_user_activity::onTrigger_act_book_name() {
    string text = edt_search->text().toStdString();
    lbooks = main_account.findBook_name(text);
    this->refershList();
}

void session_user_activity::onTrigger_act_book_author() {
    string text = edt_search->text().toStdString();
    lbooks = main_account.findBook_author(text);
    this->refershList();
}

void session_user_activity::onTrigger_act_book_information() {
    string text = edt_search->text().toStdString();
    lbooks = main_account.findBook_information(text);
    this->refershList();
}
