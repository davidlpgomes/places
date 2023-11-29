#include "../../include/view/PlacesView.hpp"
#include "../../include/model/User.hpp"
#include "../../include/model/Person.hpp"
#include "../../include/model/Company.hpp"
#include "../../include/model/Place.hpp" 
#include "../../include/controller/EventController.hpp"
#include "../../include/controller/PersonController.hpp"
#include "../../include/controller/PlaceController.hpp"
#include "../../include/controller/CompanyController.hpp"

#include <vector>
#include <iostream>


using namespace places;


PlacesView::PlacesView(
    unsigned int viewType, 
    ViewsStatesEnum viewState
): viewType{viewType}, viewState{viewState} {
}

unsigned int PlacesView::getViewType() {
    return this->viewType;
}

void PlacesView::setViewType(unsigned int viewType) {
    this->viewType = viewType;

    return;
}

ViewsStatesEnum PlacesView::getViewState() {
    return this->viewState;
}

void PlacesView::setViewState(ViewsStatesEnum viewState) {
    this->viewState = viewState;

    return;
}

void PlacesView::printHeader() {
    int cols = 70;

    for (int i = 0; i < cols; i++) std::cout << "-";
    std::cout << std::endl;

    std::string title{"PLACES"};
    int num_spaces = (int) cols / 2 - title.length() / 2;

    for (int i = 0; i < num_spaces; i++) std::cout << " ";
    std::cout << title;
    for (int i = 0; i < num_spaces; i++) std::cout << " ";
    std::cout << std::endl;

    for (int i = 0; i < cols; i++) std::cout << "-";
    std::cout << std::endl;

    return;
}

void PlacesView::clearTerminal() {
    int ret = std::system("clear");

    if (ret) exit(1);

    return;
}

User *PlacesView::getInitialPage() {
    unsigned int option;

    std::cout << "[1] Cadastrar" << std::endl;
    std::cout << "[2] Login" << std::endl;
    std::cout << "[3] Sair" << std::endl;
    std::cout << "Opção: ";

    std::cin >> option;

    if (option == 1) {
        std::cout << "\n\n[1] Cadastrar cliente" << std::endl;
        std::cout << "[2] Cadastrar empresa" << std::endl;
        std::cout << "Opção: ";
        std::cin >> option;

        if (option == 1)
            this->setViewState(REGISTER_PERSON);
        else
            this->setViewState(REGISTER_COMPANY);

        return nullptr;
    } else if (option != 2)
        exit(0);

    std::cout << "\n[1] Login de cliente" << std::endl;
    std::cout << "[2] Login de empresa" << std::endl;
    std::cout << "Opção: ";
    std::cin >> option;

    std::cout << "E-mail: ";
    std::string email;
    std::cin >> email;

    std::cout << "Senha: ";
    std::string password;
    std::cin >> password;
    std::cout << std::endl;

    if (option == 1) {
        PersonController pc{nullptr};
        Person *person = pc.getPersonByEmail(email);

        if (person == nullptr) {
            std::cout << "E-mail inválido!" << std::endl;
            sleep(2);

            this->setViewState(LOGIN);
            return nullptr;
        }

        if (password != person->getPassword()) {
            std::cout << "Senha inválida!" << std::endl;
            sleep(2);

            this->setViewState(LOGIN);
            return nullptr;
        }

        std::cout << "Login efetuado!" << std::endl;
        sleep(2);

        this->setViewState(USER_INITIAL_PAGE);
        this->setViewType(2);

        return (User*) person;
    }

        
    CompanyController cc{nullptr};
    Company *company = cc.getCompanyByEmail(email);

    if (company == nullptr) {
        std::cout << "E-mail inválido!" << std::endl;
        sleep(2);

        this->setViewState(LOGIN);
        return nullptr;
    }

    if (password != company->getPassword()) {
        std::cout << "Senha inválida!" << std::endl;
        sleep(2);

        this->setViewState(LOGIN);
        return nullptr;
    }

    std::cout << "Login efetuado!" << std::endl;
    sleep(2);

    this->setViewState(COMPANY_INITIAL_PAGE);
    this->setViewType(1);

    return (User*) company;
}

void PlacesView::getRegisterPersonPage() {
    std::string userName;
    unsigned int cpf;
    std::string email;
    std::string password;
    std::string phoneNumber;
    std::string name;

    Address address;
    
    std::cout << "Nome: ";
    std::cin >> name;

    std::cout << "Username: ";
    std::cin >> userName;

    std::cout << "CPF (apenas números): ";
    std::cin >> cpf;

    std::cout << "E-mail: ";
    std::cin >> email;

    std::cout << "Senha: ";
    std::cin >> password;

    std::cout << "Número de telefone: ";
    std::cin >> phoneNumber;

    PersonController pc{nullptr};
    pc.addPerson(
        userName,
        cpf,
        boost::posix_time::second_clock::local_time(),
        email,
        password,
        phoneNumber,
        name,
        address
    );

    std::cout << "Cadastrado com sucesso!" << std::endl;
    sleep(2);

    this->setViewState(LOGIN);

    return;
}

