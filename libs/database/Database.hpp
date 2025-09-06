#ifndef DATABASE_HPP
#define DATABASE_HPP
#include <Singleton.hpp>
#include "Backend.hpp"
#include "table/QueryProcessor.hpp"
#include "table/Dao.hpp"

namespace Database {

class Database final : Utils::Singleton<Database> {

};

} // Database

#endif //DATABASE_HPP
