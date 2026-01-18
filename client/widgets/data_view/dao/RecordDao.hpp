#ifndef RECORDDAO_HPP
#define RECORDDAO_HPP

#include <database/table/Dao.hpp>
#include <string>
#include <QDateTime>


namespace sql {
    class ResultSet;
}

namespace OpenScheduler::Dao{
    class RecordDao final : public Database::DAOBase {
    public:
        RecordDao() = delete;
        explicit RecordDao(const sql::ResultSet * /* rs */);

        RecordDao( uint16_t visitor, QDateTime start, QDateTime end, std::string comment = "" ) :
            visitor_id_(visitor), start_(std::move(start)), end_(std::move(end)), comment_(std::move(comment))
        {}

        [[nodiscard]] uint16_t ID() const { return id_; }
        [[nodiscard]] uint16_t VISITOR() const { return visitor_id_; }
        [[nodiscard]] const QDateTime & START() const { return start_; }
        [[nodiscard]] const QDateTime & END() const { return end_; }
        [[nodiscard]] const std::string & COMMENT() const { return comment_; }
        [[nodiscard]] const std::string getUpdateQuery() const override;
    private:
        static QDateTime stringToTime( const std::string & /* data */ );
    private:
        uint16_t id_ = 0;
        uint16_t visitor_id_;
        QDateTime start_;
        QDateTime end_;
        std::string comment_;
    };
}

#endif //RECORDDAO_HPP
