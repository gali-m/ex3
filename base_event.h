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
    protected:
        DateWrap date;
        std::string name;
        StudentNode* students_list;
    
    public:
        BaseEvent(DateWrap date, std::string name);
        virtual ~BaseEvent() = default;
        // BaseEvent(const BaseEvent&);

        virtual void registerParticipant(int student_id);
        virtual void unregisterParticipant(int student_id);
        virtual void printShort(std::ostream &output);
        virtual void printLong(std::ostream &output);
        virtual BaseEvent* clone() const = 0;

        friend class EventContainer;

    protected:
        bool is_valid_student(int student_id);
        bool is_student_in_list(StudentNode* students_list, int student_id);
        void add_to_students_list(StudentNode* students_list, int student_id);
    };

}


#endif //BASE_EVENT_H