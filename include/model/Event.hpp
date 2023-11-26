#ifndef EVENT_HPP
#define EVENT_HPP

#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>

#include "Place.hpp"
#include "User.hpp"


namespace places {

class Event {
    public:
        Event();

        Event(
            const std::string &name,
            const std::string &description,
            User *const owner,
            Place *const place,
            const boost::posix_time::ptime &begin,
            const boost::posix_time::ptime &end,
            unsigned int expectation
        );

        virtual ~Event() = default;

        unsigned int getId() const;

        const std::string &getName() const;
        void setName(const std::string &name);

        const std::string &getDescription() const;
        void setDescription(const std::string &description);

        const User *getOwner() const;
        void setOwner(User *const owner);

        const Place *getPlace() const;
        void setPlace(Place *const place);

        const boost::posix_time::ptime &getBegin() const;
        void setBegin(const boost::posix_time::ptime &begin);

        const boost::posix_time::ptime &getEnd() const;
        void setEnd(const boost::posix_time::ptime &end);

        unsigned int getExpectation();
        void setExpectation(unsigned int expectation);

    private:
        static unsigned int nextId;
        unsigned int id;

        std::string name;
        std::string description;

        User *owner;
        Place *place;

        boost::posix_time::ptime begin;
        boost::posix_time::ptime end;

        unsigned int expectation;
};

} // namespace places

#endif
