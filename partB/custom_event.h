#ifndef CUSTOM_EVENT_H
#define CUSTOM_EVENT_H

#include <iostream>
#include "../partA/date_wrap.h"
#include "base_event.h"
#include "../partA/exceptions.h"

namespace mtm {

    template <class CanRegister>
    class CustomEvent : public BaseEvent{
        CanRegister can_register_func;
    
    public:
        CustomEvent(DateWrap date, std::string name, CanRegister can_register_func) : 
            BaseEvent(date, name), can_register_func(can_register_func) {}

        CustomEvent(const CustomEvent& custom_event): BaseEvent(custom_event)
        {
            this->can_register_func = custom_event.can_register_func;
        }

        void registerParticipant(int student_id) override
        {
            isValidStudent(student_id);

            bool is_student_in_list_return = isStudentInList(this->students_list, student_id);
            if (is_student_in_list_return)
            {
                throw AlreadyRegistered();
            }

            bool is_student_can_register = this->can_register_func(student_id);
            if (is_student_can_register == false)
            {
                throw RegistrationBlocked();
            }

            if(this->students_list == NULL)
            { // if list is empty
                this->students_list = new StudentNode(student_id, NULL);
            }
            else if(this->students_list->student_id > student_id)
            { // the first student is bigger
                this->students_list = new StudentNode(student_id, this->students_list);
            }
            else
            {
                addToStudentsList(this->students_list, student_id);
            }
        }

        CustomEvent<CanRegister>* clone() const override
        {
            return new CustomEvent(*this);
        }
    };
}


#endif //CUSTOM_EVENT_H