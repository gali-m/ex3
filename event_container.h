#ifndef EVENT_CONTAINER_H
#define EVENT_CONTAINER_H

#include <iostream>
#include "exceptions.h"
#include "base_event.h"

namespace mtm {

    struct event_node
    {
        BaseEvent& event;
        event_node* next;

        event_node(BaseEvent& event, event_node* next = NULL);
        ~event_node();

        friend class EventContainer;
    };


    class EventContainer
    {
        class EventIterator
        {
            event_node* iterator;

            EventIterator(const EventIterator& event_iterator);
            ~EventIterator();
	        EventIterator& operator=(const EventIterator& event_iterator);
            EventIterator operator++();
            BaseEvent& operator*();
            bool operator==(const EventIterator& event_iterator);
            bool operator!=(const EventIterator& event_iterator);
        };

        event_node* event_list;

    public:
        EventContainer();
        ~EventContainer();

        virtual void add(BaseEvent& event) = 0;
        virtual EventIterator begin();
        virtual EventIterator end();
    };

}


#endif //BASE_EVENT_H