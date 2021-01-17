#ifndef CUSTOM_EVENT_H
#define CUSTOM_EVENT_H

#include <iostream>
#include "date_wrap.h"
#include "base_event.h"
#include "exceptions.h"

const int MAX_STUDENT_ID = 1234567890;
const int MIN_STUDENT_ID = 1;

namespace mtm {

    template <class CanRegister>
    class CustomEvent : public BaseEvent{
        CanRegister can_register_func;
    
    public:
        CustomEvent(DateWrap date, std::string name, CanRegister can_register_func) : 
            BaseEvent(date, name), can_register_func(can_register_func) {}

        CustomEvent(const CustomEvent& open_event): BaseEvent(open_event.date, open_event.name)
        {
            this->students_list = open_event.students_list;
            this->can_register_func = open_event.can_register_func;
        }

        void registerParticipant(int student_id)
        {
            is_valid_student(student_id);

            bool is_student_in_list_return = is_student_in_list(this->students_list, student_id);
            if (is_student_in_list_return)
            {
                throw AlreadyRegistered();
            }

            bool is_student_can_register = this->can_register_func(student_id);
            if (is_student_can_register == false)
            {
                throw RegistrationBlocked();
            }

            add_to_students_list(this->students_list, student_id);
        }

        BaseEvent* clone() const override
        {
            return new CustomEvent(*this);
        }

    };

}


#endif //CUSTOM_EVENT_H