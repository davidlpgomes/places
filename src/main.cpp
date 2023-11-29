#include "../include/model/Database.hpp"
#include "../include/view/PlacesView.hpp"
#include "../include/view/PlacesStatesEnum.hpp"
#include "../include/controller/PersonController.hpp"

#include <iostream>
#include <set>
#include <random>
#include <chrono>

using namespace places;

int main()
{
    Database *db{Database::getInstance()};

    std::vector<Person *> persons;
    std::vector<Company *> companies;
    std::vector<Place *> places;
    std::vector<Event *> events;

    // Criar 50 instâncias de Person, Company, Place e Event
    for (int i = 1; i <= 50; ++i)
    {
        // Instância Person
        Person *person = new Person();
        person->setName("Person" + std::to_string(i));
        person->setUserName("UserName" + std::to_string(i));
        // Instância Address
        Address address("Country" + std::to_string(i), "State" + std::to_string(i),
                        "City" + std::to_string(i), "Neighborhood" + std::to_string(i),
                        std::to_string(i) + " Main St", i, 10000 + i);

        // Instância Place para cada Address
        Place *place = new Place();
        place->setName("Place " + std::to_string(i));
        place->setAddress(address);
        place->setPhoneNumber("4112345678");
        place->setDescription("Esse evento vai ser show, começa 22h"); 

        // Instância Company
        Company *company = new Company(123000 + i, "email" + std::to_string(i) + "@example.com",
                                       "password" + std::to_string(i), "123-456-" + std::to_string(7000 + i),
                                       "Company " + std::to_string(i), address);

        // Instância Event
        Event *event = new Event();
        event->setName("Event " + std::to_string(i));
        event->setDescription("Description for Event " + std::to_string(i));

        // Adiciona no DB
        db->addPerson(person);
        db->addCompany(company);
        db->addEvent(event);
        db->addPlace(place);

        // Adiciona no Array
        persons.push_back(person);
        companies.push_back(company);
        events.push_back(event);
        places.push_back(place);

        PersonController personCont(person);
        if (i > 10 && i < 30)
            personCont.sendFriendship(persons[10]);


        if (i == 50){
            for (int j = 1; j <= 10; ++j){
                personCont.setPerson(persons[10]);
                std::vector<Person*> friendsReq = personCont.getFriendRequests();
                personCont.acceptFriendship(friendsReq[j]);  // adiciona amigos            
            }

        }
    }

    // Criar EventIntention
    for (size_t i = 0; i < std::min(events.size(), places.size()); ++i)
    {
        EventIntention ei(events[i]->getId(), places[i]->getId());
        db->addEventIntetion(ei);
    }

    Place place1;

    const std::multiset<EventIntention> *eis{db->getEventIntetions()};

    std::multiset<EventIntention>::const_iterator it{eis->begin()};

    PlacesView placesView{1, LOGIN};

    bool running = true;

    User *user{nullptr};

    while (running) {
        placesView.clearTerminal();
        placesView.printHeader();

        switch (placesView.getViewState()) {
            case LOGIN:
                user = (User*) placesView.getInitialPage();
                break;
            case REGISTER_PERSON:
                placesView.getRegisterPersonPage();
                break;
            case REGISTER_COMPANY:
                placesView.getRegisterCompanyPage();
                break;
            case COMPANY_INITIAL_PAGE:
                placesView.getCompanyInitialPage((Company*) user);
                break;
            case USER_INITIAL_PAGE:
                placesView.getUserInitialPage((Person*) user);
                break;
            case USER_FRIENDS_REQUESTS:
                placesView.getUserFriendsPage((Person*) user);
                break;
            case USER_FRIENDS_LIST:
                placesView.getUserFriendsPage((Person*) user);
                break;
            case PLACE_DESCRIPTION:
                placesView.getPlacePage(places[1], PLACE_DESCRIPTION);
                break;
            case PLACE_EVENTS:
                placesView.getPlacePage(places[1], PLACE_EVENTS);
                break;
            case PLACE_REVIEWS:
                placesView.getPlacePage(places[1], PLACE_REVIEWS);
                break;
            case EXIT:
                running = false;
                break;
            default:
                break;
        }
    }

    return 0;
}

