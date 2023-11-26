#ifndef EVENT_CONTROLLER_HPP
#define EVENT_CONTROLLER_HPP

#include "Controller.hpp"


namespace places {

class EventController : public Controller {
    public:
        EventController(Event *const event);

        virtual ~EventController() = default;

        void setEvent(Event *const event);

        bool addEvent(
            const std::string &name,
            const std::string &description,
            User *const owner,
            Place *const place,
            const boost::posix_time::ptime &begin,
            const boost::posix_time::ptime &end,
            unsigned int expectation
        );

        bool addEvent(Event *const event);

        std::vector<Event*> getEvents() const;

        std::vector<Event*> getEvents(const std::string &search) const;

    private:
        Event *event;
};

} // namespace places

#endif
