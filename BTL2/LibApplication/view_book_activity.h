#ifndef VIEW_BOOK_ACTIVITY_H
#define VIEW_BOOK_ACTIVITY_H

#include "macro.h"
#include "library.h"
#include "library_ui.h"

#include "account.h"
#include "admin.h"
#include "user.h"
#include "librarian.h"
#include "book.h"

#include "external.h"

class view_book_activity : public QWidget
{
    Q_OBJECT
public:
    explicit view_book_activity(const book &bk, const user &user, QWidget *parent = 0);

private:
    void setUI();
    void reset();
    void setListenEvent();
    void addDateRequire();

    QVBoxLayout *main_layout;
    QPushButton *btn_return, *btn_require;
    QDateEdit *beginDate, *endDate;

    book m_book;
    user m_user;
    bool enableRequire;
    bool checkEnableRequire();

signals:

public slots:
    void onClick_btn_return() {this->reset();}
    void onClick_btn_require();

public:
    void closeEvent(QCloseEvent *) {this->reset();}
};

#endif // VIEW_BOOK_ACTIVITY_H
