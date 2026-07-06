#include "CustomerDao.hpp"
#include <format>


namespace OpenScheduler::Dao {
    CustomerDao::CustomerDao(const sql::ResultSet * rs) {
        id_ = rs->getInt("id");
        name_ = rs->getString("name");
    }

    const std::string CustomerDao::getUpdateQuery() const {
        return std::format(
                R"(id={}, name="{}")",
                id_, name_
                );
    }
} // OpenScheduler