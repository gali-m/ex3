#include "one_time_event.h"

namespace mtm
{
    template <class EventType>
    OneTimeEvent::OneTimeEvent(DateWrap event_date, std::string event_name)
    {
        DateWrap date = DateWrap(event_date);
        std::string name = event_name;
        EventType event = EventType(date, name);

        event_node event_node();
        event_node->event = event;
        event_node->next = this->event_list;

        this->event_list = event_node;
    }

    template <class EventType>
    void OneTimeEvent::add(BaseEvent& event)
    {
        throw NotSupported();
    }
}