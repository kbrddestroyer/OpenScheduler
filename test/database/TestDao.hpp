#ifndef TESTDAO_HPP
#define TESTDAO_HPP

#include <format>
#include <string>

#include <Database.hpp>


class TestDAO final : public Database::DAOBase {
public:
    TestDAO() = delete;
    explicit TestDAO(const sql::ResultSet * rs) :
        id (rs->getInt("id")),
        name(rs->getString("name")) {}

    TestDAO(const uint32_t id, const std::string& name) : id(id), name(name) {}

    [[nodiscard]] uint32_t getID() const noexcept { return id; }
    [[nodiscard]] std::string getName() const noexcept { return name; }

    [[nodiscard]] const std::string getUpdateQuery() const override {
        return std::format("name=\'{}\'", name).c_str();
    }
private:
    uint32_t id;
    std::string name;
};

#endif //TESTDAO_HPP
