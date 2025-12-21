
#ifndef LOGINCONTEXT_HPP
#define LOGINCONTEXT_HPP
#include "Singleton.hpp"

namespace Login {

enum class LoginType {
    NO_LOGIN,
    USER_RO,
    USER_RW,
    DOCTOR,
    ADMIN
};

class LoginContextHolder : Utils::Singleton<LoginContextHolder> {
public:
    LoginContextHolder() = default;

    void setContextParams(LoginType, bool);

    [[nodiscard]] LoginType Type() const noexcept { return type_; }
    [[nodiscard]] bool Ready() const noexcept { return ready_; }
protected:
    LoginType       type_ = LoginType::NO_LOGIN;
    bool            ready_ = false;
};

} // Login

#endif //LOGINCONTEXT_HPP
