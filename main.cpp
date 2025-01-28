#include "OpenScheduler.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OpenScheduler w;
    w.show();
    return a.exec();
}
