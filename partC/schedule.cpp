#include "schedule.h"
#include <string.h>
#include <memory>

namespace mtm 
{
    const int EQUAL = 0;
    
    Schedule::Schedule() : scheduler() {}

    Schedule::~Schedule()
    {
        while (!this->scheduler.empty())
        { // destroy the BaseEvents in the list
            BaseEvent* event = this->scheduler.front();
            this->scheduler.pop_front();
            delete event;
        }
    }

    bool Schedule::containsEvents(const EventContainer& event_container) const
    {
        for (BaseEvent& event_iterator : event_container)
        {
            for (BaseEvent* event : this->scheduler)
            {
                if (event->date == event_iterator.date && event_iterator.name.compare(event->name) == EQUAL)
                {
                    return true;
                }
            }
        }
        return false;
    }

    void Schedule::addEvents(const EventContainer& event_container)
    {
        if (event_container.begin() == event_container.end())
        { // no events to add
            return;
        }

        if (this->containsEvents(event_container))
        { // the scheduler already contains one or more of the events
            throw EventAlreadyExists();
        }

        //add the events to the scheduler
        BaseEvent* event_to_add;
        bool inserted = false;

        for (BaseEvent& event_iterator : event_container)
        {
            inserted = false;

            if (this->scheduler.empty())
            { // first event in scheduler
                event_to_add = event_iterator.clone();
                this->scheduler.push_front(event_to_add);
                inserted = true;
            }

            else 
            {
                for (std::list<BaseEvent*>::iterator it = this->scheduler.begin(); it != this->scheduler.end(); ++it)
                {
                    if (!inserted && ((*it)->date > event_iterator.date || 
                        ((*it)->date == event_iterator.date && (*it)->name.compare(event_iterator.name) > EQUAL)))
                    { // insert by event date & name
                        event_to_add = event_iterator.clone();
                        this->scheduler.insert(it,event_to_add);
                        inserted = true;
                    }
                }
                
                if (!inserted)
                {// last event
                    event_to_add = event_iterator.clone();
                    this->scheduler.push_back(event_to_add);
                }
            }
        }
    }

    void Schedule::registerToEvent(DateWrap date, std::string event_name, int student_id)
    {
        for (BaseEvent* event : this->scheduler)
        {
            if (event->date == date && event_name.compare(event->name) == EQUAL)
            {// the event to register to
                event->registerParticipant(student_id);
                return;
            }
        }

        // no such event found
        throw EventDoesNotExist();
    }

    void Schedule::unregisterFromEvent(DateWrap date, std::string event_name, int student_id)
    {
        for (BaseEvent* event : scheduler)
        {
            if (event->date == date && event_name.compare(event->name) == EQUAL)
            {// the event to unregister from
                event->unregisterParticipant(student_id);
                return;
            }
        }
        // no such event found
        throw EventDoesNotExist();
    }

    void Schedule::printAllEvents() const
    {
        for (BaseEvent* event : scheduler)
        {
            event->printShort(std::cout);
            std::cout << NEW_LINE;
        }
    }

    void Schedule::printMonthEvents(int month, int year) const
    {
        for (BaseEvent* event : scheduler)
        {
            if(event->date.month() == month && event->date.year() == year)
            {// the event occurs in the month required
                event->printShort(std::cout);
                std::cout << NEW_LINE;
            }
        }
    }

    void Schedule::printEventDetails(DateWrap date, std::string event_name) const
    {
        for (BaseEvent* event : scheduler)
        {
            if(event->date == date && event_name.compare(event->name) == EQUAL)
            {// the event to print
                event->printLong(std::cout);
                std::cout << NEW_LINE;
            }
        }
    }

}