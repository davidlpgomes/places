#ifndef FRIENDSHIP_HPP
#define FRIENDSHIP_HPP

#include <boost/date_time/posix_time/posix_time.hpp>

#include "FriendshipStatusEnum.hpp"
#include "Person.hpp"


namespace places {

class Friendship {
    public:
        Friendship(
            unsigned int firstPersonId,
            unsigned int secondPersonId
        );

        virtual ~Friendship() = default;

        unsigned int getFirstPersonId();

        unsigned int getSecondPersonId();

        FriendshipStatusEnum getStatus();
        
        void setStatus(FriendshipStatusEnum status);

        const boost::posix_time::ptime &getRequestDate() const;

        const boost::posix_time::ptime &getFriendsSince() const;
        void setFriendsSince(const boost::posix_time::ptime &friendsSince);

    private:
        unsigned int firstPersonId;
        unsigned int secondPersonId;

        FriendshipStatusEnum status;

        boost::posix_time::ptime requestDate;
        boost::posix_time::ptime friendsSince;
};

} // namespace places

#endif
