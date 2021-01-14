#include <iostream>
#include "base_event.h"
#include "closed_event.h"
#include "date_wrap.h"
#include "exceptions.h"

const int MAX_STUDENT_ID = 1234567890;
const int MIN_STUDENT_ID = 1;


namespace mtm {
    
    ClosedEvent::ClosedEvent(DateWrap date, std::string name) : BaseEvent(date, name), guest_list(NULL) {}

    // ClosedEvent::ClosedEvent(const ClosedEvent& open_event)
    // {
    //     this->date = open_event.date;
    //     this->name = open_event.name;
    //     this->students_list = open_event.students_list;
    //     this->guest_list = open_event.guest_list;
    // }

    void ClosedEvent::addInvitee(int student_id)
    {
        is_valid_student(student_id);

        bool is_student_in_list_return = is_student_in_list(this->students_list, student_id);
        if (is_student_in_list_return)
        {
            throw AlreadyInvited();
        }

        add_to_students_list(this->guest_list, student_id);
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

        add_to_students_list(this->students_list, student_id);
    }

    BaseEvent* ClosedEvent::clone()
    {
        return new ClosedEvent(*this);
    }

}