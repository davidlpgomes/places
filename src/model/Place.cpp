#include "../../include/model/Place.hpp"

#include <iterator>


using namespace places;

unsigned int Place::nextId{0};

Place::Place(): id{nextId}, company(nullptr) {
    Place::nextId++;
}

Place::Place(
    const std::string &name,
    const std::string &description,
    const std::string &phoneNumber,
    Company *const company,
    const Address &address,
    unsigned int capacity
): id{nextId}, name{name}, description{description},
   phoneNumber{phoneNumber}, company{company}, address{address},
   capacity{capacity} {
    Place::nextId++;
}

unsigned int Place::getId() const {
    return this->id;
}

const std::string &Place::getName() const {
    return this->name;
}

void Place::setName(const std::string &name) {
    this->name = name;

    return;
}

const std::string &Place::getDescription() const {
    return this->description;
}

void Place::setDescription(const std::string &description) {
    this->description = description;

    return;
}

const std::string &Place::getPhoneNumber() const {
    return this->phoneNumber;
}

void Place::setPhoneNumber(const std::string &phoneNumber) {
    this->phoneNumber = phoneNumber;

    return;
}

const Company *Place::getCompany() const {
    return this->company;
}

void Place::setCompany(Company *const company) {
    this->company = company;

    return;
}

const Address &Place::getAddress() const {
    return this->address;
}

void Place::setAddress(const Address &address) {
    this->address = address;

    return;
}

unsigned int Place::getCapacity() {
    return this->capacity;
}

void Place::setCapacity(unsigned int capacity) {
    this->capacity = capacity;

    return;
}

void Place::addBoost(const PlaceBoost &boost) {
    this->boosts.push_back(boost);

    return;
}

const std::vector<PlaceBoost> &Place::getBoosts() const {
    return this->boosts;
}

const PlaceBoost &Place::getLastBoost() const {
    return this->boosts.back();
}

void Place::addOccupation(const PlaceOccupation &occupation) {
    this->occupations.push_back(occupation);

    return;
}

const std::vector<PlaceOccupation> &Place::getOccupations() const {
    return this->occupations;
}

void Place::addSchedule(const PlaceSchedule &schedule) {
    this->schedules.push_back(schedule);

    return;
}

const std::vector<PlaceSchedule> &Place::getSchedules() const {
    return this->schedules;
}

void Place::removeSchedule(
    boost::posix_time::ptime begin,
    boost::posix_time::ptime end
) {
    std::vector<PlaceSchedule>::iterator it{this->schedules.begin()};

    for (; it != this->schedules.end(); ++it)
        if ((*it).getBegin() == begin && (*it).getEnd() == end)
            break;

    if (it == this->schedules.end())
        return;

    this->schedules.erase(it);

    return;
}

void Place::addPromotion(const SalePromotion &promotion) {
    this->promotions.push_back(promotion);

    return;
}

void Place::addReview(const Review &review) {
    this->reviews.push_back(review);

    return;
}

const std::vector<Review> &Place::getReviews() const {
    return this->reviews;
}

