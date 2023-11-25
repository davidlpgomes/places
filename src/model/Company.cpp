#include "../../include/model/Company.hpp"


using namespace places;

Company::Company(long unsigned int cnpj): cnpj{cnpj} {
}

long unsigned int Company::getCnpj() {
    return this->cnpj;
}

void Company::setCnpj(unsigned long cnpj) {
    this->cnpj = cnpj;

    return;
}

