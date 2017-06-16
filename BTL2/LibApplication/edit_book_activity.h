#ifndef EDIT_BOOK_ACTIVITY_H
#define EDIT_BOOK_ACTIVITY_H

#include "macro.h"
#include "library.h"
#include "library_ui.h"

#include "account.h"
#include "admin.h"
#include "user.h"
#include "librarian.h"
#include "book.h"

#include "external.h"

class edit_book_activity : public QWidget
{
    Q_OBJECT
public:
    explicit edit_book_activity(const book &bk, QWidget *parent = 0);

private:
    void setUI();
    void reset();
    void setListenEvent();

    QVBoxLayout *main_layout;
    QPushButton *btn_return, *btn_update, *btn_remove;
    QLineEdit *edt_name, *edt_author, *edt_num;
    QTextEdit *edt_info;

    book m_book;

signals:

public slots:
    void onClick_btn_return() {this->reset();}
    void onClick_btn_update();
    void onClick_btn_remove();

public:
    void closeEvent(QCloseEvent *) {this->reset();}
};

#endif // EDIT_BOOK_ACTIVITY_H
