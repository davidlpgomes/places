#ifndef PAYMENT_HPP
#define PAYMENT_HPP

#include <boost/date_time/posix_time/posix_time.hpp>

#include "PaymentMethodEnum.hpp"
#include "PaymentStatusEnum.hpp"


namespace places {

class Payment {
    public:
        Payment();

        Payment(
            unsigned int value,
            PaymentMethodEnum method,
            PaymentStatusEnum status,
            const boost::posix_time::ptime &date
        );

        virtual ~Payment() = default;

        unsigned int getValue();
        void setValue(unsigned int value);

        PaymentMethodEnum getMethod();
        void setMethod(PaymentMethodEnum method);

        PaymentStatusEnum getStatus();
        void setStatus(PaymentStatusEnum status);

        const boost::posix_time::ptime &getDate() const;
        void setDate(const boost::posix_time::ptime &date);

    private:
        unsigned int value;

        PaymentMethodEnum method;
        PaymentStatusEnum status;

        boost::posix_time::ptime date;
};

} // namespace places

#endif
