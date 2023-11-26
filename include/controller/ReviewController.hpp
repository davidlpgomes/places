#ifndef REVIEW_CONTROLLER
#define REVIEW_CONTROLLER

#include "Controller.hpp"


namespace places {

class ReviewController : public Controller {
    public:
        ReviewController();

        virtual ~ReviewController() = default;

        bool addReview(
            const std::string &comment,
            unsigned char rating,
            Person *person,
            Place *place
        );
};

} // namespace places

#endif
