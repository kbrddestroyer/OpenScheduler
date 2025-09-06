#include "Backend.hpp"
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>

namespace Database {
    bool Backend::connect(const Host &host) {
        driver = get_driver_instance();

        if (!driver)
            return false;

        this->connection = std::unique_ptr<sql::Connection>(
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

    std::shared_ptr<sql::ResultSet> Backend::executeQuery(const std::string_view &query) const {
        sql::Statement *stmt = connection->createStatement();
        return std::shared_ptr<sql::ResultSet>( stmt->executeQuery(query.data()) );
    }
}
