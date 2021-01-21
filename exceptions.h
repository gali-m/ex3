#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

// #include <iostream>
// #include "date_wrap.h"



namespace mtm 
{
    class Exception : public std::exception {};

    //part A
    class InvalidDate : public mtm::Exception {};
    class NegativeDays : public mtm::Exception {};

    //part B
    class AlreadyRegistered : public mtm::Exception {};
    class InvalidStudent : public mtm::Exception {};
    class NotRegistered : public mtm::Exception {};
    class AlreadyInvited : public mtm::Exception {};
    class RegistrationBlocked : public mtm::Exception {};
    //collections
    class NotSupported : public mtm::Exception {};
    class DateMismatch : public mtm::Exception {};
    class InvalidNumber : public mtm::Exception {};
    class InvalidInterval : public mtm::Exception {};

    //part C
    class EventAlreadyExists :public mtm::Exception {};
    class EventDoesNotExist :public mtm::Exception {};
        
    // static func
    class StudentInList : public mtm::Exception {};
}


#endif //EXCEPTIONS_H