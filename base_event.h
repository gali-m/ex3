#ifndef BASE_EVENT_H
#define BASE_EVENT_H

#include <iostream>
#include "date_wrap.h"
#include "exceptions.h"

namespace mtm {

    struct student_node
    {
        int student_id;
        student_node* next;

        student_node(int student_id, student_node* next = NULL);
        ~student_node();

        friend class BaseEvent;
    };

    class BaseEvent{
        DateWrap date;
        std::string name;
        student_node* students_list;
    
    public:
        BaseEvent(DateWrap date, std::string name);
        ~BaseEvent();

        virtual void registerParticipant(student_node* student) = 0;
        virtual void unregisterParticipant(student_node* student);
        virtual std::ostream printShort(std::ostream);
        virtual std::ostream printLong(std::ostream);
        virtual void clone();

    private:
        bool is_valid_student(student_node* student);
        bool is_student_in_list(student_node* students_list, student_node* student);
    };

}


#endif //BASE_EVENT_H