#include <iostream>
#include "base_event.h"
#include "closed_event.h"
#include "date_wrap.h"
#include "exceptions.h"

const int MAX_STUDENT_ID = 1234567890;
const int MIN_STUDENT_ID = 1;


namespace mtm {
    
    ClosedEvent::ClosedEvent(DateWrap date, std::string name) : date(date), name(name) 
    {
        students_list = NULL;
    }

    ClosedEvent::ClosedEvent(const ClosedEvent& open_event)
    {
        this->date = open_event.date;
        this->name = open_event.name;
        this->students_list = open_event.students_list;
    }


    void ClosedEvent::registerParticipant(StudentNode* student)
    {
        is_valid_student(student);

        bool is_student_in_list_return = is_student_in_list(this->students_list, student);
        if (is_student_in_list_return)
        {
            throw AlreadyRegistered();
        }

        this->students_list += student;
    }

    void ClosedEvent::unregisterParticipant(StudentNode* student) {}

    std::ostream& ClosedEvent::printShort(std::ostream& os) {}

    std::ostream& ClosedEvent::printLong(std::ostream& os) {}


    BaseEvent* ClosedEvent::clone()
    {
        return new ClosedEvent(*this);
    }

}