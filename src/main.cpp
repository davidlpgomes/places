#include <iostream>

#include "../include/model/User.hpp"
#include "../include/model/Address.hpp"


int main() {
    std::cout << "Hello, places!" << std::endl;

    places::Address address;
    places::User user{"email", "pass", "phone", "name", address};

    std::cout << user.getCreationDate() << std::endl;

    return 0;
}
