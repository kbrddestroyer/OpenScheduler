#include "Dao.hpp"
#include <sstream>

namespace Database {
    template<class DAO>
    std::vector<DAO> QueryProcessor<DAO>::select(std::string_view tableName, size_t limit) {
        static_assert(std::is_base_of<DAOBase, DAO>());

        std::stringstream ss;
        ss << "SELECT * FROM " << tableName;
        if (limit > 0) {
            ss << " LIMIT" << limit;
        }
        ss << ";";

        std::vector<DAO> result;
        if (const auto rs = Utils::Singleton<Backend>::instance()->executeQuery(ss.str())) {

            while (rs->next()) {
                result.push_back(DAO(rs.get()));
            }
        }
        return result;
    }

    template<class DAO>
    template<typename PK>
    std::shared_ptr<DAO> QueryProcessor<DAO>::selectByPK(const std::string_view tableName, const std::string_view pkCol, const PK primary) {
        static_assert(std::is_base_of<DAOBase, DAO>());

        std::stringstream ss;
        ss << "SELECT * FROM " << tableName << " WHERE " << pkCol << "=" << primary << " LIMIT 1;";
        if (const auto rs = Utils::Singleton<Backend>::instance()->executeQuery(ss.str()); rs->next()) {
            return std::make_shared<DAO>(rs.get());
        }

        return {};
    }

} // Database