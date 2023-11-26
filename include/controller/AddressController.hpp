#ifndef ADDRESS_CONTROLLER_HPP
#define ADDRESS_CONTROLLER_HPP

#include "Controller.hpp"


namespace places {

class AddressController : public Controller {
    public:
        AddressController();

        virtual ~AddressController() = default;

        Address createAddress(
            const std::string &country,
            const std::string &state,
            const std::string &city,
            const std::string &neighborhood,
            const std::string &street,
            unsigned int number,
            unsigned int cep
        );

        Address createAddress(
            const std::string &country,
            const std::string &state,
            const std::string &city,
            const std::string &neighborhood,
            const std::string &street,
            unsigned int number,
            unsigned int cep,
            const std::string &complement
        );
};

} // namespace places

#endif
