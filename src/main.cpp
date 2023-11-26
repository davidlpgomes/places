#include <iostream>
#include <set>

#include "../include/model/Database.hpp"
#include "../include/view/PlacesView.hpp"
#include "../include/view/PlacesStatesEnum.hpp"

using namespace places;

int main() {
    Database *db{Database::getInstance()};

    Person *p1{new Person{}};
    Person *p2{new Person{}};
    Person *p3{new Person{}};

    Event *e1{new Event{}};
    Event *e2{new Event{}};
    Event *e3{new Event{}};
    p1->setName("Pedro");
    p1->setUserName("Pedro_123");

    EventIntention ei1{EventIntention{e2->getId(), p1->getId()}};
    EventIntention ei2{EventIntention{e3->getId(), p2->getId()}};
    EventIntention ei3{EventIntention{e1->getId(), p3->getId()}};

    db->addPerson(p1);
    db->addPerson(p2);
    db->addPerson(p3);

    db->addEvent(e1);
    db->addEvent(e2);
    db->addEvent(e3);
   
    // Create Address instances
    Address address1("Country1", "State1", "City1", "Neighborhood1", "123 Main St", 1, 12345);
    Address address2("Country2", "State2", "City2", "Neighborhood2", "456 Oak St", 2, 67890);
    Address address3("Country3", "State3", "City3", "Neighborhood3", "789 Pine St", 3, 13579);

    // Create Company instances
    Company company1(123456789, "company1@example.com", "password1", "123-456-7890", "Company One", address1);
    Company company2(987654321, "company2@example.com", "password2", "987-654-3210", "Company Two", address2);
 
    db->addCompany(&company1);
    db->addCompany(&company2);

    db->addEventIntetion(ei1);
    db->addEventIntetion(ei2);
    db->addEventIntetion(ei3);

    const std::multiset<EventIntention> *eis{db->getEventIntetions()};

    std::multiset<EventIntention>::const_iterator it{eis->begin()};

    PlacesView placesView{1, LOGIN};
    placesView.getInitialPage();
    
    if (placesView.getViewType() == 1){
        // std::cout << "Tela Empresa" << std::endl;
        placesView.getCompanyInitialPage(&company1); 
    }else {
        placesView.getUserInitialPage(p1); 
    }
    // for (; it != eis->end(); ++it)
        // std::cout << "e=" << (*it).getEventId() << " p=" << (*it).getPersonId() << std::endl;

    return 0;
}
