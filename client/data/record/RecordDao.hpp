
#ifndef RECORDDAO_HPP
#define RECORDDAO_HPP

#include <Database.hpp>
#include "table/Dao.hpp"
#include <compile_utils.h>

namespace OpenScheduler {

class RecordDao : public Database::DAOBase {
public:
    RecordDao() = delete;

    explicit RecordDao(const sql::ResultSet * rs);
    explicit RecordDao(std::uint32_t customer, std::time_t start, std::time_t end, std::string comment = "") :
        customer_id_(customer),
        start_(start),
        end_(end),
        comment_(comment)
    {}

    GETTER (std::uint32_t ID()) { return id_; }
    GETTER (std::uint32_t CUSTOMER()) { return customer_id_; }
    GETTER (std::time_t START()) { return start_; }
    GETTER (std::time_t END()) { return end_; }
    GETTER (std::string COMMENT()) { return comment_; }
    GETTER (const std::string getUpdateQuery()) override;
private:
    std::uint32_t   id_ = 0;
    std::uint32_t   customer_id_;
    std::time_t     start_;
    std::time_t     end_;
    std::string     comment_ = "";
};

} // OpenScheduler

#endif //RECORDDAO_HPP
