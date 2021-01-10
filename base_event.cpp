#include <iostream>
#include "base_event.h"
#include "date_wrap.h"
#include "exceptions.h"

const int MAX_STUDENT_ID = 1234567890;
const int MIN_STUDENT_ID = 1;


namespace mtm {

    student_node::student_node(int student_id, student_node* next = NULL) : 
    student_id(student_id), next(next) {}

    student_node::~student_node()
    {
        student_node* current = this;
        student_node* next;

        while (current != NULL) {
            next = current->next;
            delete current;
            current = next;
        }
    }
    

    BaseEvent::BaseEvent(DateWrap date, std::string name) : date(date), name(name) 
    {
        students_list = NULL;
    }


    // bool is_student_in_list(student_node* students_list, student_node* student)
    // {
    //     while (students_list != NULL)
    //     {
    //         if (students_list->student_id == student->student_id)
    //         {
    //             return true;
    //         }
    //         students_list = students_list->next;
    //     }

    //     return false;
    // }

    bool is_valid_student(student_node* student)
    {
        if (student->student_id > MAX_STUDENT_ID && student->student_id < MIN_STUDENT_ID)
        {
            throw InvalidStudent();
            return false;
        }
        return true;
    }


    void BaseEvent::unregisterParticipant(student_node* student)
    {
        is_valid_student(student);

        student_node* current_student = this->students_list;

        while (current_student != NULL)
        {
            if (current_student->student_id == student->student_id)
            {
                student_node* node_to_remove = current_student;
                current_student = current_student->next;

                node_to_remove->next = NULL;
                delete node_to_remove;
                return;
            }
            current_student = current_student->next;
        }

        throw NotRegistered();
    }


    std::ostream& BaseEvent::printShort(std::ostream& os)
    {
        return os << this->name << " " << this->date << "\n";
    }


    std::ostream& BaseEvent::printLong(std::ostream& os)
    {
        os << this->printShort(os);

        student_node* current_student = this->students_list;

        while (current_student != NULL)
        {
            os << this->students_list << "\n";
            current_student = current_student->next;
        }

        return os;
        
    }

    // create copy constructor

    // BaseEvent* BaseEvent::clone()
    // {
        
    // }

}