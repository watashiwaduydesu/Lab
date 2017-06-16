#ifndef SESSION_ACTIVITY_H
#define SESSION_ACTIVITY_H

#include "macro.h"
#include "library.h"
#include "library_ui.h"

#include "account.h"
#include "admin.h"
#include "user.h"
#include "librarian.h"
#include "book.h"
#include "data.h"

#include "changepassword_activity.h"
#include "viewinformation_activity.h"

class session_activity : public QWidget // PHIEN LAM VIEC CUA NGUOI DUNG
{
    Q_OBJECT
public:
    explicit session_activity(QWidget *parent = 0);

private:

    void setUI();

    void setListenEvent();
    void addMenuTop();
    void addFunctionUser(); // chuc nang nguoi dung
    void addFunctionAdmin(); // chuc nang admin
    void addFunctionLibrarian(); // chuc nang thu thu

    void showBook(book &bk);  // hien thi mot quyen sach

    changePassword_activity window_changePassword;
    viewInformation_activity window_viewInformation;

    QVBoxLayout *main_layout;

    // menu top
    QHBoxLayout *layout_menu_top;
    QMenuBar *menu_left, *menu_right;
    QAction *information, *notification, *history, *change_password, *exit;
    // area show working
    QGridLayout *area;
    QScrollArea *scrollarea;

signals:

public slots:
    void onTrigger_change_password() {window_changePassword.show();}
    void onTrigger_exit() {data::storageData(); qApp->quit();}
    void onTrigger_information() {window_viewInformation.show();}
    void onTrigger_act_book_code();
    void onTrigger_act_book_name();
    void onTrigger_act_book_author();
    void onTrigger_act_book_information();
    void onTrigger_act_add_book();
    void onTrigger_act_find_book();
    void onTrigger_act_require_book();
    void onTrigger_act_borrow_book();
    void onTrigger_act_owe_book();

public:
    void closeEvent(QCloseEvent *) {
        data::storageData();
        qApp->quit();
    }

private:
    QLineEdit *edt_search;
    QAction *act_book_code, *act_book_name, *act_book_author, *act_book_information;
    QAction *act_add_book, *act_find_book;
    QAction *act_require_book, *act_borrow_book, *act_owe_book;
};

#endif // SESSION_ACTIVITY_H
