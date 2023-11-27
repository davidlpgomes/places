#include "../include/model/Database.hpp"
#include "../include/view/PlacesView.hpp"
#include "../include/view/PlacesStatesEnum.hpp"
#include <iostream>
#include <set>

using namespace places;

int main()
{
    Database *db{Database::getInstance()};

    std::vector<Person *> persons;
    std::vector<Company *> companies;
    std::vector<Place *> places;
    std::vector<Event *> events;
    // Criar 50 instâncias de Person, Company, Place
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

        // Adiciona no Array
        persons.push_back(person);
        companies.push_back(company);
        events.push_back(event);
        places.push_back(place);
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

    while (running)
    {
        switch (placesView.getViewState())
        {
        case LOGIN:
            placesView.getInitialPage();
            break;
        case COMPANY_INITIAL_PAGE:
            if (!companies.empty())
            {
                placesView.getCompanyInitialPage(companies[0]);
            }
            break;
        case USER_INITIAL_PAGE:
            if (!persons.empty())
            {
                placesView.getUserInitialPage(persons[0]);
            }
            break;
        case USER_FRIENDS_REQUESTS:
            if (!persons.empty())
            {
                placesView.getUserFriendsPage(persons[0]);
            }
            break;
        case USER_FRIENDS_LIST:
            if (!persons.empty())
            {
                placesView.getUserFriendsPage(persons[0]);
            }
            break;
        case PLACE_DESCRIPTION:
            placesView.getPlacePage(&place1, PLACE_DESCRIPTION);
            break;
        case PLACE_EVENTS:
            placesView.getPlacePage(&place1, PLACE_EVENTS);
            break;
        case PLACE_REVIEWS:
            placesView.getPlacePage(&place1, PLACE_REVIEWS);
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
