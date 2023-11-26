#include "../../include/controller/EventController.hpp"

using namespace places;

EventController::EventController(Event *const event): event{event} {
}

void EventController::setEvent(Event *const event) {
    this->event = event;

    return;
}

bool EventController::addEvent(
    const std::string &name,
    const std::string &description,
    User *const owner,
    Place *const place,
    const boost::posix_time::ptime &begin,
    const boost::posix_time::ptime &end,
    unsigned int expectation
) {
    Event *event{
        new Event{name, description, owner, place, begin, end, expectation}
    };

    return this->addEvent(event);
}

bool EventController::addEvent(Event *const event) {
    if (event == nullptr)
        return false;

    this->db->addEvent(event);

    return true;
}

std::vector<Event*> EventController::getEvents() const {
    const std::map<int, Event*> *events{this->db->getEvents()};

    std::vector<Event*> events_vec;

    std::map<int, Event*>::const_iterator it{events->begin()};
    for (; it != events->end(); ++it)
        events_vec.push_back((*it).second);

    return events_vec;
}

std::vector<Event*> EventController::getEvents(
    const std::string &search
) const {
    const std::map<int, Event*> *events{this->db->getEvents()};

    std::vector<Event*> events_vec;

    std::map<int, Event*>::const_iterator it{events->begin()};
    for (; it != events->end(); ++it)
        if (
            (*it).second->getName().find(search) != std::string::npos ||
            search.find((*it).second->getName()) != std::string::npos
        )
            events_vec.push_back((*it).second);

    return events_vec;
}

