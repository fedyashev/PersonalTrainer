#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), controller(0)
{
    controller = new CClientController(new QTcpSocket(), this);

    this->setWindowTitle("Authorization");

    grid = new QGridLayout();
    label1 = new QLabel("Login");
    label1->setAlignment(Qt::AlignLeft);
    label2 = new QLabel("Password");
    label2->setAlignment(Qt::AlignLeft);
    line1 = new QLineEdit();
    line1->setFixedWidth(100);
    line2 = new QLineEdit();
    line2->setFixedWidth(100);
    button1 = new QPushButton("Enter");
    button2 = new QPushButton("Registration");

    grid->addWidget(label1, 0, 0, 1, 1);
    grid->addWidget(line1, 0, 1, 1, 1);
    grid->addWidget(label2, 1, 0, 1, 1);
    grid->addWidget(line2, 1, 1, 1, 1);
    grid->addWidget(button1, 2, 0, 1, 2);
    grid->addWidget(button2, 3, 0, 1, 2);

    setLayout(grid);

    setFixedSize(sizeHint());

    initConnections();

}

MainWindow::~MainWindow()
{

}

void MainWindow::initConnections()
{
    connect(button1, SIGNAL(clicked(bool)), controller, SIGNAL(connectToHost()));
}
