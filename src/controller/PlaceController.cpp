#include "../../include/controller/PlaceController.hpp"

using namespace places;

PlaceController::PlaceController(Place *const place): place{place} {
}

void PlaceController::setPlace(Place *const place) {
    this->place = place;

    return;
}

bool PlaceController::addPlace(
    const std::string &name,
    const std::string &description,
    const std::string &phoneNumber,
    Company *const company,
    const Address &address,
    unsigned int capacity
) {
    Place *place{new Place{
        name, description, phoneNumber, company, address, capacity
    }};

    return this->addPlace(place);
}

bool PlaceController::addPlace(Place *const place) {
    if (place == nullptr)
        return false;

    this->db->addPlace(place);

    return true;
}

std::vector<Place*> PlaceController::getPlaces() const {
    const std::map<int, Place*> *places{this->db->getPlaces()};

    std::vector<Place*> places_vec;

    std::map<int, Place*>::const_iterator it{places->begin()};

    for (; it != places->end(); ++it)
        places_vec.push_back((*it).second);

    return places_vec;
}


std::vector<Place*> PlaceController::getPlaces(
    const std::string &search
) const {
    const std::map<int, Place*> *places{this->db->getPlaces()};

    std::vector<Place*> places_vec;

    std::map<int, Place*>::const_iterator it{places->begin()};

    for (; it != places->end(); ++it)
        if (
            (*it).second->getName().find(search) != std::string::npos ||
            search.find((*it).second->getName()) != std::string::npos
        )
            places_vec.push_back((*it).second);

    return places_vec;
}

float PlaceController::getRating() const {
    float sum{0};

    std::vector<Review>::const_iterator it{this->place->getReviews().begin()};

    for (; it != this->place->getReviews().end(); ++it)
        sum += (*it).getRating();

    return sum / this->place->getReviews().size();
}

unsigned int PlaceController::getNumberOfFollowers() const {
    const std::vector<Follow*> *follows = this->db->getFollows();

    unsigned int counter{0};

    std::vector<Follow*>::const_iterator it{follows->begin()};
    for (; it != follows->end(); ++it)
        if ((*it)->getPlaceId() == this->place->getId())
            counter++;

    return counter;
}

