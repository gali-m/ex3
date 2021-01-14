#ifndef ONE_TIME_EVENT_H
#define ONE_TIME_EVENT_H
#include "event_container.h"

namespace mtm 
{
    template <class EventType>
    class OneTimeEvent : public EventContainer
    {
    public:
        OneTimeEvent(DateWrap event_date, std::string event_name);
        void add(BaseEvent& event);
    };

}


#endif //ONE_TIME__EVENT