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

    EventIntention ei1{EventIntention{e2->getId(), p1->getId()}};
    EventIntention ei2{EventIntention{e3->getId(), p2->getId()}};
    EventIntention ei3{EventIntention{e1->getId(), p3->getId()}};

    db->addPerson(p1);
    db->addPerson(p2);
    db->addPerson(p3);

    db->addEvent(e1);
    db->addEvent(e2);
    db->addEvent(e3);

    db->addEventIntetion(ei1);
    db->addEventIntetion(ei2);
    db->addEventIntetion(ei3);

    const std::multiset<EventIntention> *eis{db->getEventIntetions()};

    std::multiset<EventIntention>::const_iterator it{eis->begin()};

    PlacesView placesView{1, LOGIN};
    placesView.getInitialPage();
    
    if (placesView.getViewType() == 1){
        std::cout << "Tela Empresa" << std::endl;
    }else {
        std::cout << "Tela usuario" << std::endl;
    }
    // for (; it != eis->end(); ++it)
        // std::cout << "e=" << (*it).getEventId() << " p=" << (*it).getPersonId() << std::endl;

    return 0;
}
