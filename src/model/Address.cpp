#include "../../include/model/Address.hpp"


using namespace places;

Address::Address() {}

Address::Address(
    const std::string &country,
    const std::string &state,
    const std::string &city,
    const std::string &neighborhood,
    const std::string &street,
    unsigned int number,
    unsigned int cep
): country(country), state(state), city(city), neighborhood(neighborhood),
   street(street), number(number), cep(cep) {
}

const std::string &Address::getCountry() const {
    return this->country;
}

void Address::setCountry(const std::string &country) {
    this->country = country;

    return;
}

const std::string &Address::getState() const {
    return this->state;
}

void Address::setState(const std::string &state) {
    this->state = state;

    return;
}

const std::string &Address::getCity() const {
    return this->city;
}

void Address::setCity(const std::string &city) {
    this->city = city;

    return;
}

const std::string &Address::getNeighborhood() const {
    return this->neighborhood;
}

void Address::setNeighborhood(const std::string &neighborhood) {
    this->neighborhood = neighborhood;

    return;
}

const std::string &Address::getStreet() const {
    return this->street;
}

void Address::setStreet(const std::string &street) {
    this->street = street;

    return;
}

unsigned int Address::getNumber() {
    return this->number;
}

void Address::setNumber(unsigned int number) {
    this->number = number;

    return;
}

unsigned int Address::getCep() {
    return this->cep;
}

void Address::setCep(unsigned int cep) {
    this->cep = cep;

    return;
}

const std::string &Address::getComplement() const {
    return this->complement;
}

void Address::setComplement(const std::string &complement) {
    this->complement = complement;
    
    return;
}

