#ifndef SIGN_IN_ACTIVITY_H
#define SIGN_IN_ACTIVITY_H

#include "macro.h"
#include "library.h"
#include "library_ui.h"

#include "account.h"
#include "admin.h"
#include "user.h"
#include "librarian.h"
#include "book.h"

#include "external.h"

class sign_in_activity : public QWidget
{
    Q_OBJECT
public:
    explicit sign_in_activity(QWidget *parent = 0);

private:
    void setUI();
    void reset();
    void setListenEvent();

    QVBoxLayout *main_layout;
    QLabel *title;
    QFormLayout *form;
    QLineEdit *account_name, *password;
    QHBoxLayout *layout_btn;
    QPushButton *btn_send_sign_in, *btn_cancle;

signals:
    void signInSucceed();

public slots:
    void onClick_btn_send_sign_in();
    void onClick_btn_cancle() {this->reset();}

public:
    void closeEvent(QCloseEvent *) {this->reset();}
};

#endif // SIGN_IN_ACTIVITY_H
