#include "../../include/model/SalePromotion.hpp"

using namespace places;

SalePromotion::SalePromotion()
    : discount(0),
      startDate(boost::posix_time::not_a_date_time),
      endDate(boost::posix_time::not_a_date_time),
      valid(false) {}

SalePromotion::SalePromotion(const unsigned char discount,
                             const boost::posix_time::ptime &startDate,
                             const boost::posix_time::ptime &endDate)
    : discount(discount), startDate(startDate), endDate(endDate), valid(true) {}

unsigned char SalePromotion::getDiscount() const { return discount; }

void SalePromotion::setDiscount(const unsigned char discount) {
    this->discount = discount;

    return;
}

const boost::posix_time::ptime &SalePromotion::getStartDate() const {
    return startDate;
}

void SalePromotion::setStartDate(const boost::posix_time::ptime &startDate) {
    this->startDate = startDate;

    return;
}

const boost::posix_time::ptime &SalePromotion::getEndDate() const {
    return endDate;
}

void SalePromotion::setEndDate(const boost::posix_time::ptime &endDate) {
    this->endDate = endDate;

    return;
}

bool SalePromotion::isValid() const { return valid; }

void SalePromotion::setValid(const bool valid) {
    this->valid = valid;

    return;
}
