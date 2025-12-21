#include "OpenScheduler.h"
#include <QtWidgets/QApplication>

#include <database/Database.hpp>
#include <Windows.h>


int main(int argc, char *argv[])
{
    const auto backend = Database::g_backend_instance();
    const Database::Host host = {
        "localhost:3306",
        "root",
        "root",
        "unit_tests"
    };

    if (!backend->connect(host)) {
        MessageBox(
            nullptr,
            L"Could not connect to database host!",
            L"Error!",
            MB_OK | MB_ICONERROR
        );
        return -1;
    }


    QApplication application(argc, argv);
    OpenScheduler::OpenScheduler w;
    w.show();
    return application.exec();
}
