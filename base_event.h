#ifndef BASE_EVENT_H
#define BASE_EVENT_H

#include <iostream>
#include "date_wrap.h"
#include "exceptions.h"

namespace mtm {

    struct event_node
    {
        DateWrap date;
        std::string name;
        student_node* students_list;
    };

    struct student_node
    {
        int student_id;
        student_node* next;
    };

    class BaseEvent{
        event_node event;
    
    public:
        BaseEvent(DateWrap date, std::string name);

        virtual event_node registerParticipant(student_node* student);
        virtual event_node unregisterParticipant(student_node* student);
        virtual std::ostream printShort(std::ostream);
        virtual std::ostream printLong(std::ostream);
        virtual event_node* clone();

        // TODO: one function that pure virtual "=0" for abstract class
        virtual event_node* make_it_abstract() = 0;

    }

}


#endif //BASE_EVENT_H