#include <iostream>
#include "event_container.h"

namespace mtm
{
    // event_node methods:

    // set event_node to be the same as the parameters given, not a copy
    event_node::event_node(BaseEvent* event, event_node* next): event(event), next(next) {}

    event_node::event_node(const event_node& event_node): event(event_node.event), next(event_node.next) {}

    event_node::~event_node()
    {
        delete event;
    }


    //EventIterator methods:

    EventContainer::EventIterator::EventIterator(event_node* event) : iterator(event) {}

    EventContainer::EventIterator::EventIterator(const EventIterator& event_iterator) : 
                                                                                iterator(event_iterator.iterator) {}

    EventContainer::EventIterator::~EventIterator()
    {// avoid double freeing - do not delete the event_node
        this->iterator = nullptr;
    }

    EventContainer::EventIterator& EventContainer::EventIterator::operator=(const EventIterator& event_iterator)
    {
        if (this == &event_iterator)
        {// no assignment needed
            return *this;
        }

        this->iterator = event_iterator.iterator;
        return *this;
    }

    EventContainer::EventIterator& EventContainer::EventIterator::operator++()
    {
        this->iterator = this->iterator->next;
        return *this;
    }
    BaseEvent& EventContainer::EventIterator::operator*()
    {
        return *(this->iterator->event);
    }
    bool EventContainer::EventIterator::operator==(const EventIterator& event_iterator)
    {
        return (this->iterator->event == event_iterator.iterator->event);
    }
    bool EventContainer::EventIterator::operator!=(const EventIterator& event_iterator)
    {
        return !(operator==(event_iterator));
    }


    //EventContainer methods:


    DateWrap EventContainer::getEventDate(const BaseEvent& event)
    {
        return event.date;
    }

    std::string EventContainer::getEventName(const BaseEvent& event)
    {
        return event.name;
    }

    EventContainer::EventContainer()
    {
        event_list = new event_node();
    }
    EventContainer::~EventContainer()
    {// delete the nodes in the container's list
        event_node* current = this->event_list;
        event_node* next;

        while (current != nullptr) 
        {
            next = current->next;
            delete current;
            current = next;
        }
    }

    EventContainer::EventIterator EventContainer::begin() const
    {
        return EventIterator(this->event_list);
    }
    
    EventContainer::EventIterator EventContainer::end() const
    {
        EventIterator event_iterator = this->begin();

        while (&(*event_iterator) != nullptr) 
        {// go to the last node in the container
            ++event_iterator;
        }
        
        return event_iterator;
    }
}