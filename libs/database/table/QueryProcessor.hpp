#ifndef QUERYPROCESSOR_HPP
#define QUERYPROCESSOR_HPP

#include <Backend.hpp>
#include <Singleton.hpp>
#include <memory>
#include <vector>

namespace Database {

template <class DAO>
class QueryProcessor final {
public:
    static std::vector<DAO> select(std::string_view tableName, size_t limit = 0);
    template <typename PK>
    static std::shared_ptr<DAO> selectByPK(std::string_view tableName, std::string_view pkCol, PK primary);
};

} // Database

#include "QueryProcessor.ipp"
#endif //QUERYPROCESSOR_HPP
