#include "../../include/model/Event.hpp"

using namespace places;

Event::Event() {}

Event::Event(
    const std::string &name,
    const std::string &description,
    User *const owner,
    Place *const place,
    const boost::posix_time::ptime &begin,
    const boost::posix_time::ptime &end,
    unsigned int expectation
): name{name}, description{description}, owner{owner}, place{place},
   begin{begin}, end{end}, expectation{expectation} {
}

const std::string &Event::getName() const {
    return this->name;
}

void Event::setName(const std::string &name) {
    this->name = name;

    return;
}

const std::string &Event::getDescription() const {
    return this->description;
}

void Event::setDescription(const std::string &description) {
    this->description = description;

    return;
}

const User *Event::getOwner() const {
    return this->owner;
}

void Event::setOwner(User *const owner) {
    this->owner = owner;

    return;
}

const Place *Event::getPlace() const {
    return this->place;
}

void Event::setPlace(Place *const place) {
    this->place = place;

    return;
}

const boost::posix_time::ptime &Event::getBegin() const {
    return this->begin;
}

void Event::setBegin(const boost::posix_time::ptime &begin) {
    this->begin = begin;

    return;
}

const boost::posix_time::ptime &Event::getEnd() const {
    return this->end;
}

void Event::setEnd(const boost::posix_time::ptime &end) {
    this->end = end;

    return;
}

unsigned int Event::getExpectation() {
    return this->expectation;
}

void Event::setExpectation(unsigned int expectation) {
    this->expectation = expectation;

    return;
}

