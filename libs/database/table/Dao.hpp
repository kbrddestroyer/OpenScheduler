#ifndef DAO_HPP
#define DAO_HPP
#include <string>

namespace Database {

class DAOException : std::exception {
public:
    DAOException() = delete;
    DAOException(std::string&& what) : err_(std::move(what)) {}

    const char *what() const noexcept override { return err_.c_str(); }
private:
    std::string err_;
};

struct DAOBase {
    virtual ~DAOBase() = default;

    [[nodiscard]] virtual const std::string getUpdateQuery() const = 0;
};

template<class DAO_L, class DAO_R>
class CompositeDao : public DAOBase {
    static_assert(
        std::is_base_of_v<DAOBase, DAO_L> &&
        std::is_base_of_v<DAOBase, DAO_R>
    );
public:
    CompositeDao() = delete;
    explicit CompositeDao(const DAO_L&, const DAO_R&) = delete;
    CompositeDao(DAO_L&&, DAO_R&&) = delete;

    virtual ~CompositeDao() = default;

    [[nodiscard]] virtual const std::string getUpdateQuery() const override {
        throw DAOException{
            "Can't use composite dao for update/insert queries!"
        };
    }

    [[nodiscard]] const DAO_L &L() const { return l; }
    [[nodiscard]] const DAO_R &R() const { return r; }
protected:
    DAO_L l;
    DAO_R r;
};

} // Database

#endif //DAO_HPP
