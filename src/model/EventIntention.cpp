#include "../../include/model/EventIntention.hpp"

using namespace places;

EventIntention::EventIntention(
    unsigned int eventId,
    unsigned int personId
): eventId{eventId}, personId{personId} {
}

unsigned int EventIntention::getEventId() {
    return this->eventId;
}

unsigned int EventIntention::getPersonId() {
    return this->personId;
}

