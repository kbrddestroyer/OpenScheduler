
#ifndef LOGINCONTEXT_HPP
#define LOGINCONTEXT_HPP

namespace Login {

enum class __login_type {
    NO_LOGIN,
    USER_RO,
    USER_RW,
    DOCTOR,
    ADMIN
};

class LoginContext {
protected:
    __login_type    type_ = __login_type::NO_LOGIN;
    bool            ready_ = false;
};

} // Login

#endif //LOGINCONTEXT_HPP
