#ifndef COMPANY_HPP
#define COMPANY_HPP

#include "User.hpp"


namespace places {

class Company : public User {
    public:
        Company();

        Company(long unsigned int cpnj);

        virtual ~Company() = default;

        long unsigned int getCnpj();
        void setCnpj(long unsigned int cnpj);

    private:
        long unsigned int cnpj;
};

} // namespace places

#endif
