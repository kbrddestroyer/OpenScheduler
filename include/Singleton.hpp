#ifndef SINGLETON_HPP
#define SINGLETON_HPP
#include <memory>

namespace Utils {

template <class T>
class Singleton {
public:
    Singleton() = default;
    virtual ~Singleton() = default;

    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) noexcept = delete;

    const Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) noexcept = delete;

    static std::shared_ptr<T> instance();
};

} // Utils

#include "Singleton.ipp"
#endif //SINGLETON_HPP
