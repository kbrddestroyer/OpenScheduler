#ifndef HOST_HPP
#define HOST_HPP

#include <string>

namespace Database {

struct Host {
    std::string hostname;
    uint16_t port;

    std::string username;
    std::string password;
    std::string database;
};

} // Database

#endif //HOST_HPP
