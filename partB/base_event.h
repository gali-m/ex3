#ifndef BASE_EVENT_H
#define BASE_EVENT_H

#include <iostream>
#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"

namespace mtm {
    
    const int MAX_STUDENT_ID = 1234567890;
    const int MIN_STUDENT_ID = 1;

    /**
    * StudentNode: a structure which implements a list of int that represent students.
    * contains a constructor that gets a int and the next node or put NULL in the next.
    */
    struct StudentNode
    {
        int student_id;
        StudentNode* next;

        StudentNode(int student_id, StudentNode* next = NULL);

        friend class BaseEvent;
    };



    class BaseEvent{
    protected:
        DateWrap date;
        std::string name;
        StudentNode* students_list;
    
    public:
        BaseEvent(DateWrap date, std::string name);
        BaseEvent(const BaseEvent& open_event);
        virtual ~BaseEvent();

        virtual void registerParticipant(int student_id);
        virtual void unregisterParticipant(int student_id);
        virtual void printShort(std::ostream &output);
        virtual void printLong(std::ostream &output);
        virtual BaseEvent* clone() const = 0;

        friend class EventContainer;
        friend class Schedule;

    protected:

        /**
        * isValidStudent: a protected method for check of the student is valid.
        *
        * @param student_id - int of the id of the student.
        * @return
        * 	true if valid.
        *   throw InvalidStudent exception if not valid.
        */
        bool isValidStudent(int student_id);

        /**
        * isStudentInList: a protected method for check if the student_id is in students_list.
        *
        * @param student_id - int of the id of the student.
        * @param student_list - list of StudentNode.
        * @return
        * 	true if in the list and false if not.
        */
        bool isStudentInList(StudentNode* students_list, int student_id);

        /**
        * addToStudentsList: a protected method for add student_id to students_list From the smallest to the largest.
        *                    create new node of the student to add.
        *
        * @param student_id - int of the id of the student.
        * @param student_list - list of StudentNode.
        */
        void addToStudentsList(StudentNode* students_list, int student_id);

        /**
        * copyStudentsList: a protected method for copy each node from students_list to new node in new students list.
        *
        * @param student_list - list of StudentNode to copy from.
        * @return
        * 	new list of students that copy from students_list.
        */
        StudentNode* copyStudentsList(StudentNode* students_list);
    };

}


#endif //BASE_EVENT_H