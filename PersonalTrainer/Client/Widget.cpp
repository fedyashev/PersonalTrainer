#include "Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Personal Trainer - Authorization");

    grid = new QGridLayout();

    label1 = new QLabel("Login");
    label1->setAlignment(Qt::AlignLeft);

    label2 = new QLabel("Password");
    label2->setAlignment(Qt::AlignLeft);

    ledit1 = new QLineEdit();
    ledit1->setFixedWidth(100);

    ledit2 = new QLineEdit();
    ledit2->setFixedWidth(100);

    button1 = new QPushButton("Enter");
    button2 = new QPushButton("Registration");

    grid->addWidget(label1, 0, 0);
    grid->addWidget(ledit1, 0, 1);
    grid->addWidget(label2, 1, 0);
    grid->addWidget(ledit2, 1, 1);
    grid->addWidget(button1, 2, 0, 1, 2);
    grid->addWidget(button2, 3, 0, 1, 2);

    this->setLayout(grid);

    this->setFixedSize(this->sizeHint());

    connect(button1, SIGNAL(clicked()), this, SLOT(button1OnClick()));
    connect(this, SIGNAL(authorization(QString,QString)) , &client, SLOT(connectToServer(QString,QString)));
    connect(&client, SIGNAL(showMessageDialog(QString)), this, SLOT(showMessageDialog(QString)));
}

Widget::~Widget()
{

    delete label1;
    delete label2;
    delete button1;
    delete button2;
    delete ledit1;
    delete ledit2;
    delete grid;
}

void Widget::button1OnClick()
{
    emit authorization(ledit1->text(), ledit2->text());
}

void Widget::showMessageDialog(const QString &msg)
{
    QDialog dialog(this);
    QGridLayout layout;
    QLabel label(msg);
    layout.addWidget(&label);
    dialog.setLayout(&layout);
    dialog.exec();
}
