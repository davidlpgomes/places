#include "../../include/model/Follow.hpp"

using namespace places;

Follow::Follow(
    unsigned int personId,
    unsigned int companyId
): personId{personId}, companyId{companyId} {
    this->followDate = boost::posix_time::second_clock::local_time();
}

unsigned int Follow::getPersonId() {
    return this->personId;
}

unsigned int Follow::getCompanyId() {
    return this->companyId;
}

const boost::posix_time::ptime &Follow::getFollowDate() const {
    return this->followDate;
}

