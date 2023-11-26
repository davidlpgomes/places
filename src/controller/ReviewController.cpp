#include "../../include/controller/ReviewController.hpp"

using namespace places;

ReviewController::ReviewController() {}

bool ReviewController::addReview(
    const std::string &comment,
    unsigned char rating,
    Person *person,
    Place *place
) {
    Review review{Review{comment, rating, person}};

    place->addReview(review);

    return true;
}
