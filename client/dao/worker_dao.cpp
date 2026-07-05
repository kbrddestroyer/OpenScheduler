#include "worker_dao.hpp"
#include "jdbc/cppconn/resultset.h"
#include <format>


namespace OpenScheduler::Dao {
    WorkerDao::WorkerDao(const sql::ResultSet *rs) :
        id_(rs->getInt("id")),
        login_id_(rs->getInt("login_id")),
        name_(rs->getString("name")),
        surname_(rs->getString("surname")),
        type_{ rs->getInt("type") }
    {}

    WorkerDao::WorkerDao(uint16_t login_id, std::string&& name, std::string&& surname, WorkerType type) :
        login_id_(login_id),
        name_(std::move(name)),
        surname_(std::move(surname)),
        type_(type)
    {}

    WorkerDao::WorkerDao(uint16_t login_id, const QString &name, const QString &surname, WorkerType type) :
        login_id_(login_id),
        name_(name.toStdString()),
        surname_(surname.toStdString()),
        type_(type)
    {}

    const std::string WorkerDao::getUpdateQuery() const {
        return std::format(
                R"(login_id={}, name="{}", surname="{}", type={})",
                    login_id_, name_, surname_, static_cast<int>(type_)
                );
    }
} // Dao
// OpenScheduler