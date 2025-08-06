#ifndef MYSQLBACKEND_HPP
#define MYSQLBACKEND_HPP

#include <Backend.hpp>

#include <memory>
#include <cppconn/driver.h>

namespace Database::MySQL {

class MySQLBackend : public Backend {
public:
    MySQLBackend();
    ~MySQLBackend() override = default;

    bool connect(const Host& host) override;
    void disconnect() override;
    bool isConnected() override;

    sql::Driver * getDriver() const { return driver; }
private:
    sql::Driver *driver = nullptr;
    std::unique_ptr<sql::Connection> connection;
};

} // MySQL
// Database

#endif //MYSQLBACKEND_HPP
