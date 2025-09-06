#ifndef TESTDAO_HPP
#define TESTDAO_HPP

#include <string>
#include <Database.hpp>


class TestDAO final : public Database::DAOBase {
public:
    TestDAO() = delete;
    explicit TestDAO(const sql::ResultSet * rs) :
        id (rs->getInt("id")),
        name(rs->getString("name")) {}

    [[nodiscard]] uint32_t getID() const noexcept { return id; }
    [[nodiscard]] std::string getName() const noexcept { return name; }
private:
    uint32_t id;
    std::string name;
};

#endif //TESTDAO_HPP
