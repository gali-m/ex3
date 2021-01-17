#include "festival.h"

namespace mtm
{
    Festival::Festival(DateWrap date): date(date) {}

    void Festival::add(const BaseEvent& event)
    {
        DateWrap event_date = getEventDate(event);
        if (event_date != this->date)
        {
            throw DateMismatch();
        }

        event_node* event_to_add = new event_node();
        (*event_to_add).event = event.clone();

        event_node* curr_node = this->event_list;
        event_node* next_node = this->event_list;

        if (this->event_list->event == NULL || getEventName(*(curr_node->event)) >= getEventName(event))
        { // first event
            (*event_to_add).next = this->event_list;
            this->event_list = event_to_add;
            return;
        }

        next_node = next_node->next;

        while (next_node->event != NULL)
        { // insert by event name
            if (getEventName(*(next_node->event)) >= getEventName(event))
            { 
                (*event_to_add).next = next_node;
                curr_node->next = event_to_add;
                return;
            }
            curr_node = curr_node->next;
            next_node = next_node->next;
        }

        // last event
        (*event_to_add).next = next_node;
        curr_node->next = event_to_add;
    }
}