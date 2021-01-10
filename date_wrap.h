#ifndef DATE_WRAP_H
#define DATE_WRAP_H

#include <iostream>

extern "C" {
    #include "date.h"
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

    public:
        DateWrap(int day, int month, int year);
        ~DateWrap();
        DateWrap(const DateWrap& date_wrap);
	    DateWrap& operator=(const DateWrap& date_wrap);
        int get_day() const;
        int get_month() const;
        int get_year() const;
        bool operator==(const DateWrap& date_wrap);
	    // friend std::ostream& operator<<(std::ostream& os, const DateWrap& date_wrap);
        friend std::ostream& operator<<(std::ostream& os, const DateWrap& date_wrap);
        bool operator>(const DateWrap& date);
        bool operator<(const DateWrap& date);
        bool operator>=(const DateWrap& date);
        bool operator<=(const DateWrap& date);
        bool operator!=(const DateWrap& date);
        DateWrap operator++(int);
        DateWrap& operator+=(int days);
        friend DateWrap operator+(const DateWrap& wrap_date, int days);
        friend DateWrap operator+(int days, const DateWrap& wrap_date);
    };
}


#endif //DATE_WRAP_H