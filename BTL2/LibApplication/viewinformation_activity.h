#ifndef VIEWINFORMATION_ACTIVITY_H
#define VIEWINFORMATION_ACTIVITY_H

#include "macro.h"
#include "library.h"
#include "library_ui.h"

#include "account.h"
#include "admin.h"
#include "user.h"
#include "librarian.h"
#include "book.h"

#include "external.h"

class viewInformation_activity : public QWidget
{
    Q_OBJECT
public:
    explicit viewInformation_activity(QWidget *parent = 0);

private:
    void setUI();
    void reset();
    void setListenEvent();

    QVBoxLayout *main_layout;
    QLabel *title;
    QFormLayout *form;
    QHBoxLayout *layout_btn;
    QPushButton *btn_return;

signals:

public slots:
    void onClick_btn_return() {this->reset();}

public:
    void closeEvent(QCloseEvent *) {this->reset();}
};

#endif // VIEWINFORMATION_ACTIVITY_H
