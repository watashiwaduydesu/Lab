#include "session_librarian_activity.h"
#include "table_list_book.h"
#include "table_list_userbook.h"
#include "table_list_require.h"
#include "table_add_book.h"

session_librarian_activity::session_librarian_activity(QWidget *parent)
    : session_base_activity(parent)
{
    this->setUI2();
}

void session_librarian_activity::setUI2() {
    this->setMinimumHeight(600);
    this->setMinimumWidth(1000);
    QLabel *title = new QLabel("Chức năng của thủ thư (Librarian):");
    title->setFont(FONT_SIZE_NORMAL_BOLD);
    this->setContentsMargins(10, 5, 0, 10);
    main_layout->addWidget(title);
    main_layout->addSpacing(15);

    tab = new QTabWidget();
    tabBook = new table_list_book();
    tabUserBook = new table_list_userbook();
    tabRequire = new table_list_require();
    tabAddBook = new table_add_book();

    tab->addTab(tabBook, tr("BIÊN TẬP SÁCH"));
    tab->addTab(tabAddBook, tr("THÊM SÁCH MỚI"));
    tab->addTab(tabRequire, tr("XỬ LÝ YÊU CẦU MƯỢN SÁCH"));
    tab->addTab(tabUserBook, tr("SÁCH ĐANG MƯỢN"));

    main_layout->addWidget(tab);
}
