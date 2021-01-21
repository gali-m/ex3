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
    class Schedule
    {
        std::list<BaseEvent*> scheduler;

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
            for (BaseEvent* i : scheduler)
            {
                if(predicate_function(*i))
                {
                    if (verbose)
                    {
                        i->printLong(std::cout);
                    }
                    else
                    {
                        i->printShort(std::cout);
                    }

                    std::cout << "\n";
                }
            }
        }

        void printEventDetails(DateWrap date, std::string event_name) const;
    };

}
#endif //SCHEDULE_H