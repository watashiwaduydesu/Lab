#ifndef CHANGEPASSWORD_ACTIVITY_H
#define CHANGEPASSWORD_ACTIVITY_H

#include "macro.h"
#include "library.h"
#include "library_ui.h"

#include "account.h"
#include "admin.h"
#include "user.h"
#include "librarian.h"
#include "book.h"

#include "external.h"

class changePassword_activity : public QWidget
{
    Q_OBJECT
public:
    explicit changePassword_activity(QWidget *parent = 0);

private:
    void setUI();
    void reset();
    void setListenEvent();

    QVBoxLayout *main_layout;
    QLabel *title;
    QFormLayout *form;
    QLineEdit *password_cur, *password_new, *password_again;
    QHBoxLayout *layout_btn;
    QPushButton *btn_submit, *btn_cancle;

signals:

public slots:
    void onClick_btn_submit();
    void onClick_btn_cancle() {this->reset();}

public:
    void closeEvent(QCloseEvent *) {this->reset();}
};

#endif // CHANGEPASSWORD_ACTIVITY_H
