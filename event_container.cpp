#include <iostream>
#include "event_container.h"

namespace mtm
{
    EventContainer::EventIterator::EventIterator(const EventIterator& event_iterator)
    {

    }
    EventContainer::EventIterator::~EventIterator();
    EventIterator& EventContainer::EventIterator::operator=(const EventIterator& event_iterator);
    EventIterator EventContainer::EventIterator::operator++();
    BaseEvent& EventContainer::EventIterator::operator*();
    bool EventContainer::EventIterator::operator==(const EventIterator& event_iterator);
    bool EventContainer::EventIterator::operator!=(const EventIterator& event_iterator);
}