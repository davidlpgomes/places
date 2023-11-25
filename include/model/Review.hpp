#ifndef REVIEW_HPP
#define REVIEW_HPP

#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>


namespace places {

class Review {
    public:
        Review();

        Review(
            const std::string &comment,
            const unsigned char rating,
            const boost::posix_time::ptime &date
        );

        virtual ~Review() = default;

        const std::string &getComment() const;
        void setComment(const std::string &comment);

        unsigned char getRating() const;
        void setRating(const unsigned char rating);

        const boost::posix_time::ptime &getDate() const;
        void setDate(const boost::posix_time::ptime &date);

    private:
        std::string comment;
        unsigned char rating;
        boost::posix_time::ptime date;
};

} // namespace places

#endif
