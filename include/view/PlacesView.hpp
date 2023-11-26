#ifndef PLACES_VIEW_HPP
#define PLACES_VIEW_HPP

#include <string>
#include "../../include/view/PlacesStatesEnum.hpp"

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

    private:
        unsigned int viewType;
        ViewsStatesEnum viewState;

};

}

#endif
