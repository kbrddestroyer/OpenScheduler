#ifndef CUSTOMERDAO_HPP
#define CUSTOMERDAO_HPP

#include <Database.hpp>
#include <database/table/Dao.hpp>

#include "compile_utils.h"

namespace OpenScheduler {

class CustomerDao final : public Database::DAOBase {
public:
    CustomerDao() = delete;

    explicit CustomerDao(const sql::ResultSet * rs);
    explicit CustomerDao(std::string name) : name_(std::move(name)) {}

    GETTER (std::uint32_t ID()) { return id_; }
    GETTER (std::string NAME()) { return name_; }
    GETTER (const std::string getUpdateQuery()) override;
private:
    std::uint32_t   id_ = 0;
    std::string     name_;
};

} // OpenScheduler

#endif //CUSTOMERDAO_HPP
