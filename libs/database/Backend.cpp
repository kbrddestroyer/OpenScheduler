#include "Backend.hpp"

#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>

namespace Database {
    bool Backend::connect(const Host &host) {
        if (driver)  // Already connected
            return connection->isValid();

        driver = get_driver_instance();

        if (!driver)
            return false;
        try {
            this->connection = std::unique_ptr<sql::Connection>(
                driver->connect(
                    host.hostname,
                    host.username,
                    host.password
                )
            );
        }
        catch (sql::SQLException &e) {
            return false;
        }

        if (!connection)
            return false;

        connection->setSchema(host.dbname);
        return true;
    }

    void Backend::close() const {
        if ( driver && connection->isValid() )
            connection->close();
    }

    std::shared_ptr<sql::ResultSet> Backend::executeQuery(const std::string_view &query) const {
        const auto stmt = std::unique_ptr<sql::Statement>(connection->createStatement());
        return std::shared_ptr<sql::ResultSet>( stmt->executeQuery(query.data()) );
    }

    uint32_t Backend::executeUpdate(const std::string_view &query) const {
        const auto stmt = std::unique_ptr<sql::Statement>(connection->createStatement());
        return stmt->executeUpdate(query.data());
    }
}
