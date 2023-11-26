#ifndef COMPANY_CONTROLLER_HPP
#define COMPANY_CONTROLLER_HPP

#include "Controller.hpp"


namespace places {

class CompanyController : public Controller {
    public:
        CompanyController(Company *const company);

        virtual ~CompanyController() = default;

        void setCompany(Company *const company);

        bool addCompany(
            long unsigned int cpnj,
            const std::string &email,
            const std::string &password,
            const std::string &phoneNumber,
            const std::string &name,
            const Address &address
        );

        bool addCompany(Company *const company);

        Company *getCompanyById(unsigned int id) const;

        std::vector<Company*> getCompanies() const;

        std::vector<Company*> getCompanies(const std::string &search) const;

    private:
        Company *company;
};

} // namespace places

#endif
