#include "RecordDao.hpp"

#include <format>
#include <iomanip>
#include <cppconn/resultset.h>

namespace OpenScheduler::Dao {
    RecordDao::RecordDao(const sql::ResultSet * rs) :
        id_ ( rs->getInt("id") ),
        visitor_id_( rs->getInt("visitor_id") ),
        start_( stringToTime(rs->getString( "start" )) ),
        end_( stringToTime( rs->getString("end")) ),
        comment_( rs->getString("comment") ) {
    }

    const std::string RecordDao::getUpdateQuery() const {
        return std::format(
            "visitor_id={}, start=\"{}\", end=\"{}\", comment=\"{}\"",
            visitor_id_, start_.toString("yyyy-MM-dd hh:mm:ss").toStdString(), end_.toString("yyyy-MM-dd HH:mm:ss").toStdString(), comment_
        );
    }

    QDateTime RecordDao::stringToTime(const std::string & data) {
        return QDateTime::fromString( { data.c_str() }, "yyyy-MM-dd HH:mm:ss" );
    }
}
