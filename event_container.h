#ifndef EVENT_CONTAINER_H
#define EVENT_CONTAINER_H

#include <iostream>
#include "exceptions.h"
#include "base_event.h"

namespace mtm {

    struct event_node
    {
        BaseEvent* event;
        event_node* next;

        event_node(BaseEvent* event = NULL, event_node* next = NULL);
        event_node(const event_node& event_node);

        friend class EventIterator;
        friend class EventContainer;
    };


    class EventContainer
    {
        event_node* event_list;

    public:

        class EventIterator
        {
            event_node* iterator;

        public:

            EventIterator(event_node* event);
            EventIterator(const EventIterator& event_iterator);
	        EventIterator& operator=(const EventIterator& event_iterator);
            EventIterator& operator++();
            BaseEvent& operator*();
            bool operator==(const EventIterator& event_iterator);
            bool operator!=(const EventIterator& event_iterator);

            friend class EventContainer;
        };

        EventContainer();
        virtual ~EventContainer();

        virtual void add(BaseEvent& event) = 0;
        virtual EventIterator begin();
        virtual EventIterator end();
    };

}


#endif //BASE_EVENT_H