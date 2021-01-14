#include <iostream>
#include "base_event.h"
#include "date_wrap.h"
#include "exceptions.h"

// const int MAX_STUDENT_ID = 1234567890;
// const int MIN_STUDENT_ID = 1;


namespace mtm {

    StudentNode::StudentNode(int student_id, StudentNode* next) : student_id(student_id), next(NULL) {}

    //TODO: fix studenNode copy
    StudentNode::StudentNode(const StudentNode& student_node) : student_id(student_node.student_id)
    {
        if (student_node.next == NULL)
        {
            this->next = NULL;
            return;
        }

        this->next = new StudentNode(student_node.next->student_id, student_node.next->next);
    }

    StudentNode::~StudentNode()
    {
        StudentNode* current = this;
        StudentNode* next;

        while (current != NULL) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    // StudentNode& StudentNode::operator+=(StudentNode* student)
    // {
    //     StudentNode* current = this;

    //     while (current != NULL) {
    //         current = current->next;
    //     }

    //     current->next = &StudentNode((*student).student_id, (*student).next);

    //     return *this;
    // }
    

    BaseEvent::BaseEvent(DateWrap date, std::string name) : date(date), name(name), students_list(NULL) {}

    // BaseEvent::~BaseEvent() {}


    bool BaseEvent::is_student_in_list(StudentNode* students_list, StudentNode* student)
    {
        while (students_list != NULL)
        {
            if (students_list->student_id == student->student_id)
            {
                return true;
            }
            students_list = students_list->next;
        }

        return false;
    }

    bool BaseEvent::is_valid_student(StudentNode* student)
    {
        if (student->student_id > MAX_STUDENT_ID && student->student_id < MIN_STUDENT_ID)
        {
            throw InvalidStudent();
            return false;
        }
        return true;
    }


    void BaseEvent::unregisterParticipant(StudentNode* student)
    {
        is_valid_student(student);

        StudentNode* current_student = this->students_list;

        while (current_student != NULL)
        {
            if (current_student->student_id == student->student_id)
            {
                StudentNode* node_to_remove = current_student;
                current_student = current_student->next;

                node_to_remove->next = NULL;
                delete node_to_remove;
                return;
            }
            current_student = current_student->next;
        }

        throw NotRegistered();
    }

    void BaseEvent::printShort()
    {
        std::cout << this->name << " " << this->date << "\n";
    }


    void BaseEvent::printLong()
    {
        this->printShort();

        StudentNode* current_student = this->students_list;

        while (current_student != NULL)
        {
            std::cout << this->students_list << "\n";
            current_student = current_student->next;
        }
    }

    void BaseEvent::add_to_students_list(StudentNode* students_list, StudentNode* student)
    {
        if(students_list == NULL)
        {
            students_list = new StudentNode((*student).student_id, NULL);
            return;
        }

        StudentNode* current = students_list;
        StudentNode* before_current = NULL;

        while (current->student_id < student->student_id) {
            if (current->next == NULL)
            {
                current->next = new StudentNode((*student).student_id, NULL);
                return;
            }
            before_current = current;
            current = current->next;
        }

        before_current->next = new StudentNode((*student).student_id, (*before_current).next);
    }

}