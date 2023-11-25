#ifndef PLACE_HPP
#define PLACE_HPP

#include <string>
#include <vector>

#include "Address.hpp"
#include "Company.hpp"
#include "PlaceBoost.hpp"
#include "PlaceOccupation.hpp"
#include "PlaceSchedule.hpp"
#include "SalePromotion.hpp"


namespace places {

class Place {
    public:
        Place();

        Place(
            const std::string &name,
            const std::string &description,
            const std::string &phoneNumber,
            Company *const company,
            const Address &address,
            unsigned int capacity
        );

        virtual ~Place() = default;

        const std::string &getName() const;
        void setName(const std::string &name);

        const std::string &getDescription() const;
        void setDescription(const std::string &description);

        const std::string &getPhoneNumber() const;
        void setPhoneNumber(const std::string &phoneNumber);

        const Company *getCompany() const;
        void setCompany(Company *const company);

        const Address &getAddress() const;
        void setAddress(const Address &address);

        unsigned int getCapacity();
        void setCapacity(unsigned int capacity);

        void addBoost(const PlaceBoost &boost);

        void addOccupation(const PlaceOccupation &occupation);

        void addSchedule(const PlaceSchedule &schedule);
        void removeSchedule(
            boost::posix_time::ptime begin,
            boost::posix_time::ptime end
        );

        void addPromotion(const SalePromotion &promotion);

    private:
        std::string name;
        std::string description;
        std::string phoneNumber;

        Company *company;
        Address address;

        unsigned int capacity;

        std::vector<PlaceBoost> boosts;
        std::vector<PlaceOccupation> occupations;
        std::vector<PlaceSchedule> schedules;

        std::vector<SalePromotion> promotions;
};

} // namespace places

#endif
