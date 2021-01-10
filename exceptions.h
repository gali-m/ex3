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
}


#endif //EXCEPTIONS_H