#ifndef BACKEND_HPP
#define BACKEND_HPP

#include <string>
#include <memory>
#include <cppconn/driver.h>

#include <Singleton.hpp>
#include <cppconn/resultset.h>

namespace Database {
    struct Host {
        std::string hostname;
        std::string username;
        std::string password;
        std::string dbname;
    };

    class Backend : Utils::Singleton<Backend> {
    public:
        bool connect(const Host &);
        [[nodiscard]] std::shared_ptr<sql::ResultSet> executeQuery(const std::string_view&) const;
        [[nodiscard]] uint32_t executeUpdate(const std::string_view&) const;
    protected:
        sql::Driver * driver = nullptr;
        std::unique_ptr<sql::Connection> connection;
    };
}

#endif //BACKEND_HPP
