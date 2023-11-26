#ifndef FOLLOW_HPP
#define FOLLOW_HPP

#include <boost/date_time/posix_time/posix_time.hpp>


namespace places {

class Follow {
    public:
        Follow(
            unsigned int personId,
            unsigned int placeId
        );

        virtual ~Follow() = default;

        unsigned int getPersonId();

        unsigned int getPlaceId();

        const boost::posix_time::ptime &getFollowDate() const;

    private:
        unsigned int personId;
        unsigned int placeId;

        boost::posix_time::ptime followDate;
};

} // namespace places

#endif
