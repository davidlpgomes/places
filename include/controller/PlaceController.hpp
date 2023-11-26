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

        bool addPlace(
            const std::string &name,
            const std::string &description,
            const std::string &phoneNumber,
            Company *const company,
            const Address &address,
            unsigned int capacity
        );

        bool addPlace(Place *const place);

        std::vector<Place*> getPlaces() const;

        std::vector<Place*> getPlaces(const std::string &search) const;

        float getRating() const;

        unsigned int getNumberOfFollowers() const;

        bool addPlaceSchedule(const PlaceSchedule &schedule);

        bool addPlaceSchedule(
            const boost::posix_time::ptime begin,
            const boost::posix_time::ptime end
        );

        bool addPlaceOccupation(const PlaceOccupation &occupation);

        bool addPlaceOccupation(const unsigned int occupation);

        bool addSalePromotion(const SalePromotion &promotion);

        bool addSalePromotion(
            const unsigned char discount,
            const boost::posix_time::ptime &startDate,
            const boost::posix_time::ptime &endDate
        );

        bool addPlaceBoost(const PlaceBoost &boost);

        bool addPlaceBoost(
            const boost::posix_time::ptime &startDate,
            const boost::posix_time::ptime &endDate,
            unsigned int value,
            PaymentMethodEnum method
        );

    private:
        Place *place;
};

} // namespace places

#endif
