#ifndef START_ACTIVITY_H
#define START_ACTIVITY_H

#include "macro.h"
#include "library.h"
#include "library_ui.h"
#include "account.h"
#include "admin.h"
#include "user.h"
#include "librarian.h"
#include "book.h"
#include "data.h"
#include "external.h"

class sign_in_activity;
class sign_up_activity;
class session_user_activity;
class session_librarian_activity;
class session_admin_activity;

class start_activity : public QWidget
{
    Q_OBJECT
public:
    explicit start_activity(QWidget *parent = 0);

private:
    void setUI();
    void setListenEvent();

    QVBoxLayout *main_layout;
    QLabel *title, *text_1;
    QLineEdit *edt_search;
    QHBoxLayout *layout_top, *layout_search;
    QPushButton *btn_sign_up, *btn_sign_in, *btn_quit, *btn_search;

    sign_in_activity *window_sign_in;
    sign_up_activity *window_sign_up;
    session_user_activity *window_user_session;
    session_librarian_activity *window_lib_session;
    session_admin_activity *window_admin_session;

signals:

public slots:
    void onClick_btn_sign_up();
    void onClick_btn_sign_in();
    void onClick_btn_quit() {data::storageData(); qApp->quit();}
    void open_window_session();

public:
    void closeEvent(QCloseEvent *) {
        data::storageData(); qApp->quit();
    }
};

#endif // START_ACTIVITY_H
