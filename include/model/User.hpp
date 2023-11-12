#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>

#include "Address.hpp"


namespace places {

class User {
    public:
        User();

        User(
            const std::string &email,
            const std::string &password,
            const std::string &phoneNumber,
            const std::string &name,
            const Address &address
        );

        virtual ~User() = default;

        std::string getEmail() const;
        void setEmail(const std::string &email);

        std::string getPassword() const;
        void setPassword(const std::string &password);

        std::string getPhoneNumber() const;
        void setPhoneNumber(const std::string &phoneNumber);

        std::string getName() const;
        void setName(const std::string &name);

        Address getAddress() const;
        void setAddress(const Address &address);

        boost::posix_time::ptime getCreationDate() const;

    private:
        std::string email;
        std::string password;
        std::string phoneNumber;
        std::string name;

        Address address;

        boost::posix_time::ptime creationDate;
};

}

#endif
