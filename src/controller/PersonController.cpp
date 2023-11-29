#include "../../include/controller/PersonController.hpp"

using namespace places;

PersonController::PersonController(Person *const person): person{person} {
}

void PersonController::setPerson(Person *const person) {
    this->person = person;

    return;
}

bool PersonController::addPerson(
    const std::string &userName,
    unsigned int cpf,
    const boost::posix_time::ptime &birthDate,
    const std::string &email,
    const std::string &password,
    const std::string &phoneNumber,
    const std::string &name,
    const Address &address
) {
    Person *person{new Person{
        userName, cpf, birthDate, email, password, phoneNumber, name, address
    }};

    return this->addPerson(person);
}

bool PersonController::addPerson(Person *const person) {
    if (person == nullptr)
        return false;

    this->db->addPerson(person);

    return true;
}

Person *PersonController::getPersonById(unsigned int id) const {
    return this->db->getPersons()->find(id)->second;
}

Person *PersonController::getPersonByEmail(const std::string &email) const {
    const std::map<int, Person*> *people{this->db->getPersons()};

    std::map<int, Person*>::const_iterator it{people->begin()};

    Person *person{nullptr};

    for (; it != people->end(); ++it)
        if ((*it).second->getEmail() == email) {
            person = (*it).second;
            break;
        }

    return person;
}

std::vector<Person*> PersonController::getPeople() const {
    const std::map<int, Person*> *people{this->db->getPersons()};

    std::vector<Person*> people_vec;

    std::map<int, Person*>::const_iterator it{people->begin()};

    for (; it != people->end(); ++it)
        people_vec.push_back((*it).second);

    return people_vec;
}

std::vector<Person*> PersonController::getPeople(
    const std::string &search
) const {
    const std::map<int, Person*> *people{this->db->getPersons()};

    std::vector<Person*> people_vec;

    std::map<int, Person*>::const_iterator it{people->begin()};

    for (; it != people->end(); ++it)
        if (
            (*it).second->getName().find(search) != std::string::npos ||
            search.find((*it).second->getName()) != std::string::npos
        )
            people_vec.push_back((*it).second);

    return people_vec;
}

std::vector<Person*> PersonController::getFriends() const {
    const std::vector<Friendship*> *friendships{this->db->getFriendships()};

    std::vector<Person*> friends;

    std::vector<Friendship*>::const_iterator it{friendships->begin()};

    for (; it != friendships->end(); ++it) {
        if (
            (*it)->getFirstPersonId() == this->person->getId() &&
            (*it)->getStatus() == FriendshipStatusEnum::FRIENDS
        ) {
            friends.push_back(getPersonById((*it)->getSecondPersonId()));
            continue;
        }

        if (
            (*it)->getSecondPersonId() == this->person->getId() &&
            (*it)->getStatus() == FriendshipStatusEnum::FRIENDS
        ) {
            friends.push_back(getPersonById((*it)->getFirstPersonId()));
            continue;
        }
    }

    return friends;
}

std::vector<Person*> PersonController::getFriendRequests() const {
    const std::vector<Friendship*> *friendships{this->db->getFriendships()};

    std::vector<Person*> friends;

    std::vector<Friendship*>::const_iterator it{friendships->begin()};

    for (; it != friendships->end(); ++it)
        if (
            (*it)->getSecondPersonId() == this->person->getId() &&
            (*it)->getStatus() == FriendshipStatusEnum::REQUEST_SENT
        )
            friends.push_back(getPersonById((*it)->getFirstPersonId()));

    return friends;
}

bool PersonController::sendFriendship(Person *const receiver) {
    Friendship *friendship{
        new Friendship{this->person->getId(), receiver->getId()}};

    this->db->addFriendship(friendship);

    return true;
}

bool PersonController::acceptFriendship(Person *const sender) {
    const std::vector<Friendship*> *friendships{this->db->getFriendships()};

    std::vector<Friendship*>::const_iterator it{friendships->begin()};

    for (; it != friendships->end(); ++it)
        if (
            (*it)->getSecondPersonId() == this->person->getId() &&
            (*it)->getFirstPersonId() == sender->getId() &&
            (*it)->getStatus() == FriendshipStatusEnum::REQUEST_SENT
        ) {
            (*it)->setStatus(FriendshipStatusEnum::FRIENDS);
            return true;
        }

    return false;
}

bool PersonController::declineFriendship(Person *const sender) {
    const std::vector<Friendship*> *friendships{this->db->getFriendships()};

    std::vector<Friendship*>::const_iterator it{friendships->begin()};

    for (; it != friendships->end(); ++it)
        if (
            (*it)->getSecondPersonId() == this->person->getId() &&
            (*it)->getFirstPersonId() == sender->getId() &&
            (*it)->getStatus() == FriendshipStatusEnum::REQUEST_SENT
        ) {
            (*it)->setStatus(FriendshipStatusEnum::REQUEST_DENIED);
            return true;
        }

    return false;
}

bool PersonController::unfriend(Person *const person) {
    const std::vector<Friendship*> *friendships{this->db->getFriendships()};

    std::vector<Friendship*>::const_iterator it{friendships->begin()};

    for (; it != friendships->end(); ++it) {
        if (
            (*it)->getFirstPersonId() == this->person->getId() &&
            (*it)->getSecondPersonId() == person->getId() &&
            (*it)->getStatus() == FriendshipStatusEnum::FRIENDS
        ) {
            (*it)->setStatus(FriendshipStatusEnum::REMOVED);
            return true;
        }

        if (
            (*it)->getSecondPersonId() == this->person->getId() &&
            (*it)->getFirstPersonId() == person->getId() &&
            (*it)->getStatus() == FriendshipStatusEnum::FRIENDS
        ) {
            (*it)->setStatus(FriendshipStatusEnum::REMOVED);
            return true;
        }
    }

    return false;
}

bool PersonController::inviteFriend(Person *const person, Event *const event) {
    Invite *invite{
        new Invite{this->person->getId(), person->getId(), event}
    };

    this->db->addInvite(invite);

    return true;
}

bool PersonController::followPlace(Place *const place) {
    Follow *follow{
        new Follow{this->person->getId(), place->getId()}
    };

    this->db->addFollow(follow);

    return true;
}

