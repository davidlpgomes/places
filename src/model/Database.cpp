#include "../../include/model/Database.hpp"


using namespace places;

Database *Database::database{nullptr};

Database::Database():
    persons{new std::map<int, Person*>},
    companies{new std::map<int, Company*>},
    events{new std::map<int, Event*>},
    places{new std::map<int, Place*>},
    follows{new std::vector<Follow*>},
    friendships{new std::vector<Friendship*>},
    invites{new std::vector<Invite*>},
    intentions{new std::multiset<EventIntention>} {
}

Database *Database::getInstance() {
    if (Database::database == nullptr)
        Database::database = new Database{};

    return Database::database;
}

const std::map<int, Person*> *Database::getPersons() const {
    return this->persons;
}

void Database::addPerson(Person *const person) {
    this->persons->insert(
        std::pair<int, Person*>(person->getId(), person)
    );

    return;
}

const std::map<int, Company*> *Database::getCompanies() const {
    return this->companies;
}

void Database::addCompany(Company *const company) {
    this->companies->insert(
        std::pair<int, Company*>(company->getId(), company)
    );

    return;
}

const std::map<int, Event*> *Database::getEvents() const {
    return this->events;
}

void Database::addEvent(Event *const event) {
    this->events->insert(
        std::pair<int, Event*>(event->getId(), event)
    );

    return;
}

const std::map<int, Place*> *Database::getPlaces() const {
    return this->places;
}

void Database::addPlace(Place *const place) {
    this->places->insert(
        std::pair<int, Place*>(place->getId(), place)
    );

    return;
}

const std::vector<Follow*> *Database::getFollows() const {
    return this->follows;
}

void Database::addFollow(Follow *const follow) {
    this->follows->push_back(follow);
    
    return;
}

const std::vector<Friendship*> *Database::getFriendships() const {
    return this->friendships;
}

void Database::addFriendship(Friendship *const friendship) {
    this->friendships->push_back(friendship);

    return;
}

const std::vector<Invite*> *Database::getInvites() const {
    return this->invites;
}

void Database::addInvite(Invite *const invite) {
    this->invites->push_back(invite);

    return;
}

const std::multiset<EventIntention> *Database::getEventIntetions() const {
    return this->intentions;
}

void Database::addEventIntetion(const EventIntention &intention) {
    this->intentions->insert(intention);

    return;
}

