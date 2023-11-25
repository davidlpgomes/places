#ifndef PLACE_SCHEDULE_HPP
#define PLACE_SCHEDULE_HPP

#include <boost/date_time/posix_time/posix_time.hpp>

namespace places {
class PlaceSchedule {
   public:
    PlaceSchedule();
    PlaceSchedule(const boost::posix_time::ptime &begin,
                  const boost::posix_time::ptime &end);

    virtual ~PlaceSchedule() = default;

    const boost::posix_time::ptime &getBegin() const;
    void setBegin(const boost::posix_time::ptime &begin);

    const boost::posix_time::ptime &getEnd() const;
    void setEnd(const boost::posix_time::ptime &end);

   private:
    boost::posix_time::ptime begin;
    boost::posix_time::ptime end;
};
}  // namespace places

#endif