#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "../model/Database.hpp"


namespace places {

class Controller {
    public:
        Controller();

        virtual ~Controller() = default;

    private:
        Database *db;
};

} // namespace places

#endif
