#ifndef RECURRING_EVENT_H
#define RECURRING_EVENT_H
#include "event_container.h"

namespace mtm 
{
    template <class EventType>
    class RecurringEvent : public EventContainer
    {
    public:
        RecurringEvent(const DateWrap first_date, const std::string event_name, const int num_occurrences, const int interval_days)
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
            event_node* last_node = this->event_list;

            for( int i = 0; i < num_occurrences; i++)
            {
                BaseEvent* event = new EventType(date, name);
                event_node* node = new event_node();
                node->event = event;

                if (i == 0)
                { // first event
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
        
        void add(BaseEvent& event) override
        {
            throw NotSupported();
        }
    };

    // template class RecurringEvent<OpenEvent>;
    // template class RecurringEvent<ClosedEvent>;
    // template class RecurringEvent<CustomEvent>;
}


#endif //RECURRING_EVENT