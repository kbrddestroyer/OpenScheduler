#ifndef TESTDAO_HPP
#define TESTDAO_HPP

#include <format>
#include <string>
#include <string_view>
#include <Database.hpp>


class TestDAO final : public Database::DAOBase {
public:
    TestDAO() = delete;
    explicit TestDAO(const sql::ResultSet * rs) :
        id (rs->getInt("id")),
        name(rs->getString("name")) {}

    TestDAO(const uint32_t id, std::string name) : id(id), name(name.c_str()) {}

    [[nodiscard]] uint32_t getID() const noexcept { return id; }
    [[nodiscard]] std::string getName() const noexcept { return name; }

    [[nodiscard]] std::string getUpdateQuery() const override {
        std::stringstream ss;

        ss << "name=\'" << name << "\', ";
        ss << "id=" << id;
        return { ss.str().c_str() };
    }
private:
    uint32_t id;
    std::string name;
};

#endif //TESTDAO_HPP
