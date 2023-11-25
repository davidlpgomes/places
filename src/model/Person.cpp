#include "../../include/model/Person.hpp"


using namespace places;

Person::Person() {}

Person::Person(
    const std::string &userName,
    unsigned int cpf,
    const boost::posix_time::ptime &birthDate
): userName{userName}, cpf{cpf}, birthDate{birthDate} {
}

const std::string &Person::getUserName() const {
    return this->userName;
}

void Person::setUserName(const std::string &userName) {
    this->userName = userName;

    return;
}

unsigned int Person::getCpf() {
    return this->cpf;
}

void Person::setCpf(unsigned int cpf) {
    this->cpf = cpf;

    return;
}

const boost::posix_time::ptime &Person::getBirthDate() const {
    return this->birthDate;
}

void Person::setBirthDate(const boost::posix_time::ptime &birthDate) {
    this->birthDate = birthDate;

    return;
}

