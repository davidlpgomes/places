#ifndef USER_HPP
#define USER_HPP

#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>

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

        unsigned int getId();

        const std::string &getEmail() const;
        void setEmail(const std::string &email);

        const std::string &getPassword() const;
        void setPassword(const std::string &password);

        const std::string &getPhoneNumber() const;
        void setPhoneNumber(const std::string &phoneNumber);

        const std::string &getName() const;
        void setName(const std::string &name);

        const Address &getAddress() const;
        void setAddress(const Address &address);

        const boost::posix_time::ptime &getCreationDate() const;

    private:
        static unsigned int nextId;
        unsigned int id;

        std::string email;
        std::string password;
        std::string phoneNumber;
        std::string name;

        Address address;

        boost::posix_time::ptime creationDate;
};

} // namespace places

#endif
