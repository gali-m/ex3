#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

// #include <iostream>
// #include "date_wrap.h"



namespace mtm {

    class Exception : public std::exception {};


    //part B
    class AlreadyRegistered : public mtm::Exception {};
    class InvalidStudent : public mtm::Exception {};
        
    // static func
    class StudentInList : public mtm::Exception {};
}


#endif //EXCEPTIONS_H