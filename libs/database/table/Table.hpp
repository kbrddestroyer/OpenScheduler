#ifndef TABLE_HPP
#define TABLE_HPP

namespace Database {

template <typename... Cols>
class Table {
public:
    virtual ~Table() = default;
};

} // Database

#endif //TABLE_HPP
