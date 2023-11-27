#include "../../include/view/PlacesView.hpp"
#include "../../include/model/User.hpp"
#include "../../include/model/Person.hpp"
#include "../../include/model/Company.hpp"
#include "../../include/model/Place.hpp" 
#include "../../include/controller/EventController.hpp"
#include "../../include/controller/PersonController.hpp"
#include <vector>
#include <iostream>

using namespace std; 
using namespace places;

PlacesView::PlacesView(unsigned int viewType, ViewsStatesEnum viewState) : viewType{viewType}, viewState{viewState} {}

unsigned int getViewType();

unsigned int PlacesView::getViewType()
{
    return this->viewType;
};

void PlacesView::setViewType(unsigned int viewType)
{
    this->viewType = viewType;
};

ViewsStatesEnum PlacesView::getViewState()
{
    return this->viewState;
};

void PlacesView::setViewState(ViewsStatesEnum viewState)
{
    this->viewState = viewState;
};

void PlacesView::getInitialPage()
{
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
    if (opcao == 1)
    {
        this->setViewState(COMPANY_INITIAL_PAGE);
        this->setViewType(1);
    }
    else
    {
        this->setViewState(USER_INITIAL_PAGE);
        this->setViewType(2);
    }

    return;
}

void PlacesView::getUserInitialPage(Person *person)
{
    std::cout << "" << person->getName() << std::endl;
    std::cout << "" << person->getCreationDate() << std::endl;
    std::cout << "Digite 2 para verificar eventos e 3 para verificar revisões:" << std::endl;
    unsigned int opcao;
    std::cin >> opcao;
    if (opcao == 2)
    {
        this->setViewState(PLACE_EVENTS);
    }
    else if (opcao == 3)
    {
        this->setViewState(PLACE_REVIEWS);
    }
    //
}

void PlacesView::getCompanyInitialPage(Company *company)
{
    std::cout << company->getName() << std::endl;
    std::cout << company->getAddress().getCountry() << ", "
              << company->getAddress().getState() << ", "
              << company->getAddress().getCity() << ", "
              << company->getAddress().getNeighborhood() << ", "
              << company->getAddress().getStreet() << " \n";
    std::cout << company->getPhoneNumber() << std::endl;
    Event event; 
    EventController evCont(&event); 

    std::cout << "Digite 1 para impulsionar um local:" << std::endl;
    unsigned int opcao;
    std::cin >> opcao;
    if (opcao == 1)
    {
        this->setViewState(PLACE_EVENTS);
    }
    else
    {
        this->setViewState(EXIT);
    }
    // Impulsionar local
}

void PlacesView::getPlacePage(Place *place, ViewsStatesEnum viewState)
{
    if (viewState == PLACE_DESCRIPTION)
    {
        // place description
        // print place description
        place->getAddress();
        place->getPhoneNumber();
        place->getDescription();
    }
    else if (viewState == PLACE_EVENTS)
    {
        // place events
        place->getBoosts();
        // print place events
    }
    else if (viewState == PLACE_REVIEWS)
    {
        // place reviews
        const std::vector<Review> reviews = place->getReviews();
        // print place reviews
    }

    std::cout << "Digite 2 para verificar eventos e 3 para verificar revisões:" << std::endl;
    unsigned int opcao;
    std::cin >> opcao;
    if (opcao == 2)
    {
        this->setViewState(PLACE_EVENTS);
    }
    else if (opcao == 3)
    {
        this->setViewState(PLACE_REVIEWS);
    }
}

void PlacesView::getUserFriendsPage(Person *person)
{
    PersonController personCont(person);

    std::cout << "Digite 1 para visualizar lista e 2 para visualizar solicitações:" << std::endl;
    unsigned int option;
    std::cin >> option;
    if (option == 1)
    {
        std::vector<Person*> friends = personCont.getFriends(); 

        std::cout << "Lista de Amigos:\n";
        for (const auto &friendItem : friends) 
        {
            std::cout << friendItem->getName() << std::endl;
        }
        this->setViewState(USER_FRIENDS_LIST);
    }
    if (option == 2)
    {
        personCont.getFriendRequets();
        this->setViewState(USER_FRIENDS_REQUESTS);
    }

}