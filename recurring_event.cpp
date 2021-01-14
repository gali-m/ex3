#include "recurring_event.h"

namespace mtm
{
    template <class EventType>
    RecurringEvent<EventType>::RecurringEvent(DateWrap first_date, std::string event_name, int num_occurrences, int interval_days)
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
        event_node* curr_event_node = this->event_list;
        event_node* next_event_node = this->event_list;

        for( int i = 0; i < num_occurrences; i++)
        {
            EventType event = EventType(date, name);
            event_node event_node();
            event_node->event = event;

            if (i == 0)
            { // first event
                event_node->next = curr_event_node;
                this->event_list = event_node;
                next_event_node = next_event_node->next;
            }
            else
            {
                event_node->next = next_event_node;
                curr_event_node->next = event_node;
            }
            
            date += interval_days;
            curr_event_node = curr_event_node->next;
            next_event_node = next_event_node->next;
        }
    }

    template <class EventType>
    void RecurringEvent<EventType>::add(const BaseEvent& event)
    {
        throw NotSupported();
    }
}