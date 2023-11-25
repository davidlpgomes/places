#ifndef SALE_PROMOTION_HPP
#define SALE_PROMOTION_HPP

#include <boost/date_time/posix_time/posix_time.hpp>

namespace places {
class SalePromotion {
   public:
    SalePromotion();
    SalePromotion(const unsigned char discount,
                  const boost::posix_time::ptime &startDate,
                  const boost::posix_time::ptime &endDate);

    virtual ~SalePromotion() = default;

    unsigned char getDiscount() const;
    void setDiscount(const unsigned char discount);

    const boost::posix_time::ptime &getStartDate() const;
    void setStartDate(const boost::posix_time::ptime &startDate);

    const boost::posix_time::ptime &getEndDate() const;
    void setEndDate(const boost::posix_time::ptime &endDate);

    bool isValid() const;
    void setValid(const bool valid);

   private:
    unsigned char discount;
    boost::posix_time::ptime startDate;
    boost::posix_time::ptime endDate;
    bool valid;
};

}

#endif