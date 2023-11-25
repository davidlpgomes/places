#include "../../include/model/PlaceSchedule.hpp"

using namespace places;

PlaceSchedule::PlaceSchedule() {}

PlaceSchedule::PlaceSchedule(
    const boost::posix_time::ptime &begin,
    const boost::posix_time::ptime &end
): begin{begin}, end{end} {
}

const boost::posix_time::ptime &PlaceSchedule::getBegin() const {
    return this->begin;
}

void PlaceSchedule::setBegin(const boost::posix_time::ptime &begin) {
    this->begin = begin;

    return;
}

const boost::posix_time::ptime &PlaceSchedule::getEnd() const {
    return this->end;
}

void PlaceSchedule::setEnd(const boost::posix_time::ptime &end) {
    this->end = end;

    return;
}

