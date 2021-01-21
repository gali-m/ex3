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
        // ~StudentNode();
        // StudentNode(const StudentNode* student_node);
        // StudentNode* copy_students_list(StudentNode* new_students_list, const StudentNode* students_list);
        // StudentNode& operator+=(StudentNode* student);

        friend class BaseEvent;
    };

    // struct StudentList
    // {
    //     StudentNode* student;
    //     StudentList();
    //     StudentList(StudentNode* student);
    //     ~StudentList();
    // };

    class BaseEvent{
    protected:
        DateWrap date;
        std::string name;
        StudentNode* students_list;
    
    public:
        BaseEvent(DateWrap date, std::string name);
        BaseEvent(const BaseEvent& open_event);
        virtual ~BaseEvent();
        // BaseEvent(const BaseEvent&);

        std::string getName() const
        {
            return this->name;
        }
        DateWrap getDate() const
        {
            return this->date;
        }

        virtual void registerParticipant(int student_id);
        virtual void unregisterParticipant(int student_id);
        virtual void printShort(std::ostream &output);
        virtual void printLong(std::ostream &output);
        virtual BaseEvent* clone() const = 0;

        friend class EventContainer;
        friend class Schedule;

    protected:
        bool is_valid_student(int student_id);
        bool is_student_in_list(StudentNode* students_list, int student_id);
        void add_to_students_list(StudentNode* students_list, int student_id);
        StudentNode* copy_students_list(StudentNode* new_students_list, StudentNode* students_list);
    };

}


#endif //BASE_EVENT_H