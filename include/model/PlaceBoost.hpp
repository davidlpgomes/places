#ifndef PLACE_BOOST_HPP
#define PLACE_BOOST_HPP

#include <boost/date_time/posix_time/posix_time.hpp>

#include "Payment.hpp"


namespace places {

class PlaceBoost {
    public:
        PlaceBoost();

        PlaceBoost(
            const Payment &payment,
            const boost::posix_time::ptime &begin,
            const boost::posix_time::ptime &end,
            bool valid
        );

        virtual ~PlaceBoost() = default;

        const Payment &getPayment() const;
        void setPayment(const Payment &payment);

        const boost::posix_time::ptime &getBegin() const;
        void setBegin(const boost::posix_time::ptime &begin);

        const boost::posix_time::ptime &getEnd() const;
        void setEnd(const boost::posix_time::ptime &end);

        bool isValid();
        void setValid(bool valid);

    private:
        Payment payment;

        boost::posix_time::ptime begin;
        boost::posix_time::ptime end;

        bool valid;
};

} // namespace places

#endif
