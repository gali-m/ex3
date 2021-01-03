#ifndef DATE_WRAP_H
#define DATE_WRAP_H

#include <iostream>

extern "C" {
    #include "../provided/date.h"
}

namespace mtm {

    // class DateWrap{
    // public:
    //     // DateWrap(int day, int month, int year);
    //     int get_day();
    //     // int get_month();
    //     // int get_year();
    //     // friend std::ostream& operator<<(std::ostream& out, DateWrap const& date);
    // };

    class DateWrap{
    private:
        int day;
        int month;
        int year;

    public:
        DateWrap(int day, int month, int year);
        int get_day();
        int get_month();
        int get_year();
        // friend std::ostream& operator<<(std::ostream& out, DateWrap const& date);
    };
}


#endif //DATE_WRAP_H