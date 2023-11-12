#include "../../include/model/User.hpp"

#include <boost/date_time/posix_time/posix_time_types.hpp>

using namespace places;

User::User() {}

User::User(
    const std::string &email,
    const std::string &password,
    const std::string &phoneNumber,
    const std::string &name,
    const Address &address
): email(email), password(password), phoneNumber(phoneNumber), name(name),
   address(address) {
       this->creationDate = boost::posix_time::second_clock::local_time();
}

std::string User::getEmail() const {
    return this->email;
}

void User::setEmail(const std::string &email) {
    this->email = email;

    return;
}

std::string User::getPassword() const {
    return this->password;
}

void User::setPassword(const std::string &password) {
    this->password = password;

    return;
}

std::string User::getPhoneNumber() const {
    return this->phoneNumber;
}

void User::setPhoneNumber(const std::string &phoneNumber) {
    this->phoneNumber = phoneNumber;

    return;
}

std::string User::getName() const {
    return this->name;
}

void User::setName(const std::string &name) {
    this->name = name;

    return;
}

Address User::getAddress() const {
    return this->address;
}

void User::setAddress(const Address &address) {
    this->address = address;

    return;
}

boost::posix_time::ptime User::getCreationDate() const {
    return this->creationDate;
}

