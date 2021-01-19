#include "schedule.h"
#include <string.h>

namespace mtm 
{
    
        Schedule::Schedule() : scheduler() {}

        void Schedule::addEvents(const EventContainer& event_container)
        {
            for (mtm::EventContainer::EventIterator event_iterator = event_container.begin(); event_iterator != event_container.end(); ++event_iterator)
            {
                for (BaseEvent* i : scheduler)
                {
                    if (i->date == event_iterator.iterator->event->date && event_iterator.iterator->event->name.compare(i->name) == 0)
                    {
                        throw EventAlreadyExists();
                    }
                }
            }

            //add to list

            for (mtm::EventContainer::EventIterator event_iterator = event_container.begin(); event_iterator != event_container.end(); ++event_iterator)
            {
                BaseEvent* event = (*event_iterator).clone();

                if (this->scheduler.empty())
                    { // first event
                        this->scheduler.push_front(event);
                        return;
                    }

                for (std::list<BaseEvent*>::iterator i = this->scheduler.begin(); i != this->scheduler.end(); ++i)
                {
                    if ((*i)->date > event->date || ((*i)->date == event->date && (*i)->name.compare(event->name) < 0))
                    { // insert by event date & name
                        this->scheduler.insert(i,event);
                        return;
                    }
                }
                // last event
                this->scheduler.push_back(event);
            }
        }

        void Schedule::registerToEvent(DateWrap date, std::string event_name, int student_id)
        {
            for (BaseEvent* i : scheduler)
            {
                if (i->date == date && event_name.compare(i->name) == 0)
                {
                    i->registerParticipant(student_id);
                    return;
                }
            }

            throw EventDoesNotExist();
        }

        void Schedule::unregisterFromEvent(DateWrap date, std::string event_name, int student_id)
        {
            for (BaseEvent* i : scheduler)
            {
                if (i->date == date && event_name.compare(i->name) == 0)
                {
                    i->unregisterParticipant(student_id);
                    return;
                }
            }

            throw EventDoesNotExist();
        }

        void Schedule::printAllEvents() const
        {
            for (BaseEvent* i : scheduler)
            {
                i->printShort(std::cout);
                std::cout << "/n";
            }
        }

        void Schedule::printMonthEvents(int month, int year) const
        {
            for (BaseEvent* i : scheduler)
            {
                if(i->date.month() == month && i->date.year() == year)
                {
                    i->printShort(std::cout);
                    std::cout << "/n";
                }
            }
        }

        void Schedule::printEventDetails(DateWrap date, std::string event_name) const
        {
            for (BaseEvent* i : scheduler)
                {
                    if(i->date == date && event_name.compare(i->name) == 0)
                    {
                        i->printLong(std::cout);
                        std::cout << "/n";
                    }
                }
        }

}