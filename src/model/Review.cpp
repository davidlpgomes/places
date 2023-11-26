#include "../../include/model/Review.hpp"

using namespace places;

Review::Review(): rating(0) {}

Review::Review(
    const std::string &comment,
    const unsigned char rating,
    Person *const person
): comment{comment}, rating{rating}, person{person} {
    this->date = boost::posix_time::second_clock::local_time();
}

const std::string &Review::getComment() const {
    return comment;
}

void Review::setComment(const std::string &comment) {
    this->comment = comment;

    return;
}

unsigned char Review::getRating() const {
    return rating;
}

void Review::setRating(const unsigned char rating) {
    this->rating = rating;

    return;
}

const boost::posix_time::ptime &Review::getDate() const {
    return date;
}

void Review::setDate(const boost::posix_time::ptime &date) {
    this->date = date;

    return;
}

const Person *Review::getPerson() const {
    return this->person;
}

void Review::setPerson(Person *const person) {
    this->person = person;
    
    return;
}

