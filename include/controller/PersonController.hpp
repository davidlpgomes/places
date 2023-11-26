#ifndef PERSON_CONTROLLER_HPP
#define PERSON_CONTROLLER_HPP

#include <vector>

#include "Controller.hpp"


namespace places {

class PersonController : public Controller {
    public:
        PersonController(Person *const person);

        virtual ~PersonController() = default;

        void setPerson(Person *const person);

        bool addPerson(Person *const person);

        Person *getPersonById(unsigned int id) const;

        std::vector<Person*> getPeople() const;

        std::vector<Person*> getPeople(const std::string &search) const;

        std::vector<Person*> getFriends() const;

        std::vector<Person*> getFriendRequets() const;

        bool sendFriendship(Person *const receiver);

        bool acceptFriendship(Person *const sender);

        bool declineFriendship(Person *const sender);

        bool unfriend(Person *const person);

        bool inviteFriend(Person *const person, Event *const event);

        bool followPlace(Place *const place);

    private:
        Person *person;
};

}

#endif
