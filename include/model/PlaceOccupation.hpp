#ifndef PLACE_OCCUPATION_HPP
#define PLACE_OCCUPATION_HPP

#include <boost/date_time/posix_time/posix_time.hpp>

namespace places {
class PlaceOccupation {
   public:
    PlaceOccupation();
    PlaceOccupation(const boost::posix_time::ptime &date,
                    unsigned int occupation);

    virtual ~PlaceOccupation() = default;

    const boost::posix_time::ptime &getDate() const;
    void setDate(const boost::posix_time::ptime &date);

    unsigned int getOccupation() const;
    void setOccupation(const unsigned int occupation);

   private:
    boost::posix_time::ptime date;
    unsigned int occupation;
    
};
}  // namespace places
#endif