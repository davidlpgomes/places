#include "../../include/model/PlaceOccupation.hpp"

using namespace places;

PlaceOccupation::PlaceOccupation() {}

PlaceOccupation::PlaceOccupation(
    unsigned int occupation
): occupation(occupation) {
    this->date = boost::posix_time::second_clock::local_time();
}

const boost::posix_time::ptime &PlaceOccupation::getDate() const {
    return this->date;
}

unsigned int PlaceOccupation::getOccupation() const {
    return this->occupation;
}

void PlaceOccupation::setOccupation(const unsigned int occupation) {
    this->occupation = occupation;

    return;
}

