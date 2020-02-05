#include "dialerwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialerWindow w;
    w.show();
    return a.exec();
}
