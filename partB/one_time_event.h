#ifndef ONE_TIME_EVENT_H
#define ONE_TIME_EVENT_H
#include "event_container.h"

namespace mtm 
{
    template <class EventType>
    class OneTimeEvent : public EventContainer
    {
    public:
        OneTimeEvent(const DateWrap event_date, std::string event_name)
        {
            DateWrap date = DateWrap(event_date);
            std::string name = event_name;
            BaseEvent* event = new EventType(date, name);

            // add the event to the container
            EventNode* node = new EventNode(event, this->event_list);
            this->event_list = node;
        }

        void add(const BaseEvent& event) override
        {// no insertion allowed
            throw NotSupported();
        }
    };
}


#endif //ONE_TIME__EVENT_H