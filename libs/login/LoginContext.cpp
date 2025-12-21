
#include "LoginContext.hpp"

namespace Login {
    void LoginContextHolder::setContextParams(LoginType type, bool ready) {
        type_ = type;
        ready_ = ready;
    }

} // Login