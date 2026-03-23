#include "RecordDao.hpp"

#include <format>
#include <cppconn/resultset.h>

namespace OpenScheduler::Dao {
    RecordDao::RecordDao(const sql::ResultSet * rs) :
        id_ ( rs->getInt("id") ),
        visitor_id_( rs->getInt("visitor_id") ),
        start_( rs->getString("start") ),
        end_( rs->getString("end") ),
        comment_( rs->getString("comment") )
    {}

    const std::string RecordDao::getUpdateQuery() const {
        return std::format(
            "visitor_id={}, start=\"{}\", end=\"{}\", comment=\"{}\"",
            visitor_id_, start_, end_, comment_
        );
    }

}
