#include <iostream>
#include "base_event.h"
#include "date_wrap.h"
#include "exceptions.h"

// const int MAX_STUDENT_ID = 1234567890;
// const int MIN_STUDENT_ID = 1;


namespace mtm {

    StudentNode::StudentNode(int student_id, StudentNode* next) : student_id(student_id), next(next) {}

    //TODO: fix studenNode copy
    StudentNode::StudentNode(const StudentNode* student_node)
    {
        if (student_node != NULL)
        {
            this->student_id = student_node->student_id;

            if (student_node->next == NULL)
            {
                this->next = NULL;
            }
            else 
            {
                this->next = new StudentNode(student_node->next->student_id, student_node->next->next);
            }
        }
    }

    // StudentNode::~StudentNode()
    // {
    //     StudentNode* current = this;
    //     StudentNode* next = current->next;

    //     while (next != NULL) {
    //         next = current->next;
    //         delete current;
    //         current = next;
    //     }
    // }

    // StudentList::StudentList() : student(NULL) {}

    // StudentList::StudentList(StudentNode* student) : student(student) {}

    // StudentList::~StudentList()
    // {
    //     StudentNode* current = this->student;
    //     StudentNode* next;

    //     while (current != NULL) {
    //         next = current->next;
    //         delete current;
    //         current = next;
    //     }
    // }

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

    BaseEvent::~BaseEvent() 
    {
        StudentNode* current = this->students_list;
        StudentNode* next;

        while (current != NULL) {
            next = current->next;
            delete current;
            current = next;
        }
    }


    bool BaseEvent::is_student_in_list(StudentNode* students_list, int student_id)
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

    bool BaseEvent::is_valid_student(int student_id)
    {
        if (student_id > MAX_STUDENT_ID && student_id < MIN_STUDENT_ID)
        {
            throw InvalidStudent();
            return false;
        }
        return true;
    }

    void BaseEvent::registerParticipant(int student_id)
    {
        is_valid_student(student_id);

        bool is_student_in_list_return = is_student_in_list(this->students_list, student_id);
        if (is_student_in_list_return)
        {
            throw AlreadyRegistered();
        }

        // if list is empty
        if(this->students_list == NULL)
        {
            this->students_list = new StudentNode(student_id, NULL);
        }
        else if(this->students_list->student_id > student_id)
        {
            this->students_list = new StudentNode(student_id, this->students_list);
        }
        else
        {
            add_to_students_list(this->students_list, student_id);
        }

    }

    void BaseEvent::unregisterParticipant(int student_id)
    {
        is_valid_student(student_id);

        StudentNode* current_student = this->students_list;

        while (current_student != NULL)
        {
            if (current_student->student_id == student_id)
            {
                StudentNode* node_to_remove = current_student;

                if(this->students_list == current_student)
                {
                    this->students_list = current_student->next;
                }

                current_student = current_student->next;

                node_to_remove->next = NULL;
                delete node_to_remove;
                return;
            }
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

    void BaseEvent::add_to_students_list(StudentNode* students_list, int student_id)
    {
        if(students_list == NULL)
        {
            students_list = new StudentNode(student_id, NULL);
            return;
        }

        StudentNode* current = students_list;
        StudentNode* before_current = NULL;

        while (current->student_id < student_id) {
            if (current->next == NULL)
            {
                current->next = new StudentNode(student_id, NULL);
                return;
            }
            before_current = current;
            current = current->next;
        }

        if(before_current == NULL)
        {
            students_list = new StudentNode(student_id, current);
            return;
        }

        before_current->next = new StudentNode(student_id, (*before_current).next);
    }

}