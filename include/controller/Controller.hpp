#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "../model/Database.hpp"


namespace places {

class Controller {
    public:
        Controller();

        virtual ~Controller() = default;

    protected:
        Database *db;
};

} // namespace places

#endif
