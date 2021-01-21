// #include <iostream>
// #include "base_event.h"
// #include "custom_event.h"
// #include "date_wrap.h"
// #include "exceptions.h"

// const int MAX_STUDENT_ID = 1234567890;
// const int MIN_STUDENT_ID = 1;


// namespace mtm {
    
//     template <class CanRegister>
//     CustomEvent<CanRegister>::CustomEvent(DateWrap date, std::string name, CanRegister can_register_func) : 
//     BaseEvent(date, name), can_register_func(can_register_func) {}
    
//     template <class CanRegister>
//     CustomEvent<CanRegister>::CustomEvent(const CustomEvent& open_event)
//     {
//         this->date = open_event.date;
//         this->name = open_event.name;
//         this->students_list = open_event.students_list;
//         this->can_register_func = open_event.can_register_func;
//     }

//     template <class CanRegister>
//     void CustomEvent<CanRegister>::registerParticipant(int student_id)
//     {
//         is_valid_student(student_id);

//         bool is_student_in_list_return = is_student_in_list(this->students_list, student_id);
//         if (is_student_in_list_return)
//         {
//             throw AlreadyRegistered();
//         }

//         bool is_student_can_register = this->can_register_func(student_id);
//         if (is_student_can_register == false)
//         {
//             throw RegistrationBlocked();
//         }

//         add_to_students_list(this->students_list, student_id);
//     }

//     template <class CanRegister>
//     BaseEvent* CustomEvent<CanRegister>::clone() const
//     {
//         return new CustomEvent(*this);
//     }

// }