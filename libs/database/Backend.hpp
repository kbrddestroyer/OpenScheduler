#ifndef BACKEND_HPP
#define BACKEND_HPP

#include "Host.hpp"

namespace Database {

/**
 *  Abstraction level for database connector library
 */
class Backend {
public:
    virtual ~Backend() = default;

    virtual bool connect(const Host& host) = 0;
    virtual void disconnect() = 0;
    virtual bool isConnected() = 0;
protected:
    bool connected = false;
};

} // Database

#endif //BACKEND_HPP
