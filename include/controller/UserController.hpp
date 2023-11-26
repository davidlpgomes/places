#ifndef USER_CONTROLLER_HPP
#define USER_CONTROLLER_HPP

#include <string>

#include "Controller.hpp"


namespace places {

class UserController : public Controller {
    public:
        UserController(User *const user);

        virtual ~UserController() = default;

        void setUser(User *const user);

        bool login(
            const std::string &email,
            const std::string &password
        );

        bool updatePassword(
            const std::string &oldPassword,
            const std::string &newPassword
        );

        bool updatePhoneNumber(const std::string &newPhoneNumber);

        bool updateName(const std::string &newName);

        bool updateAddress(const Address &address);

    private:
        User *user;
};

} // namespace places

#endif
