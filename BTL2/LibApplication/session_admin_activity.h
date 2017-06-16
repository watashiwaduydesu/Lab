#ifndef SESSION_ADMIN_ACTIVITY_H
#define SESSION_ADMIN_ACTIVITY_H

#include "session_base_activity.h"
#include <QTabWidget>

class table_list_account;
class table_list_signup;
class table_list_require;
class table_list_book;
class table_add_book;
class table_list_userbook;

class session_admin_activity : public session_base_activity
{
    Q_OBJECT
public:
    explicit session_admin_activity(QWidget *parent = 0);

private:
    void setUI2();

    QTabWidget *tab;
    table_list_book *tabBook;
    table_list_account *tabAcc;
    table_list_userbook *tabUserBook;
    table_list_require *tabRequire;
    table_add_book *tabAddBook;
    table_list_signup *tabSignUp;

signals:

public slots:

};

#endif // SESSION_ADMIN_ACTIVITY_H
