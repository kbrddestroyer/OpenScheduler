#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <Singleton.hpp>
#include <memory>

#include "Backend.hpp"
namespace Database {

typedef std::shared_ptr<sql::ResultSet> DatabaseResult;

class Database final : Utils::Singleton<Database> {
public:
    Database() = default;
    ~Database() override;

    [[nodiscard]] bool connect(const Host & /* host */);

    [[nodiscard]] DatabaseResult executeQuery(const std::string_view & /* query */) const;
    [[nodiscard]] uint32_t executeUpdate(const std::string_view & /* query */) const;
private:
    Backend connection_;
};

} // Database

#endif //DATABASE_HPP
