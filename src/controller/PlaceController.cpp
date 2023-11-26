#include "../../include/controller/PlaceController.hpp"

using namespace places;

PlaceController::PlaceController(Place *const place): place{place} {
}

void PlaceController::setPlace(Place *const place) {
    this->place = place;

    return;
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

