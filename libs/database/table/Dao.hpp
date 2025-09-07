#ifndef DAO_HPP
#define DAO_HPP

namespace Database {

struct DAOBase {
    virtual ~DAOBase() = default;

    [[nodiscard]] virtual std::string getUpdateQuery() const = 0;
};

} // Database

#endif //DAO_HPP
