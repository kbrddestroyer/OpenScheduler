#include <string>
#include <iostream>

#include <login/Login.hpp>
#include <database/Database.hpp>
#include <database/Backend.hpp>


int main() {
    const auto backend = Database::g_backend_instance();
    const Database::Host host = {
        "localhost:3306",
        "root",
        "root",
        "unit_tests"
    };

    if (!backend->connect(host)) {
        std::cerr << "Could not connect to database!" << std::endl;
        return -1;
    }

    std::cout << backend.use_count() << std::endl;

    std::string username, passwd;

    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> passwd;

    if (Login::Login login({username, passwd}); login.tryRegister())
        std::cout << "Register success!" << std::endl;
    else
        std::cerr << "Could not register account" << std::endl;

    return 0;
}