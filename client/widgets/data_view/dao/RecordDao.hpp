#ifndef RECORDDAO_HPP
#define RECORDDAO_HPP

#include <database/table/Dao.hpp>
#include <string>

namespace sql {
    class ResultSet;
}

namespace OpenScheduler::Dao{

    class RecordDao final : public Database::DAOBase {
    public:
        RecordDao() = delete;
        RecordDao(const sql::ResultSet * /* rs */);

        RecordDao( uint16_t visitor, std::string start, std::string end, std::string comment = "" ) :
            visitor_id_(visitor), start_(std::move(start)), end_(std::move(end)), comment_(std::move(comment))
        {}

        uint16_t ID() const { return id_; }
        uint16_t VISITOR() const { return visitor_id_; }
        const std::string & START() const { return start_; }
        const std::string & END() const { return end_; }
        const std::string & COMMENT() const { return comment_; }

        [[nodiscard]] const std::string getUpdateQuery() const override;

    private:
        uint16_t id_ = 0;
        uint16_t visitor_id_;
        std::string start_;
        std::string end_;
        std::string comment_;
    };

}

#endif //RECORDDAO_HPP
