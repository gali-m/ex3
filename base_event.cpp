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
    


    BaseEvent::BaseEvent(DateWrap date, std::string name)
    {

    }


    bool is_student_in_list(student_node* students_list, student_node* student)
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

    bool is_valid_student(student_node* student)
    {
        if (student->student_id > MAX_STUDENT_ID && student->student_id < MIN_STUDENT_ID)
        {
            throw InvalidStudent();
            return false;
        }
        return true;
    }

}