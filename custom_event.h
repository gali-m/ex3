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

        CustomEvent(const CustomEvent& custom_event): BaseEvent(custom_event.date, custom_event.name)
        {
            if(custom_event.students_list != NULL)
            {
                this->students_list = new StudentNode(custom_event.students_list);
            }
            this->can_register_func = custom_event.can_register_func;
        }

        void registerParticipant(int student_id) override
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

        BaseEvent* clone() const override
        {
            return new CustomEvent(*this);
        }

    };

}


#endif //CUSTOM_EVENT_H