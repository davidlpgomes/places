#ifndef ADDRESS_HPP
#define ADDRESS_HPP

#include <string>

namespace places {

class Address {
    public:
        Address();

        Address(
            const std::string &country,
            const std::string &state,
            const std::string &city,
            const std::string &neighborhood,
            const std::string &street,
            unsigned int number,
            unsigned int cep
        );

        virtual ~Address() = default;

        std::string getCountry() const;
        void setCountry(const std::string &country);

        std::string getState() const;
        void setState(const std::string &state);

        std::string getCity() const;
        void setCity(const std::string &city);

        std::string getNeighborhood() const;
        void setNeighborhood(const std::string &neighborhood);

        std::string getStreet() const;
        void setStreet(const std::string &street);

        unsigned int getNumber();
        void setNumber(unsigned int number);

        unsigned int getCep();
        void setCep(unsigned int cep);

        std::string getComplement() const;
        void setComplement(const std::string &complement);

    private:
        std::string country;
        std::string state;
        std::string city;

        std::string neighborhood;
        std::string street;
        unsigned int number;

        unsigned int cep;
        std::string complement;
};

}

#endif
