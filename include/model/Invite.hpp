#ifndef INVITE_HPP
#define INVITE_HPP

#include <boost/date_time/posix_time/posix_time.hpp>

#include "Event.hpp"


namespace places {

class Invite {
    public:
        Invite(
            unsigned int senderId,
            unsigned int receiverId,
            Event *const event
        );

        virtual ~Invite() = default;

        unsigned int getSenderId();

        unsigned int getReceiverId();

        const Event *getEvent() const;

        const boost::posix_time::ptime &getInviteDate() const;

    private:
        unsigned int senderId;
        unsigned int receiverId;
        Event *event;
        boost::posix_time::ptime inviteDate;
};

} // namespace places

#endif
