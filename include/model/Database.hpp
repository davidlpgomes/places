#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <set>
#include <map>
#include <vector>

#include "Company.hpp"
#include "Event.hpp"
#include "EventIntention.hpp"
#include "Follow.hpp"
#include "Friendship.hpp"
#include "Invite.hpp"
#include "Person.hpp"
#include "Place.hpp"


namespace places {

class Database {
    public:
        Database(Database &other) = delete;
        void operator=(const Database &) = delete;

        static Database *getInstance();

        const std::map<int, Person*> *getPersons() const;
        void addPerson(Person *const person);

        const std::map<int, Company*> *getCompanies() const;
        void addCompany(Company *const company);

        const std::map<int, Event*> *getEvents() const;
        void addEvent(Event *const event);

        const std::map<int, Place*> *getPlaces() const;
        void addPlace(Place *const place);

        const std::vector<Follow*> *getFollows() const;
        void addFollow(Follow *const follow);

        const std::vector<Friendship*> *getFriendships() const;
        void addFriendship(Friendship *const friendship);

        const std::vector<Invite*> *getInvites() const;
        void addInvite(Invite *const invite);

        const std::multiset<EventIntention> *getEventIntetions() const;
        void addEventIntetion(const EventIntention &intention);

    private:
        Database();
        virtual ~Database() = default;

        static Database *database;

        std::map<int, Person*> *persons;
        std::map<int, Company*> *companies;
        std::map<int, Event*> *events;
        std::map<int, Place*> *places;

        std::vector<Follow*> *follows;
        std::vector<Friendship*> *friendships;
        std::vector<Invite*> *invites;

        std::multiset<EventIntention> *intentions;
};

} // namespace places

#endif
