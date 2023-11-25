#include "../../include/model/Place.hpp"


using namespace places;

Place::Place(): company(nullptr) {}

Place::Place(
    const std::string &name,
    const std::string &description,
    const std::string &phoneNumber,
    Company *const company,
    const Address &address,
    unsigned int capacity
): name(name), description(description), phoneNumber(phoneNumber),
   company(company), address(address), capacity(capacity) {
}

const std::string &Place::getName() const {
    return this->name;
}

void Place::setName(const std::string &name) {
    this->name = name;

    return;
}

const std::string &Place::getDescription() const {
    return this->description;
}

void Place::setDescription(const std::string &description) {
    this->description = description;

    return;
}

const std::string &Place::getPhoneNumber() const {
    return this->phoneNumber;
}

void Place::setPhoneNumber(const std::string &phoneNumber) {
    this->phoneNumber = phoneNumber;

    return;
}

const Company *Place::getCompany() const {
    return this->company;
}

void Place::setCompany(Company *const company) {
    this->company = company;

    return;
}

const Address &Place::getAddress() const {
    return this->address;
}

void Place::setAddress(const Address &address) {
    this->address = address;

    return;
}

unsigned int Place::getCapacity() {
    return this->capacity;
}

void Place::setCapacity(unsigned int capacity) {
    this->capacity = capacity;

    return;
}

