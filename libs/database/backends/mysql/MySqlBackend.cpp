#include "MySqlBackend.hpp"


namespace Database::MySQL {
    MySQLBackend::MySQLBackend() {
        driver = get_driver_instance();
    }


    bool MySQLBackend::connect(const Host& host) {
        if (!driver)
            return false;

        connection.reset(driver->connect(
            host.hostname,
            host.username,
            host.password
        ));

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