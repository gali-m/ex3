#ifndef BASE_EVENT_H
#define BASE_EVENT_H

#include <iostream>
#include "date_wrap.h"
#include "exceptions.h"

namespace mtm {
    
    const int MAX_STUDENT_ID = 1234567890;
    const int MIN_STUDENT_ID = 1;

    struct StudentNode
    {
        int student_id;
        StudentNode* next;

        StudentNode(int student_id, StudentNode* next = NULL);
        ~StudentNode();
        StudentNode(const StudentNode& student_node);
        // StudentNode& operator+=(StudentNode* student);

        friend class BaseEvent;
    };

    class BaseEvent{
        DateWrap date;
        std::string name;
        StudentNode* students_list;
    
    public:
        BaseEvent(DateWrap date, std::string name);
        virtual ~BaseEvent();
        // BaseEvent(const BaseEvent&);

        virtual void registerParticipant(StudentNode* student) = 0;
        virtual void unregisterParticipant(StudentNode* student);
        virtual std::ostream& printShort(std::ostream& os);
        virtual std::ostream& printLong(std::ostream& os);
        virtual BaseEvent* clone() = 0;

        friend class EventContainer;

    protected:
        bool is_valid_student(StudentNode* student);
        bool is_student_in_list(StudentNode* students_list, StudentNode* student);
        void add_to_students_list(StudentNode* students_list, StudentNode* student);
    };

}


#endif //BASE_EVENT_H