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
        Date date;
        enum date_parameter {DAY,MONTH,YEAR};
        static int get_date_parameter(Date date, enum date_parameter date_parameter);
        DateWrap(Date date);

    public:
        DateWrap(int day, int month, int year);
        ~DateWrap();
        int get_day();
        int get_month();
        int get_year();
        friend std::ostream& operator<<(std::ostream& out, DateWrap const& date);
        bool operator>(const DateWrap& date);
        bool operator<(const DateWrap& date);
        bool operator=(const DateWrap& date);
        bool operator>=(const DateWrap& date);
        bool operator<=(const DateWrap& date);
        bool operator!=(const DateWrap& date);
        DateWrap operator++(int);
        DateWrap& operator+=(int days);
        DateWrap operator+(int days);
    };
}


#endif //DATE_WRAP_H