#include "MySqlBackend.hpp"


namespace Database::MySQL {
    MySQLBackend::MySQLBackend() {
        driver = get_driver_instance();
    }

    bool MySQLBackend::connect(const Host& host) {
        if (isConnected())
            return true;    // No need to connect twice

        if (!driver)
            return false;

        sql::Connection * conn = driver->connect(
            host.hostname,
            host.username,
            host.password
        );

        connection = std::unique_ptr<sql::Connection>(conn);

        if (!connection)
            return false;

        connection->setSchema(host.database);
        return true;
    }

    void MySQLBackend::disconnect() {
        connection->close();
    }

    bool MySQLBackend::isConnected() {
        return connection != nullptr;
    }
} // MySQL
// Database