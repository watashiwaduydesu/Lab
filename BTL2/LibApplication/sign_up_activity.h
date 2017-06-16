#ifndef SIGN_UP_ACTIVITY_H
#define SIGN_UP_ACTIVITY_H

// GIAO DIEN DANG KI TAI KHOAN

#include "macro.h"
#include "library.h"
#include "library_ui.h"

#include "account.h"
#include "admin.h"
#include "user.h"
#include "librarian.h"
#include "book.h"

#include "external.h"

class sign_up_activity : public QWidget
{
    Q_OBJECT
public:
    explicit sign_up_activity(QWidget *parent = 0);

private:
    void setUI();
    void reset();
    void setListenEvent();

    QVBoxLayout *main_layout;
    QLabel *title;
    QFormLayout *form;
    QLineEdit *account_name, *password_1, *password_2;
    QLineEdit *id, *email, *username, *telephone;
    QDateEdit *birth_date;
    QHBoxLayout *layout_btn;
    QPushButton *btn_send_sign_up, *btn_cancle;

signals:

public slots:
    void onClick_btn_send_sign_up();
    void onClick_btn_cancle() {this->reset();}

public:
    void closeEvent(QCloseEvent *) {this->reset();}
};

#endif // SIGN_UP_ACTIVITY_H
