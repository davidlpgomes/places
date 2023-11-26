#include "../../include/model/Friendship.hpp"

using namespace places;

Friendship::Friendship(
    unsigned int firstPersonId,
    unsigned int secondPersonId
): firstPersonId{firstPersonId}, secondPersonId{secondPersonId} {
    this->requestDate = boost::posix_time::second_clock::local_time();
}

unsigned int Friendship::getFirstPersonId() {
    return this->firstPersonId;
}

unsigned int Friendship::getSecondPersonId() {
    return this->secondPersonId;
}

FriendshipStatusEnum Friendship::getStatus() {
    return this->status;
}

void Friendship::setStatus(FriendshipStatusEnum status) {
    this->status = status;

    return;
}

const boost::posix_time::ptime &Friendship::getRequestDate() const {
    return this->requestDate;
}

const boost::posix_time::ptime &Friendship::getFriendsSince() const {
    return this->friendsSince;
}

void Friendship::setFriendsSince(
    const boost::posix_time::ptime &friendsSince) {
    this->friendsSince = friendsSince;

    return;
}

