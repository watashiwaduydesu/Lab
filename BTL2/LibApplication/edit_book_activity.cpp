#include "edit_book_activity.h"

edit_book_activity::edit_book_activity(const book &bk, QWidget *parent)
    : QWidget(parent), m_book(bk)
{
    this->setUI();
    this->setListenEvent();
}

void edit_book_activity::setListenEvent() {
    connect(btn_return, SIGNAL(clicked(bool)), this, SLOT(onClick_btn_return()));
    connect(btn_update, SIGNAL(clicked(bool)), this, SLOT(onClick_btn_update()));
    connect(btn_remove, SIGNAL(clicked(bool)), this, SLOT(onClick_btn_remove()));
}

void edit_book_activity::onClick_btn_update()
{
    QMessageBox *message = new QMessageBox(this);
    message->setFont(FONT_SIZE_NORMAL);
    message->setWindowTitle("Thông báo");
    message->setContentsMargins(20, 20, 20, 20);

    string name = edt_name->text().toStdString();
    string author = edt_author->text().toStdString();
    string info = edt_info->toPlainText().toStdString();
    int number = edt_num->text().toInt();
    int ok = 1;
    if (name.size() < 10) ok = 0;
    else if (author.size() < 10) ok = 0;
    else if (info.size() < 50) ok = 0;
    else if (number <= 0 || number > 1000) ok = 0;

    if (ok) {
        message->setText("Thông tin đã được sửa đổi và cập nhật");
        message->setIcon(QMessageBox::Information);
        book &bk = main_lib.findBook(m_book.getCode());
        main_lib.editBook(bk, name, author, info, number);
    }
    else {
        message->setText("Tên sách và tên tác giả: tối thiểu 10 kí tự không dấu\n"
                          "Phần mô tả sách: tối thiểu 50 kí tự không dấu\n"
                          "Số lượng (cuốn): tối thiểu 1, tối đa 1000");
        message->setIcon(QMessageBox::Warning);
    }
    message->exec();
    if (message->close() && ok) this->reset();
}

void edit_book_activity::onClick_btn_remove()
{
    QMessageBox *message = new QMessageBox();
    message->setWindowTitle("Xác nhận xóa sách");
    message->setText("Bạn thật sự muốn xóa sách này khỏi hệ thống ?");
    message->setFont(FONT_SIZE_NORMAL);
    message->setContentsMargins(20, 20, 20, 20);
    message->setIcon(QMessageBox::Question);
    message->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    message->setButtonText(QMessageBox::Ok, "Xóa");
    message->setButtonText(QMessageBox::Cancel, "Quay trở về");
    message->setDefaultButton(QMessageBox::Cancel);

    int res = message->exec();
    switch (res)
    {
    case QMessageBox::Ok:
        main_lib.removeBook(m_book.getCode());
        this->hide();
        break;

    case QMessageBox::Cancel:
        break;
    }
}

void edit_book_activity::setUI()
{
    this->move(300, 100);
    this->setMinimumWidth(600);
    this->setFont(FONT_SIZE_MEDIUM);
    this->setWindowTitle("Chỉnh sửa thông tin sách");

    main_layout = new QVBoxLayout(this);

    QLabel *title = new QLabel("THÔNG TIN SÁCH");
    title->setFont(FONT_SIZE_XLARGE);
    title->setAlignment(Qt::AlignCenter);
    title->setMargin(30);
    main_layout->addWidget(title);

    QFormLayout *form = new QFormLayout();

    edt_name = new QLineEdit(QString(m_book.getName().c_str()));
    edt_author = new QLineEdit(QString(m_book.getAuthor().c_str()));
    edt_info = new QTextEdit(QString(m_book.getInformation().c_str()));
    edt_num = new QLineEdit(QString(std::to_string(m_book.getRemain()).c_str()));

    edt_name->setMaxLength(MAX_LENGTH_INPUT);
    edt_author->setMaxLength(MAX_LENGTH_INPUT);
    edt_num->setMaxLength(MAX_LENGTH_INPUT);

    QRegExp re;
    re.setPattern(REGEXP_NUMBER_BOOK);
    edt_num->setValidator(new QRegExpValidator(re));

    form->addRow("Mã sách:", new QLabel(tr(m_book.getCode().c_str())));
    form->addRow("Tên sách:", edt_name);
    form->addRow("Tác giả:", edt_author);
    form->addRow("Mô tả:", edt_info);
    form->addRow("Số lượng:", edt_num);

    form->setHorizontalSpacing(25);
    form->setVerticalSpacing(10);
    form->setContentsMargins(20,0,20,0);
    main_layout->addLayout(form);

    QHBoxLayout *layout_btn = new QHBoxLayout();
    btn_return = new QPushButton("Thoát");
    btn_return->setFont(FONT_SIZE_NORMAL);
    btn_update = new QPushButton("Cập nhật");
    btn_update->setFont(FONT_SIZE_NORMAL);
    btn_remove = new QPushButton("Xóa sách");
    btn_remove->setFont(FONT_SIZE_NORMAL);

    layout_btn->addWidget(btn_update);
    layout_btn->addWidget(btn_return);
    layout_btn->addWidget(btn_remove);
    layout_btn->setSpacing(50);
    layout_btn->setAlignment(Qt::AlignCenter);
    layout_btn->setMargin(30);

    main_layout->addLayout(layout_btn);

    main_layout->addStretch(1);
    this->setLayout(main_layout);
}

void edit_book_activity::reset() {
    this->hide();
    this->move(350, 150);
}
