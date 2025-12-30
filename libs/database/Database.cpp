#include "Database.hpp"

namespace Database {
    Database::~Database() {
        connection_.close();
    }

    bool Database::connect(const Host &host)
    {
        return connection_.connect(host);
    }

    DatabaseResult Database::executeQuery(const std::string_view &query) const {
        return connection_.executeQuery(query);
    }

    uint32_t Database::executeUpdate(const std::string_view &query) const {
        return connection_.executeUpdate(query);
    }

} // Database