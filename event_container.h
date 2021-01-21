#ifndef EVENT_CONTAINER_H
#define EVENT_CONTAINER_H

#include <iostream>
#include "exceptions.h"
#include "base_event.h"
#include "open_event.h"
#include "closed_event.h"
#include "custom_event.h"

namespace mtm 
{
    struct event_node
    {
        BaseEvent* event;
        event_node* next;

        event_node(BaseEvent* event = NULL, event_node* next = NULL);
        ~event_node();
        // event_node(const event_node& event_node);

    };


    class EventContainer
    {
    public:

        class EventIterator
        {
            event_node* iterator;

        public:

            EventIterator(event_node* event);
            EventIterator(const EventIterator& event_iterator);
            ~EventIterator();
	        EventIterator& operator=(const EventIterator& event_iterator);
            EventIterator& operator++();
            BaseEvent& operator*();
            bool operator==(const EventIterator& event_iterator);
            bool operator!=(const EventIterator& event_iterator);

            friend class EventContainer;
            friend class Schedule;
        };

    protected:

        event_node* event_list;
        DateWrap getEventDate(const BaseEvent& event);
        std::string getEventName(const BaseEvent& event);
        // event_node* getIteratorEventnode(EventIterator event_iterator);

    public:

        EventContainer();
        virtual ~EventContainer();

        virtual void add(const BaseEvent& event) = 0;
        virtual EventIterator begin() const;
        virtual EventIterator end() const;
    };

}
#endif //BASE_EVENT_H