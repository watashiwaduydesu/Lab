#ifndef SESSION_BASE_ACTIVITY_H
#define SESSION_BASE_ACTIVITY_H

#include "account.h"
#include "admin.h"
#include "user.h"
#include "librarian.h"
#include "book.h"
#include "data.h"

#include "changepassword_activity.h"
#include "viewinformation_activity.h"
#include "view_book_activity.h"
#include "history_session_activity.h"

class session_base_activity : public QWidget
{
    Q_OBJECT
public:
    explicit session_base_activity(QWidget *parent = 0);

protected:
    void setUI();
    void addMenuTop();
    void setListenEvent();

    changePassword_activity window_changePassword;
    viewInformation_activity window_viewInformation;
    history_session_activity window_history;

    QVBoxLayout *main_layout;
    QAction *information, *notification, *history, *change_password, *exits;

signals:

public slots:
    void onTrigger_change_password() {window_changePassword.show();}
    void onTrigger_exit() {data::storageData(); qApp->quit();}
    void onTrigger_information() {window_viewInformation.show();}
    void onTrigger_history() {window_history.show();}

public:
    void closeEvent(QCloseEvent *) {
        data::storageData();
        qApp->quit();
    }
};

#endif // SESSION_BASE_ACTIVITY_H
