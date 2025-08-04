#ifndef MYSQLBACKEND_HPP
#define MYSQLBACKEND_HPP

#include <Backend.hpp>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include <memory>

namespace Database::MySQL {

class MySQLBackend : public Backend {
public:
    MySQLBackend();
    ~MySQLBackend() override = default;

    bool connect(const Host& host) override;
    void disconnect() override;
    bool isConnected() override;
private:
    sql::Driver *driver = nullptr;
    std::unique_ptr<sql::Connection> connection;
};

} // MySQL
// Database

#endif //MYSQLBACKEND_HPP
