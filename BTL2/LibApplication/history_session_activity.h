#ifndef HISTORY_SESSION_ACTIVITY_H
#define HISTORY_SESSION_ACTIVITY_H

#include "library.h"
#include "library_ui.h"
#include "macro.h"

#include "account.h"
#include "user.h"
#include "librarian.h"
#include "admin.h"
#include "book.h"
#include "user_book.h"

class history_session_activity : public QWidget
{
    Q_OBJECT
public:
    explicit history_session_activity(QWidget *parent = 0);

private:
    void setUI();
    void reset();

    QVBoxLayout *main_layout;


signals:

public slots:

public:
    void closeEvent(QCloseEvent *) {this->reset();}
};

#endif // HISTORY_SESSION_ACTIVITY_H
