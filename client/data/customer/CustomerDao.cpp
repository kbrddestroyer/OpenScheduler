
#include "CustomerDao.hpp"

#include <format>

namespace OpenScheduler {
    CustomerDao::CustomerDao(const sql::ResultSet *rs) :
        id_(rs->getInt("id")),
        name_(rs->getString("name"))
    {}

    const std::string CustomerDao::getUpdateQuery() const noexcept {
        return std::format(
            "name=\'{}\'",
            name_
        );
    }
} // OpenScheduler