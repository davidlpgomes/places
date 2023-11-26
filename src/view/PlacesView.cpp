#include "../../include/view/PlacesView.hpp"
#include "../../include/model/User.hpp"
#include "../../include/model/Person.hpp"
#include "../../include/model/Company.hpp"
#include "../../include/controller/EventControler.hpp"


#include <iostream>
using namespace places;

PlacesView::PlacesView(unsigned int viewType,ViewsStatesEnum viewState): viewType{viewType}, viewState{viewState} {}


unsigned int getViewType();

unsigned int PlacesView::getViewType(){
    return this->viewType;
};

void PlacesView::setViewType(unsigned int viewType){
    this->viewType = viewType;
}; 

ViewsStatesEnum PlacesView::getViewState(){
    return this->viewState;
};

void PlacesView::setViewState(ViewsStatesEnum viewState){
    this->viewState = viewState;
};

void PlacesView::getInitialPage() {
    std::cout << "Digite o tipo de acesso desejado: 1 para empresa, 2 para cliente" << std::endl;
    unsigned int opcao;
    std::cin >> opcao;

    std::cout << "E-mail:" << std::endl;
    std::string login;
    std::cin >> login;
    std::cout << "Senha:" << std::endl;
    std::string password;
    std::cin >> password;

    std::cout << "Login efetuado" << std::endl;
    if (opcao == 1){
        this->setViewState(COMPANY_INITIAL_PAGE);
        this->setViewType(1);
    }
    else {
        this->setViewState(USER_INITIAL_PAGE);
        this->setViewType(2);
    }

    return;
}

void PlacesView::getUserInitialPage(Person *person){
    std::cout << "" << person->getName()  << std::endl;
    std::cout << "" << person->getCreationDate()  << std::endl;

    // 

}

void PlacesView::getCompanyInitialPage(Company *company){
    std::cout << company->getName()  << std::endl;
    std::cout << company->getAddress().getCountry() << ", "
              << company->getAddress().getState() << ", "
              << company->getAddress().getCity() << ", "
              << company->getAddress().getNeighborhood() << ", "
              << company->getAddress().getStreet() << " \n" ;
    std::cout << company->getPhoneNumber()  << std::endl;
    EventControler evCont;

    std::cout << "Digite 1 para impulsionar um local:" << std::endl;
    // Impulsionar local
}
