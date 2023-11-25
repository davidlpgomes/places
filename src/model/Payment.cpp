#include "../../include/model/Payment.hpp"

using namespace places;

Payment::Payment() {}

Payment::Payment(
    unsigned int value,
    PaymentMethodEnum method,
    PaymentStatusEnum status,
    const boost::posix_time::ptime &date
): value{value}, method{method}, status{status}, date{date} {
}

unsigned int Payment::getValue() {
    return this->value;
}

void Payment::setValue(unsigned int value) {
    this->value = value;

    return;
}

PaymentMethodEnum Payment::getMethod() {
    return this->method;
}

void Payment::setMethod(PaymentMethodEnum method) {
    this->method = method;

    return;
}

PaymentStatusEnum Payment::getStatus() {
    return this->status;
}

void Payment::setStatus(PaymentStatusEnum status) {
    this->status = status;

    return;
}

const boost::posix_time::ptime &Payment::getDate() const {
    return this->date;
}

void Payment::setDate(const boost::posix_time::ptime &date) {
    this->date = date;

    return;
}

