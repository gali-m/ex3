#ifndef EVENT_CONTAINER_H
#define EVENT_CONTAINER_H

#include <iostream>
#include "../partA/exceptions.h"
#include "base_event.h"
#include "open_event.h"
#include "closed_event.h"
#include "custom_event.h"

namespace mtm 
{
    /**
    * EventNode: a structure which implements a list of pointers to BaseEvents.
    * contains a constructor that gets a BaseEvent and the next node, a copy constructor and a destructor.
    */
    struct EventNode
    {
        BaseEvent* event;
        EventNode* next;

        EventNode(BaseEvent* event = NULL, EventNode* next = NULL);
        explicit EventNode(const EventNode& event_node);
        ~EventNode();
    };


    class EventContainer
    {
    public:

        /**
        * EventIterator: a class for the iterator of the EventContainer.
        * contains a constructor that gets a pointer to an EventNode, a copy constructor, a destructor 
        * and operators as defined in the instructions.
        */
        class EventIterator
        {
            EventNode* iterator;

        public:

            EventIterator(EventNode* event);
            EventIterator(const EventIterator& event_iterator);
            ~EventIterator();
	        EventIterator& operator=(const EventIterator& event_iterator);
            EventIterator& operator++();
            BaseEvent& operator*();
            bool operator==(const EventIterator& event_iterator);
            bool operator!=(const EventIterator& event_iterator);
        };

    protected:

        EventNode* event_list;

        /**
        * getEventDate: a protected method for getting the date of an event.
        *
        * @param event - an event to get the date of.
        * @return
        * 	DateWrap the date of the event.
        */
        DateWrap getEventDate(const BaseEvent& event);

        /**
        * getEventName: a protected method for getting the name of an event.
        *
        * @param event - an event to get the name of.
        * @return
        * 	std::string the name of the event.
        */
        std::string getEventName(const BaseEvent& event);

    public:

        EventContainer();
        virtual ~EventContainer();

        virtual void add(const BaseEvent& event) = 0;
        virtual EventIterator begin() const;
        virtual EventIterator end() const;
    };

}
#endif //EVENT_CONTAINER_H