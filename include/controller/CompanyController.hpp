#ifndef COMPANY_CONTROLLER_HPP
#define COMPANY_CONTROLLER_HPP

#include "Controller.hpp"


namespace places {

class CompanyController : public Controller {
    public:
        CompanyController(Company *const company);

        virtual ~CompanyController() = default;

        void setCompany(Company *const company);

        bool addCompany(Company *const company);

        Company *getCompanyById(unsigned int id) const;

        std::vector<Company*> getCompanies() const;

    private:
        Company *company;
};

} // namespace places

#endif
