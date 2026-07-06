#include "OpenScheduler.h"
#include <QtWidgets/QApplication>
#include <database/Database.hpp>

#include <filesystem>
#include <QMessageBox>

#include "config/DatabaseConfig.hpp"
#include "registry/g_registry.hpp"


int main(int argc, char *argv[])
{
    const auto backend = Utils::Singleton<Database::Database>::instance();
    const std::string path = std::filesystem::absolute("resources/database.conf").string();

    OpenScheduler::DatabaseConfig db_config ( path );

    if ( ! db_config.prepare() ) {
        // MessageBox call
        return 1;
    }

    if ( ! db_config.parse() ) {
        // MessageBox call
        return 2;
    }

    const Database::Host host = {
        db_config.HOST(),
        db_config.LOGIN(),
        db_config.PASSWORD(),
        db_config.SCHEMA()
    };

    QApplication application(argc, argv);
    OpenScheduler::OpenScheduler w;
    w.show();

    if (!backend->connect(host)) {
        QMessageBox mbox;
        mbox.setText("Could not connect to database host!");
        mbox.exec();
        return -1;
    }

    OpenScheduler::sync_global_registry();

    return application.exec();
}
