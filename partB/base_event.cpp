#include <iostream>
#include "base_event.h"
#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"

namespace mtm {

    // StudentNode constructor:

    StudentNode::StudentNode(int student_id, StudentNode* next) : student_id(student_id), next(next) {}  

    // BaseEvent methods:

    BaseEvent::BaseEvent(DateWrap date, std::string name) : date(date), name(name), students_list(NULL) {}

    BaseEvent::BaseEvent(const BaseEvent& base_event) : date(base_event.date), name(base_event.name) 
    {
        this->students_list = copyStudentsList(base_event.students_list);
    }

    StudentNode* BaseEvent::copyStudentsList(StudentNode* students_list)
    {
        StudentNode* new_students_list = NULL;

        // students list is not empty
        if(students_list != NULL)
        {
            // copy each node from students_list to new node in new_students_list
            StudentNode* base_event_current = students_list;
            new_students_list = new StudentNode(base_event_current->student_id, NULL);
            StudentNode* this_current = new_students_list;

            base_event_current = base_event_current->next;

            while (base_event_current != NULL)
            {
                this_current->next = new StudentNode(base_event_current->student_id, NULL);
                base_event_current = base_event_current->next;
                this_current = this_current->next;
            }
        }
        return new_students_list;
    }

    BaseEvent::~BaseEvent() 
    {
        StudentNode* current = this->students_list;
        StudentNode* next;

        // distroy each node in the students list
        while (current != NULL) 
        {
            next = current->next;
            delete current;
            current = next;
        }
    }

    bool BaseEvent::isStudentInList(StudentNode* students_list, int student_id)
    {
        while (students_list != NULL)
        {
            if (students_list->student_id == student_id)
            {
                return true;
            }
            students_list = students_list->next;
        }

        return false;
    }

    bool BaseEvent::isValidStudent(int student_id)
    {
        if (student_id > MAX_STUDENT_ID || student_id < MIN_STUDENT_ID)
        {
            throw InvalidStudent();
            return false;
        }
        return true;
    }

    void BaseEvent::registerParticipant(int student_id)
    {
        isValidStudent(student_id);

        bool is_student_in_list_return = isStudentInList(this->students_list, student_id);
        if (is_student_in_list_return)
        {
            throw AlreadyRegistered();
        }

        if(this->students_list == NULL)
        { // if list is empty
            this->students_list = new StudentNode(student_id, NULL);
        }
        else if(this->students_list->student_id > student_id)
        { // the first student is bigger
            this->students_list = new StudentNode(student_id, this->students_list);
        }
        else
        {
            addToStudentsList(this->students_list, student_id);
        }
    }

    void BaseEvent::unregisterParticipant(int student_id)
    {
        isValidStudent(student_id);

        StudentNode* current_student = this->students_list;
        StudentNode* before_current = NULL;

        while (current_student != NULL)
        {
            if (current_student->student_id == student_id)
            {
                StudentNode* node_to_remove = current_student;

                if(before_current == NULL)
                { // remove first node
                    this->students_list = current_student->next;
                }
                else
                {
                    before_current->next = current_student->next;
                }

                node_to_remove->next = NULL;
                delete node_to_remove;
                return;
            }
            before_current = current_student;
            current_student = current_student->next;
        }

        throw NotRegistered();
    }

    void BaseEvent::printShort(std::ostream &output)
    {
        output << this->name << " " << this->date << "\n";
    }


    void BaseEvent::printLong(std::ostream &output)
    {
        this->printShort(output);

        StudentNode* current_student = this->students_list;

        while (current_student != NULL)
        {
            output << current_student->student_id << "\n";
            current_student = current_student->next;
        }
    }

    void BaseEvent::addToStudentsList(StudentNode* students_list, int student_id)
    {
        // the list id empty - add first node
        if(students_list == NULL)
        {
            students_list = new StudentNode(student_id, NULL);
            return;
        }

        StudentNode* current = students_list;
        StudentNode* before_current = NULL;

        // find the right place and add
        while (current->student_id < student_id) {
            if (current->next == NULL)
            {
                current->next = new StudentNode(student_id, NULL);
                return;
            }
            before_current = current;
            current = current->next;
        }

        // add to first node
        if(before_current == NULL)
        {
            students_list = new StudentNode(student_id, current);
            return;
        }

        // add to last node
        before_current->next = new StudentNode(student_id, (*before_current).next);
    }

}