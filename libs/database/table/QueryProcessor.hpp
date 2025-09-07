#ifndef QUERYPROCESSOR_HPP
#define QUERYPROCESSOR_HPP

#include <memory>
#include <vector>

namespace Database {

template <class DAO>
class QueryProcessor final {
public:
    static std::vector<DAO> select(std::string_view tableName, size_t limit = 0);

    template <typename PK>
    static std::shared_ptr<DAO> selectByPK(std::string_view tableName, std::string_view pkCol, PK primary);

    static bool insert(std::string_view tableName, const DAO& object);

    template <typename PK>
    static uint32_t update(std::string_view tableName, std::string_view pkCol, PK primary, const DAO& object);
};

} // Database

#include "QueryProcessor.ipp"
#endif //QUERYPROCESSOR_HPP
