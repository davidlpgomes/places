#ifndef PERSON_HPP
#define PERSON_HPP

#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>

#include "User.hpp"


namespace places {

class Person : public User {
    public:
        Person();

        Person(
            const std::string &userName,
            unsigned int cpf,
            const boost::posix_time::ptime &birthDate,
            const std::string &email,
            const std::string &password,
            const std::string &phoneNumber,
            const std::string &name,
            const Address &address
        );

        virtual ~Person() = default;

        const std::string &getUserName() const;
        void setUserName(const std::string &userName);

        unsigned int getCpf();
        void setCpf(unsigned int cpf);

        const boost::posix_time::ptime &getBirthDate() const;
        void setBirthDate(const boost::posix_time::ptime &birthDate);

    private:
        std::string userName;
        unsigned int cpf;
        boost::posix_time::ptime birthDate;
};

} // namespace places

#endif
