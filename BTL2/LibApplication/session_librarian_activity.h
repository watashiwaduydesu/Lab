#ifndef SESSION_LIBRARIAN_ACTIVITY_H
#define SESSION_LIBRARIAN_ACTIVITY_H

#include "session_base_activity.h"
#include <QTabWidget>

class table_list_book;
class table_list_userbook;
class table_list_require;
class table_add_book;

class session_librarian_activity : public session_base_activity
{
    Q_OBJECT
public:
    explicit session_librarian_activity(QWidget *parent = 0);

private:
    void setUI2();

    QTabWidget *tab;
    table_list_book *tabBook;
    table_add_book *tabAddBook;
    table_list_userbook *tabUserBook;
    table_list_require *tabRequire;

signals:

public slots:

};


#endif // SESSION_LIBRARIAN_ACTIVITY_H
