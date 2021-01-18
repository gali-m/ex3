#include <iostream>
#include "base_event.h"
#include "closed_event.h"
#include "date_wrap.h"
#include "exceptions.h"

const int MAX_STUDENT_ID = 1234567890;
const int MIN_STUDENT_ID = 1;


namespace mtm {
    
    ClosedEvent::ClosedEvent(const DateWrap date, const std::string name) : BaseEvent(date, name), guest_list(NULL) {}

    ClosedEvent::ClosedEvent(const ClosedEvent& closed_event) : BaseEvent(closed_event)
    {
        // if(closed_event.students_list != NULL)
        // {
        //     this->students_list = new StudentNode(closed_event.students_list);
        // }

        // if(closed_event.guest_list != NULL)
        // {
        //     this->guest_list = new StudentNode(closed_event.guest_list);
        // }
        this->guest_list = copy_students_list(this->guest_list, closed_event.students_list);
    }


    ClosedEvent::~ClosedEvent()
    {
        StudentNode* current = this->guest_list;
        StudentNode* next;

        while (current != NULL) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    void ClosedEvent::addInvitee(int student_id)
    {
        is_valid_student(student_id);

        bool is_student_in_list_return = is_student_in_list(this->guest_list, student_id);
        if (is_student_in_list_return)
        {
            throw AlreadyInvited();
        }

        // if list is empty
        if(this->guest_list == NULL)
        {
            this->guest_list = new StudentNode(student_id, NULL);
        }
        else if(this->guest_list->student_id > student_id)
        {
            this->guest_list = new StudentNode(student_id, this->guest_list);
        }
        else
        {
            add_to_students_list(this->guest_list, student_id);
        }
    }

    void ClosedEvent::registerParticipant(int student_id)
    {
        is_valid_student(student_id);

        bool is_student_in_list_return = is_student_in_list(this->students_list, student_id);
        if (is_student_in_list_return)
        {
            throw AlreadyRegistered();
        }

        bool is_student_in_guest_list_return = is_student_in_list(this->guest_list, student_id);
        if (is_student_in_guest_list_return == false)
        {
            throw RegistrationBlocked();
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

    BaseEvent* ClosedEvent::clone() const
    {
        return new ClosedEvent(*this);
    }

}