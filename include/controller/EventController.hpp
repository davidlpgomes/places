#ifndef EVENT_CONTROLLER_HPP
#define EVENT_CONTROLLER_HPP

#include "Controller.hpp"


namespace places {

class EventController : public Controller {
    public:
        EventController(Event *const event);

        virtual ~EventController() = default;

        void setEvent(Event *const event);

        bool addEvent(Event *const event);

        std::vector<Event*> getEvents() const;

        std::vector<Event*> getEvents(const std::string &search) const;

    private:
        Event *event;
};

} // namespace places

#endif
