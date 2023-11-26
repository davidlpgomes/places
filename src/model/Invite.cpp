#include "../../include/model/Invite.hpp"

using namespace places;

Invite::Invite(
    unsigned int senderId,
    unsigned int receiverId,
    Event *const event
): senderId{senderId}, receiverId{receiverId}, event{event} {
    this->inviteDate = boost::posix_time::second_clock::local_time();
}

unsigned int Invite::getSenderId() {
    return this->senderId;
}

unsigned int Invite::getReceiverId() {
    return this->receiverId;
}

const Event *Invite::getEvent() const {
    return this->event;
}

const boost::posix_time::ptime &Invite::getInviteDate() const {
    return this->inviteDate;
}

