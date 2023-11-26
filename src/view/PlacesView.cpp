#include "../../include/view/PlacesView.hpp"

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

