#include "schedule.h"
#include <string.h>

namespace mtm 
{
    
        Schedule::Schedule() : scheduler() {}

        void Schedule::addEvents(EventContainer& event_container)
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
                for (BaseEvent* i : scheduler)
                {
                    // if (i->date == event_iterator.iterator->event->date && event_iterator.iterator->event->name.compare(i->name) == 0)
                    // {
                    //     // add in place
                    // }
                }
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

        // void Schedule::printAllEvents();
        // void Schedule::printMonthEvents(int month);

        // void Schedule::printEventDetails(std::string event_name, DateWrap date);

}