void PlacesView::getRegisterCompanyPage() {
    unsigned int cnpj;
    std::string email;
    std::string password;
    std::string phoneNumber;
    std::string name;

    Address address;
    
    std::cout << "Nome: ";
    std::cin >> name;

    std::cout << "CNPJ (apenas números): ";
    std::cin >> cnpj;

    std::cout << "E-mail: ";
    std::cin >> email;

    std::cout << "Senha: ";
    std::cin >> password;

    std::cout << "Número de telefone: ";
    std::cin >> phoneNumber;

    CompanyController cc{nullptr};
    cc.addCompany(
        cnpj,
        email,
        password,
        phoneNumber,
        name,
        address
    );

    std::cout << "Cadastrado com sucesso!" << std::endl;
    sleep(2);

    this->setViewState(LOGIN);

    return;
}

void PlacesView::getUserInitialPage(Person *person)
{
    std::cout << "Nome: " << person->getName() << std::endl;
    std::cout << "Digite 2 para visualizar a pagina de amigos e 3 para buscar eventos:" << std::endl;
    unsigned int opcao;
    std::cin >> opcao;
    if (opcao == 2)
    {
        this->setViewState(USER_FRIENDS_LIST);
    }
    else if (opcao == 3)
    {
        Event event; 
        EventController evCont(&event);
        std::string searchedEv; 
        std::cout << "Digite o nome do evento:" << std::endl;
        std::cin >> searchedEv;
          

        std::vector<Event *> events = evCont.getEvents(searchedEv);
        for (const auto &evItem : events) 
        {
            std::cout << evItem->getName() << std::endl;
            std::cout << evItem->getDescription() << std::endl;
            std::cout << evItem->getExpectation() << std::endl;
            std::cout << "\n" << std::endl;
        }
        std::cout << "-----------------------------------" << std::endl;
        
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
    Place place1; 

    EventController evCont(&event); 
    CompanyController companyCont(company); 
    PlaceController placeCont(&place1); 

    std::cout << "Digite 1 visualizar seus locais, 2 para adicionar um local, 3 para sair:" << std::endl;
    unsigned int opcao;
    std::cin >> opcao;
    if (opcao == 1)
    {
        companyCont.setCompany(company);
        std::vector<Place *> places = placeCont.getPlaces();
        for (const auto &placeItem : places) 
        {
            std::cout << "LOCAL:" << std::endl;

            std::cout << placeItem->getName() << std::endl;
            std::cout << placeItem->getDescription() << std::endl;
            std::cout << placeItem->getPhoneNumber() << std::endl;

            std::cout << "\n" << std::endl;
        }
        
    }else if (opcao == 2){
        companyCont.setCompany(company);
        std::cout << "Digite os dados do local:" << std::endl;
        
        unsigned int number;
        unsigned int zipcode;
        std::string stringInfo;
        std::string count;
        std::string state;
        std::string city;
        std::string neighboorhood;
        std::string street;
        
        Place *place = new Place();
        std::cout << "Nome:" << std::endl;
        std::cin >> stringInfo;
        place->setName("Place " + stringInfo );
        std::cout << "Descrição:" << std::endl;
        std::cin >> stringInfo;
        place->setDescription(stringInfo);
        std::cout << "Telefone:" << std::endl;
        std::cin >> stringInfo;
        place->setPhoneNumber(stringInfo);

        std::cout << "Digite: País, estado, cidade, bairro, rua, numero e cep do local:" << std::endl;
        std::cin >> count;
        std::cin >> state;
        std::cin >> city;
        std::cin >> neighboorhood;
        std::cin >> street;
        std::cin >> number;
        std::cin >> zipcode;

        Address address("Country" + count, "State" + state,
                "City" + city, "Neighborhood" + neighboorhood,
                street + " Main St", number, 10000 + zipcode);

        place->setAddress(address);
    
        std::cout << "Local adicionado!" << std::endl;
        placeCont.addPlace(place);
    }
    else
    {
        this->setViewState(EXIT);
    }
}

void PlacesView::getPlacePage(Place *place, ViewsStatesEnum viewState)
{
    if (viewState == PLACE_DESCRIPTION)
    {
        // place description
        // print place description
        std::cout << place->getAddress().getStreet()<< std::endl;
        std::cout << place->getPhoneNumber() << std::endl;
        std::cout << place->getDescription() << std::endl;

    }
    else if (viewState == PLACE_EVENTS)
    {
        Event *event = new Event();

        EventController evCont(event); 
        std::vector<Event *> events = evCont.getEvents();
        for (const auto &evItem : events) 
        {
            std::cout << evItem->getName() << std::endl;
            std::cout << evItem->getDescription() << std::endl;
            std::cout << evItem->getBegin() << " - " << evItem->getEnd() << std::endl;

            std::cout << "\n" << std::endl;
        }
        // print place events
    }
    else if (viewState == PLACE_REVIEWS)
    {
        // place reviews
        const std::vector<Review> reviews = place->getReviews();
        std::cout << "Lista de Avaliações:\n";
        for (const auto &revieItem : reviews) 
        {
            std::cout << revieItem.getRating() << std::endl;
            std::cout << revieItem.getComment() << std::endl;
            std::cout << "\n" << std::endl;

        }
    }else if (viewState == PLACE_ADD){
        Event event; 
        EventController evCont(&event); 
        unsigned int expectation;
        boost::posix_time::ptime evTime; 
        std::string stringInfo;
        
        std::cout << "Nome:" << std::endl;
        std::cin >> stringInfo;
        event.setName("Event " + stringInfo);
        std::cout << "Descrição:" << std::endl;
        std::cin >> stringInfo;
        event.setDescription("Description for Event " + stringInfo);
        std::cout << "Iníico do evento:" << std::endl;
        std::cin >> evTime;
        event.setBegin(evTime);
        std::cout << "Fim do evento:" << std::endl;
        std::cin >> evTime;
        event.setEnd(evTime);
        std::cout << "Expectativa do evento:" << std::endl;
        std::cin >> expectation;
        event.setExpectation(expectation);
        evCont.addEvent(&event);
        std::cout << "Evento adicionado!" << std::endl;


    }

    std::cout << "Digite 2 para ver eventos no local e 3 para ver revisões do local,4 para adicionar evento, 5 para voltar a pagina inicial:" << std::endl;
    unsigned int opcao;
    std::cin >> opcao;
    if (opcao == 2)
    {
        std::cout << "Seus eventos:" << std::endl;
        Event event; 
        Place place1; 

        EventController evCont(&event); 
        PlaceController placeCont(&place1);

        std::vector<Event *> events = evCont.getEvents();
        for (const auto &evItem : events) 
        {
            std::cout << evItem->getName() << std::endl;
            std::cout << evItem->getDescription() << std::endl;
            std::cout << evItem->getBegin() << " - " << evItem->getEnd() << std::endl;

            std::cout << "\n" << std::endl;
        }
        this->setViewState(USER_INITIAL_PAGE);

    }
    else if (opcao == 3)
    {
        this->setViewState(PLACE_REVIEWS);
    }else if(opcao == 4){
        this->setViewState(PLACE_ADD);
    }else if(opcao == 5){
        this->setViewState(USER_INITIAL_PAGE);
    }
}

void PlacesView::getUserFriendsPage(Person *person)
{
    PersonController personCont(person);

    std::cout << "Digite 1 para visualizar lista, 2 para visualizar solicitações,3 para buscar novos amigos,4 para volta a pagina inicial:" << std::endl;
    unsigned int option;
    std::cin >> option;

    if (option == 1)
    {
        personCont.setPerson(person);
        std::vector<Person*> friends = personCont.getFriends(); 

        std::cout << "Lista de Amigos:\n";
        for (const auto &friendItem : friends) 
        {
            std::cout << friendItem->getName() << std::endl;
        }
        this->setViewState(USER_FRIENDS_LIST);
    }
    else if (option == 2)
    {
        personCont.setPerson(person);
        std::vector<Person*> friendsReq = personCont.getFriendRequests();
        std::cout << "Lista de Solicitações:\n";
        for (const auto &friendItem : friendsReq) 
        {
            std::cout << friendItem->getName() << std::endl;
        }
        std::cout << "Digite o numero da pessoa na lista para adiciona-la ou -1 para sair:\n";
        int option;
        std::cin >> option;
        if (option != -1){
            personCont.acceptFriendship(friendsReq[option]);  // adiciona amigos            
        }

        this->setViewState(USER_FRIENDS_REQUESTS);
    }
    else if(option == 3){
        
        std::vector<Person *> people = personCont.getPeople();
        std::cout << "Lista de Pessoas:\n";
        for (const auto &peopleIt : people) 
        {
            std::cout << peopleIt->getName() << std::endl;
        }
        std::cout << "Digite 1 para adicionar uma pessoa como amigo ou 2 para voltar: " << std::endl;

        unsigned int option;
        std::cin >> option;

        if (option == 1){
            std::cout << "Digite o nome do amigo" << std::endl;

            std::string personName;
            std::cin >> personName;

            personCont.setPerson(person); 
            personCont.sendFriendship(personCont.getPeople(personName)[0]); // envia solicitacao de amizade a pessoa buscada
        }

        this->setViewState(USER_INITIAL_PAGE);

    }
    else if (option == 4){
        this->setViewState(USER_INITIAL_PAGE);
    }


}
