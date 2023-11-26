#include "../../include/controller/UserController.hpp"

using namespace places;

UserController::UserController(User *const user): user{user} {
}

void UserController::setUser(User *const user) {
    this->user = user;

    return;
}

bool UserController::login(
    const std::string &email,
    const std::string &password
) {
    if (
        email == this->user->getEmail() &&
        password == this->user->getPassword()
    )
        return true;

    return false;
}

bool UserController::updatePassword(
    const std::string &oldPassword,
    const std::string &newPassword
) {
    if (oldPassword != this->user->getPassword())
        return false;

    this->user->setPassword(newPassword);

    return true;
}

bool UserController::updatePhoneNumber(const std::string &newPhoneNumber) {
    this->user->setPhoneNumber(newPhoneNumber);

    return true;
}

bool UserController::updateName(const std::string &newName) {
    this->user->setName(newName);

    return true;
}

bool UserController::updateAddress(const Address &address) {
    this->user->setAddress(address);

    return true;
}

