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

        unsigned int getEventId() const;

        unsigned int getPersonId() const;

        bool operator<(const EventIntention &other) const;

    private:
        unsigned int eventId;
        unsigned int personId;
};

} // namespace places

#endif
