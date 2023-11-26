#include "../../include/model/EventIntention.hpp"

using namespace places;

EventIntention::EventIntention(
    unsigned int eventId,
    unsigned int personId
): eventId{eventId}, personId{personId} {
}

unsigned int EventIntention::getEventId() const {
    return this->eventId;
}

unsigned int EventIntention::getPersonId() const {
    return this->personId;
}

bool EventIntention::operator<(const EventIntention &other) const {
    if (this->eventId == other.eventId)
        return this->personId < other.personId;

    return this->eventId < other.eventId;
}

