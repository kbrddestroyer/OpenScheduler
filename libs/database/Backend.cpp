#include "Backend.hpp"

#include <sstream>
#include <cppconn/statement.h>

namespace Database {
    bool Backend::connect(const Host &host) {
        driver = get_driver_instance();

        if (!driver)
            return false;

        connection = std::unique_ptr<sql::Connection>(
            driver->connect(
                host.hostname,
                host.username,
                host.password
            )
        );

        if (!connection)
            return false;

        connection->setSchema(host.dbname);
        return true;
    }
}
