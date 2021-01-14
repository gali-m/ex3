#include <iostream>
#include "base_event.h"
#include "open_event.h"
#include "date_wrap.h"
#include "exceptions.h"

const int MAX_STUDENT_ID = 1234567890;
const int MIN_STUDENT_ID = 1;


namespace mtm {
    
    OpenEvent::OpenEvent(DateWrap date, std::string name) : BaseEvent(date, name) {}

    // OpenEvent::OpenEvent(const OpenEvent& open_event)
    // {
    //     this->date = open_event.date;
    //     this->name = open_event.name;
    //     this->students_list = open_event.students_list;
    // }

    void OpenEvent::registerParticipant(int student_id)
    {
        is_valid_student(student_id);

        bool is_student_in_list_return = is_student_in_list(this->students_list, student_id);
        if (is_student_in_list_return)
        {
            throw AlreadyRegistered();
        }

        add_to_students_list(this->students_list, student_id);
    }

    BaseEvent* OpenEvent::clone()
    {
        return new OpenEvent(*this);
    }

}