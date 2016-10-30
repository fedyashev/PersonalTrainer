#include <QApplication>
//#include <QCoreApplication>
#include "Widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QCoreApplication a(argc, argv);

    Widget w;
    w.show();

//    ClientController *controller = new ClientController(new QTcpSocket());
//    ClientController controller(new QTcpSocket());

//    controller.getLoginWidget()->show();

    return a.exec();
}
