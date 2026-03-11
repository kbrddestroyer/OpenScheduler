#include "RecordDao.hpp"
#include <format>

namespace OpenScheduler {
    RecordDao::RecordDao(const sql::ResultSet *rs) :
        id_(rs->getInt("id")),
        customer_id_(rs->getInt("customer")),
        start_(rs->getInt64("start")),
        end_(rs->getInt64("end")),
        comment_(rs->getString("comment"))
    {}

    const std::string RecordDao::getUpdateQuery() const noexcept {
        return std::format(
            "customer={}, start={}, end={}, comment=\'{}\'",
            customer_id_,
            start_,
            end_,
            comment_
        );
    }
} // OpenScheduler