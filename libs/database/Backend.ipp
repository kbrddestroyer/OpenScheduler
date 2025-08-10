#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <sstream>

namespace Database {
    template<typename K, class DAO>
    DAOBase *Backend::getByID(const std::string& tableName, const std::string& keyName, const K key) {
        static_assert(std::is_base_of<DAOBase, DAO>());

        sql::Statement * statement = connection->createStatement();
        std::stringstream query;
        query << "SELECT * FROM " << tableName << ";";

        if (sql::ResultSet *  rs = statement->executeQuery(query.str()); rs->next()) {
            return dynamic_cast<DAOBase *> ( new DAO(rs) );
        }
        return nullptr;
    }
}
