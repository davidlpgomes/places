#include "../../include/controller/CompanyController.hpp"

using namespace places;

CompanyController::CompanyController(
    Company *const company
): company{company} {
}

void CompanyController::setCompany(Company *const company) {
    this->company = company;

    return;
}

bool CompanyController::addCompany(
    long unsigned int cnpj,
    const std::string &email,
    const std::string &password,
    const std::string &phoneNumber,
    const std::string &name,
    const Address &address
) {
    Company *company{new Company{
        cnpj, email, password, phoneNumber, name, address
    }};

    return this->addCompany(company);
}

bool CompanyController::addCompany(Company *const company) {
    if (company == nullptr)
        return false;

    this->db->addCompany(company);

    return true;
}

Company *CompanyController::getCompanyById(unsigned int id) const {
    return this->db->getCompanies()->find(id)->second;
}

Company *CompanyController::getCompanyByEmail(const std::string &email) const {
    const std::map<int, Company*> *companies{this->db->getCompanies()};

    std::map<int, Company*>::const_iterator it{companies->begin()};

    Company *company{nullptr};

    for (; it != companies->end(); ++it)
        if ((*it).second->getEmail() == email) {
            company = (*it).second;
            break;
        }

    return company;
}

std::vector<Company*> CompanyController::getCompanies() const {
    const std::map<int, Company*> *companies{this->db->getCompanies()};

    std::vector<Company*> companies_vec;

    std::map<int, Company*>::const_iterator it{companies->begin()};

    for (; it != companies->end(); ++it)
        companies_vec.push_back((*it).second);

    return companies_vec;
}

std::vector<Company*> CompanyController::getCompanies(
    const std::string &search
) const {
    const std::map<int, Company*> *companies{this->db->getCompanies()};

    std::vector<Company*> companies_vec;

    std::map<int, Company*>::const_iterator it{companies->begin()};

    for (; it != companies->end(); ++it)
        if (
            (*it).second->getName().find(search) != std::string::npos ||
            search.find((*it).second->getName()) != std::string::npos
        )
            companies_vec.push_back((*it).second);

    return companies_vec;
}

