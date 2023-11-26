#ifndef PLACE_CONTROLLER_HPP
#define PLACE_CONTROLLER_HPP

#include <string>

#include "Controller.hpp"


namespace places {

class PlaceController : public Controller {
    public:
        PlaceController(Place *const place);

        virtual ~PlaceController() = default;

        void setPlace(Place *const place);

        bool addPlace(Place *const place);

        std::vector<Place*> getPlaces() const;

        std::vector<Place*> getPlaces(const std::string &search) const;

        float getRating() const;

        unsigned int getNumberOfFollowers() const;

    private:
        Place *place;
};

} // namespace places

#endif
