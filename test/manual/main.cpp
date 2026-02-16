#include <string>
#include <iostream>

#include <login/Login.hpp>
#include <database/Database.hpp>
#include <database/Backend.hpp>


int main() {
    const auto backend = Utils::Singleton<Database::Database>::instance();
    const Database::Host host = {
        "localhost:3306",
        "root",
        "root",
        "openscheduler_main"
    };

    if (!backend->connect(host)) {
        std::cerr << "Could not connect to database!" << std::endl;
        return -1;
    }
    std::string username, passwd;

    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> passwd;

    if (const Login::Login login({username, passwd}); login.tryRegister())
        std::cout << "Register success!" << std::endl;
    else
        std::cerr << "Could not register account" << std::endl;

    return 0;
}