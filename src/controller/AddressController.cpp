#include "../../include/controller/AddressController.hpp"

using namespace places;

AddressController::AddressController() {}

Address AddressController::createAddress(
    const std::string &country,
    const std::string &state,
    const std::string &city,
    const std::string &neighborhood,
    const std::string &street,
    unsigned int number,
    unsigned int cep
) {
    Address address{Address{
        country, state, city, neighborhood, street, number, cep
    }};

    return address;
}

Address AddressController::createAddress(
    const std::string &country,
    const std::string &state,
    const std::string &city,
    const std::string &neighborhood,
    const std::string &street,
    unsigned int number,
    unsigned int cep,
    const std::string &complement
) {
    Address address{this->createAddress(
        country, state, city, neighborhood, street, number, cep
    )};

    address.setComplement(complement);

    return address;
}

