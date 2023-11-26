#include "../../include/model/Company.hpp"


using namespace places;

Company::Company(
    long unsigned int cnpj,
    const std::string &email,
    const std::string &password,
    const std::string &phoneNumber,
    const std::string &name,
    const Address &address
): User{email, password, phoneNumber, name, address}, cnpj{cnpj}  {
}

long unsigned int Company::getCnpj() {
    return this->cnpj;
}

void Company::setCnpj(unsigned long cnpj) {
    this->cnpj = cnpj;

    return;
}

