#ifndef OPENSCHEDULER_CUSTOMERDAO_H
#define OPENSCHEDULER_CUSTOMERDAO_H

#include <database/Database.hpp>
#include <database/table/Dao.hpp>

namespace OpenScheduler::Dao {

    class CustomerDao : public Database::DAOBase {
    public:
        CustomerDao() = delete;
        explicit CustomerDao(const sql::ResultSet * /* rs */);

        CustomerDao( uint16_t id, const std::string name ) :
            id_(id), name_(std::move(name))
        {}

        [[nodiscard]] uint16_t ID() const { return id_; }
        [[nodiscard]] const std::string NAME() const { return name_; }
        [[nodiscard]] const std::string getUpdateQuery() const override;
    private:
        uint16_t id_ = 0;
        std::string name_;
    };

} // OpenScheduler

#endif //OPENSCHEDULER_CUSTOMERDAO_H
