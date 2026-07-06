#ifndef OPENSCHEDULER_WORKER_DAO_HPP
#define OPENSCHEDULER_WORKER_DAO_HPP

#include "database/table/Dao.hpp"
#include <cstdint>
#include <string>
#include <QString>


namespace sql {
    class ResultSet;
}

namespace OpenScheduler::Dao {
    enum class WorkerType {
        DEFAULT = 0,
        SUPERUSER = 1,
        ADMINISTRATOR = 2,
        MEDIC = 3,
        OTHER = 4
    };

    class WorkerDao final : public Database::DAOBase {
    public:
        WorkerDao() = delete;

        explicit WorkerDao( const sql::ResultSet * /* rs */ );

        WorkerDao(
                uint16_t /* login_id */,
                std::string &&/* name */,
                std::string &&/* surname */,
                WorkerType /* type */
                );

        WorkerDao(
                uint16_t /* login_id */,
                const QString & /* name */,
                const QString & /* surname */,
                WorkerType /* type */
                );

        [[nodiscard]] const std::string getUpdateQuery() const override;
        [[nodiscard]] std::string DISPLAY_NAME() const { return name_ + " " + surname_; }
        [[nodiscard]] uint16_t ID() const { return id_; }
        [[nodiscard]] WorkerType TYPE() const { return type_; }
    private:
        std::uint16_t id_ = 0;
        std::uint16_t login_id_;
        std::string name_;
        std::string surname_;
        WorkerType type_;
    };
}

#endif //OPENSCHEDULER_WORKER_DAO_HPP
