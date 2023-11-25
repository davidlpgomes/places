#include "../../include/model/PlaceBoost.hpp"

using namespace places;

PlaceBoost::PlaceBoost() {}

PlaceBoost::PlaceBoost(
    const Payment &payment,
    const boost::posix_time::ptime &begin,
    const boost::posix_time::ptime &end,
    bool valid
): payment{payment}, begin{begin}, end{end}, valid{valid} {
}

const Payment &PlaceBoost::getPayment() const {
    return this->payment;
}

void PlaceBoost::setPayment(const Payment &payment) {
    this->payment = payment;

    return;
}

const boost::posix_time::ptime &PlaceBoost::getBegin() const {
    return this->begin;
}

void PlaceBoost::setBegin(const boost::posix_time::ptime &begin) {
    this->begin = begin;

    return;
}

const boost::posix_time::ptime &PlaceBoost::getEnd() const {
    return this->end;
}

void PlaceBoost::setEnd(const boost::posix_time::ptime &end) {
    this->end = end;

    return;
}

bool PlaceBoost::isValid() {
    return this->valid;
}

void PlaceBoost::setValid(bool valid) {
    this->valid = valid;

    return;
}

