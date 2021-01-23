#include "festival.h"

namespace mtm
{
    Festival::Festival(const DateWrap date): date(date) {}

    void Festival::add(const BaseEvent& event)
    {
        DateWrap event_date = getEventDate(event);
        if (event_date != this->date)
        {// the event doesn't occur on the festival's day
            throw DateMismatch();
        }

        // add the event
        event_node* event_to_add = new event_node(event.clone());

        event_node* curr_node = this->event_list;
        
        if (this->event_list->event == NULL || getEventName(*(curr_node->event)) >= getEventName(event))
        { // insert as the first event
            event_to_add->next = this->event_list;
            this->event_list = event_to_add;
            return;
        }

        event_node* next_node = curr_node->next;

        while (next_node->event != NULL)
        { // insert by event name
            if (getEventName(*(next_node->event)) >= getEventName(event))
            { 
                event_to_add->next = next_node;
                curr_node->next = event_to_add;
                return;
            }
            curr_node = curr_node->next;
            next_node = next_node->next;
        }

        // last event
        event_to_add->next = next_node;
        curr_node->next = event_to_add;
    }
}