#ifndef RECURRING_EVENT_H
#define RECURRING_EVENT_H
#include "event_container.h"

namespace mtm 
{
    template <class EventType>
    class RecurringEvent : public EventContainer
    {
    public:
        RecurringEvent(DateWrap first_date, std::string event_name, int num_occurrences, int interval_days);
        void add(const BaseEvent& event);
    };
}


#endif //RECURRING_EVENT