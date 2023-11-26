#ifndef PLACES_VIEW_HPP
#define PLACES_VIEW_HPP

#include <string>
#include "../../include/view/PlacesStatesEnum.hpp"
#include "../../include/model/User.hpp"
#include "../../include/model/Person.hpp"

#include "../../include/model/Company.hpp"

namespace places {


class PlacesView {
    public:
        PlacesView();

        PlacesView(
            unsigned int viewType,
            ViewsStatesEnum viewState
        );

        virtual ~PlacesView() = default;

        unsigned int getViewType();
        void setViewType(unsigned int viewType);
        
        ViewsStatesEnum getViewState();
        void setViewState(ViewsStatesEnum viewState);

        void getInitialPage();
        void getUserInitialPage(Person *person);
        void getCompanyInitialPage(Company *company);


    private:
        unsigned int viewType;
        ViewsStatesEnum viewState;

};

}

#endif
