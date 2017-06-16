#ifndef EDIT_ACCOUNT_ACTIVITY_H
#define EDIT_ACCOUNT_ACTIVITY_H

#include "macro.h"
#include "library.h"
#include "library_ui.h"

#include "account.h"
#include "admin.h"
#include "user.h"
#include "librarian.h"
#include "book.h"

#include "external.h"

class edit_account_activity : public QWidget
{
    Q_OBJECT
public:
    explicit edit_account_activity(const account &acc, QWidget *parent = 0);

private:
    void setUI();
    void setListenEvent();
    void reset();

    QVBoxLayout *main_layout;
    QPushButton *btn_return, *btn_update, *btn_remove;
    QButtonGroup *grp_role, *grp_state;
    QRadioButton *btn_admin, *btn_lib, *btn_user;
    QRadioButton *btn_active, *btn_disabled;
    QLineEdit *edt_username, *edt_email, *edt_id, *edt_phone, *edt_password;
    QPushButton *btn_change_password;
    QDateEdit *edt_birth;

    account m_account;

signals:

public slots:
    void onClick_btn_return() {this->reset();}
    void onClick_btn_update();
    void onClick_btn_remove();
    void onClick_btn_change_password();

public:
    void closeEvent(QCloseEvent *) {this->reset();}
};

#endif // EDIT_ACCOUNT_ACTIVITY_H
