#ifndef BACKEND_HPP
#define BACKEND_HPP

#include <string>
#include <memory>
#include <vector>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>

namespace Database {
    struct Host {
        std::string hostname;
        std::string username;
        std::string password;
        std::string dbname;
    };

    class DAOBase {
    public:
        virtual ~DAOBase() = default;
    };

    class Backend {
    public:
        virtual ~Backend() = default;

        bool connect(const Host &);
        template <typename K, class DAO>
        DAOBase * getByID(const std::string&, const std::string&, K key);
    protected:
        sql::Driver * driver = nullptr;
        std::unique_ptr<sql::Connection> connection;
    };
}

#include "Backend.ipp"
#endif //BACKEND_HPP
