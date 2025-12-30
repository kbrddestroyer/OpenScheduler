#include "OpenScheduler.h"
#include <QtWidgets/QApplication>

#include <database/Database.hpp>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    const auto backend = Utils::Singleton<Database::Database>::instance();
    const Database::Host host = {
        "localhost:3306",
        "root",
        "root",
        "openscheduler_main"
    };

    if (!backend->connect(host)) {
        QMessageBox mbox;
        mbox.setText("Could not connect to database host!");
        mbox.exec();
        return -1;
    }


    QApplication application(argc, argv);
    OpenScheduler::OpenScheduler w;
    w.show();
    return application.exec();
}
