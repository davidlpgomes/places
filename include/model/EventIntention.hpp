#ifndef EVENT_INTENTION_HPP
#define EVENT_INTENTION_HPP

namespace places {

class EventIntention {
    public:
        EventIntention(
            unsigned int eventId,
            unsigned int personId
        );

        virtual ~EventIntention() = default;

        unsigned int getEventId();

        unsigned int getPersonId();

    private:
        unsigned int eventId;
        unsigned int personId;
};

} // namespace places

#endif
