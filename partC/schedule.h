#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <iostream>
#include "../partA/exceptions.h"
#include "../partA/date_wrap.h"
#include "../partB/base_event.h"
#include "../partB/open_event.h"
#include "../partB/closed_event.h"
#include "../partB/custom_event.h"
#include "../partB/event_container.h"
#include <list>

namespace mtm 
{
    const std::string NEW_LINE = "\n";
    
    class Schedule
    {
        std::list<BaseEvent*> scheduler;

        /**
        * containsEvents: a private method for checking whether events are already in the scheduler or not.
        *
        * @param event_container - an event conatainer with events we wish to insert to the scheduler.
        * @return
        * 	true if at least one of the events in the event container is already in the scheduler (event name + date).
        *   false otherwise.
        */
        bool containsEvents(const EventContainer& event_container) const;

    public:

        Schedule();
        ~Schedule();

        void addEvents(const EventContainer& event_container);
        void registerToEvent(DateWrap date, std::string event_name, int student_id);
        void unregisterFromEvent(DateWrap date, std::string event_name, int student_id);
        void printAllEvents() const;
        void printMonthEvents(int month, int year) const;

        template <class Predicate>
        void printSomeEvents(Predicate predicate_function , bool verbose = false) const
        {
            for (BaseEvent* event : scheduler)
            {
                if(predicate_function(*event))
                {// print this event according to verbose value
                    if (verbose)
                    {
                        event->printLong(std::cout);
                    }
                    else
                    {
                        event->printShort(std::cout);
                    }

                    std::cout << NEW_LINE;
                }
            }
        }

        void printEventDetails(DateWrap date, std::string event_name) const;
    };

}
#endif //SCHEDULE_H