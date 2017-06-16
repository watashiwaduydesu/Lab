#ifndef MYTABLE_H
#define MYTABLE_H

#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>

class MyTable : public QWidget
{
    Q_OBJECT
public:
    explicit MyTable(QWidget *parent = 0);

protected:
    QTableWidget *table;
    QVBoxLayout *main_layout;

signals:

public slots:
    void addRow();
    void deleteRow();
};

#endif // MYTABLE_H
