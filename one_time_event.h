#ifndef ONE_TIME_EVENT_H
#define ONE_TIME_EVENT_H
#include "event_container.h"

namespace mtm 
{
    template <class EventType>
    class OneTimeEvent : public EventContainer
    {
    public:
        OneTimeEvent(DateWrap event_date, std::string event_name)
        {
            DateWrap date = DateWrap(event_date);
            std::string name = event_name;
            BaseEvent* event = new EventType(date, name);

            event_node* node = new event_node();
            node->event = event;
            node->next = this->event_list;

            this->event_list = node;
        }

        void add(const BaseEvent& event) override
        {
            throw NotSupported();
        }
    };

    // template class OneTimeEvent<OpenEvent>;
    // template class OneTimeEvent<ClosedEvent>;
    // template class RecurringEvent<CustomEvent>;

}


#endif //ONE_TIME__EVENT