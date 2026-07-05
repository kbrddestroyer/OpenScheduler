#include "RecordDao.hpp"

#include <format>
#include <iomanip>
#include "jdbc/cppconn/resultset.h"

namespace OpenScheduler::Dao {
    RecordDao::RecordDao(const sql::ResultSet * rs) :
        id_ ( rs->getInt("id") ),
        visitor_id_( rs->getInt("visitor_id") ),
        assignee_id_( rs->getInt("assignee_id") ),
        start_( stringToTime(rs->getString( "start" )) ),
        end_( stringToTime( rs->getString("end")) ),
        comment_( rs->getString("comment") ) {
    }

    const std::string RecordDao::getUpdateQuery() const {
        return std::format(
            "visitor_id={}, assignee_id={}, start=\"{}\", end=\"{}\", comment=\"{}\"",
            visitor_id_, assignee_id_, timeToString(start_), timeToString(end_), comment_
        );
    }

    std::string RecordDao::timeToString(const QDateTime &datetime) {
        return datetime.toString("yyyy-MM-dd hh:mm:ss").toStdString();
    }

    QDateTime RecordDao::stringToTime(const std::string & data) {
        return QDateTime::fromString( { data.c_str() }, "yyyy-MM-dd HH:mm:ss" );
    }
}
