#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <iostream>
#include "exceptions.h"
#include "date_wrap.h"
#include "base_event.h"
#include "open_event.h"
#include "closed_event.h"
#include "custom_event.h"
#include "event_container.h"
#include <list>

namespace mtm 
{
    class Schedule
    {
        std::list<BaseEvent*> scheduler;

    public:

        Schedule();

        void addEvents(EventContainer& event_container);
        void registerToEvent(DateWrap date, std::string event_name, int student_id);
        void unregisterFromEvent(DateWrap date, std::string event_name, int student_id);
        void printAllEvents();
        void printMonthEvents(int month);

        template <class Predicate>
        void printSomeEvents(Predicate predicate_function , bool verbose = false)
        {

        }

        void printEventDetails(std::string event_name, DateWrap date);
    };

}
#endif //SCHEDULE_H