#ifndef FESTIVAL_H
#define FESTIVAL_H
#include "event_container.h"

namespace mtm 
{
    class Festival : public EventContainer
    {
        DateWrap date;

    public:
        Festival(const DateWrap date);
        void add(const BaseEvent& event) override;
    };

}


#endif //FESTIVAL_H