#ifndef REVIEW_HPP
#define REVIEW_HPP

#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>

#include "Person.hpp"


namespace places {

class Review {
    public:
        Review();

        Review(
            const std::string &comment,
            const unsigned char rating,
            Person *const person
        );

        virtual ~Review() = default;

        const std::string &getComment() const;
        void setComment(const std::string &comment);

        unsigned char getRating() const;
        void setRating(const unsigned char rating);

        const boost::posix_time::ptime &getDate() const;

        const Person *getPerson() const;
        void setPerson(Person *const person);

    private:
        std::string comment;
        unsigned char rating;
        boost::posix_time::ptime date;
        Person *person;
};

} // namespace places

#endif
