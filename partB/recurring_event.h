#ifndef RECURRING_EVENT_H
#define RECURRING_EVENT_H
#include "event_container.h"

namespace mtm 
{
    template <class EventType>
    class RecurringEvent : public EventContainer
    {
    public:
        RecurringEvent(const DateWrap first_date, std::string event_name, int num_occurrences, int interval_days)
        {
            if (num_occurrences <= 0)
            {
                throw InvalidNumber();
            }
            if (interval_days <= 0)
            {
                throw InvalidInterval();
            }

            DateWrap date = DateWrap(first_date);
            std::string name = event_name;
            EventNode* curr_event_node = this->event_list;
            EventNode* last_node = this->event_list;

            for( int i = 0; i < num_occurrences; i++)
            {// add the events
                BaseEvent* event = new EventType(date, name);
                EventNode* node = new EventNode(event);

                if (i == 0)
                {// first event
                    node->next = curr_event_node;
                    this->event_list = node;
                }
                else
                {
                    node->next = last_node;
                    curr_event_node->next = node;
                }

                date += interval_days;
                curr_event_node = node;
            }
        }
        
        void add(const BaseEvent& event) override
        {// no insertion allowed
            throw NotSupported();
        }
    };
}


#endif //RECURRING_EVENT_H