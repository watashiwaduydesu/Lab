#include "mytable.h"
#include "macro.h"

MyTable::MyTable(QWidget *parent) : QWidget(parent)
{
    main_layout = new QVBoxLayout();

    table = new QTableWidget(this);
    table->setWordWrap(true);
    table->setAlternatingRowColors(true);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setFont(FONT_SIZE_NORMAL);

    main_layout->addWidget(table);
    setLayout(main_layout);
}

void MyTable::addRow()
{
    this->table->insertRow(this->table->rowCount());
}

void MyTable::deleteRow()
{
    this->table->removeRow(this->table->currentRow());
}
