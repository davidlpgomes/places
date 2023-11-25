#include "../../include/model/PlaceOccupation.hpp"

using namespace places;

PlaceOccupation::PlaceOccupation() {}

PlaceOccupation::PlaceOccupation(
    const boost::posix_time::ptime &date,
    unsigned int occupation
): date(date), occupation(occupation) {
}

const boost::posix_time::ptime &PlaceOccupation::getDate() const {
    return this->date;
}

void PlaceOccupation::setDate(const boost::posix_time::ptime &date) {
    this->date = date;

    return;
}

unsigned int PlaceOccupation::getOccupation() const {
    return this->occupation;
}

void PlaceOccupation::setOccupation(const unsigned int occupation) {
    this->occupation = occupation;

    return;
}

