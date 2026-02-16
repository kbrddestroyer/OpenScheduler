/**/
#include <iostream>
#include <filesystem>

#include <login/Login.hpp>
#include <database/Database.hpp>

// From client/ folder
#include "DatabaseConfig.hpp"


#define


int main(int __argc, char __argv[]) {
    const auto backend = Utils::Singleton<Database::Database>::instance();
    const std::string path = std::filesystem::absolute("resources/database.conf").string();

    OpenScheduler::DatabaseConfig db_config { path };

    if ( !db_config.prepare() || db_config.parse() ) {
        std::cerr << "Could not parse config." << std::endl;
        return 1;
    }

    const Database::Host host = {
        db_config.HOST(),
        db_config.LOGIN(),
        db_config.PASSWORD(),
        db_config.SCHEMA()
    };

    if (!backend->connect( host )) {
        std::cerr << "Could not connect to database host." << std::endl;
        return 2;
    }

    if (
        const Login::Login login( {username, passwd} )
    )
}
