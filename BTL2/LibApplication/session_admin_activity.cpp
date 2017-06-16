#include "session_admin_activity.h"
#include "table_list_book.h"
#include "table_list_account.h"
#include "table_list_userbook.h"
#include "table_list_require.h"
#include "table_add_book.h"
#include "table_list_signup.h"

session_admin_activity::session_admin_activity(QWidget *parent)
    : session_base_activity(parent)
{
    this->setUI2();
}

void session_admin_activity::setUI2()
{
    this->setMinimumHeight(600);
    this->setMinimumWidth(1000);
    QLabel *title = new QLabel("Chức năng của quản trị hệ thống thư viện (Admin):");
    title->setFont(FONT_SIZE_NORMAL_BOLD);
    this->setContentsMargins(10, 5, 0, 10);
    main_layout->addWidget(title);
    main_layout->addSpacing(15);

    tab = new QTabWidget();
    tabAcc = new table_list_account();
    tabBook = new table_list_book();
    tabAddBook = new table_add_book();
    tabRequire = new table_list_require();
    tabUserBook = new table_list_userbook();
    tabSignUp = new table_list_signup();

    tab->addTab(tabAcc, tr("DANH SÁCH TÀI KHOẢN"));
    tab->addTab(tabSignUp, tr("XỬ LÝ YÊU CẦU ĐĂNG KÍ TÀI KHOẢN"));
    tab->addTab(tabBook, tr("BIÊN TẬP SÁCH"));
    tab->addTab(tabAddBook, tr("THÊM SÁCH MỚI"));
    tab->addTab(tabRequire, tr("XỬ LÝ YÊU CẦU MƯỢN SÁCH"));
    tab->addTab(tabUserBook, tr("SÁCH ĐANG MƯỢN"));

    main_layout->addWidget(tab);
}
