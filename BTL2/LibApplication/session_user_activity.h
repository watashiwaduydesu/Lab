#ifndef SESSION_USER_ACTIVITY_H
#define SESSION_USER_ACTIVITY_H

#include "session_base_activity.h"
#include "library_ui.h"

class session_user_activity : public session_base_activity
{
    Q_OBJECT
public:
    explicit session_user_activity(QWidget *parent = 0);

private:
    void setUI2();
    void setListenEvent2();
    void refershList();
    void setUiListBook();

    QLineEdit *edt_search;
    QAction *act_book_code, *act_book_name, *act_book_author, *act_book_information;
    QPushButton *btn_reset;
    QTableWidget *m_table;

    vector<book> lbooks;

signals:

public slots:
    void onClick_btn_reset();
    void onDoubleClick_list_book();
    void onTrigger_act_book_code();
    void onTrigger_act_book_name();
    void onTrigger_act_book_author();
    void onTrigger_act_book_information();
};

#endif // SESSION_USER_ACTIVITY_H
