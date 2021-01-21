#ifndef DATE_WRAP_H
#define DATE_WRAP_H

#include <iostream>

extern "C" {
    #include "date.h"
}

namespace mtm 
{
    class DateWrap{
    private:
        Date date;
        enum date_parameter {DAY,MONTH,YEAR};
        static int get_date_parameter(Date date, enum date_parameter date_parameter);

    public:
        DateWrap(int day, int month, int year);
        DateWrap(const DateWrap& date_wrap);
        ~DateWrap();
	    DateWrap& operator=(const DateWrap& date_wrap);
        int day() const;
        int month() const;
        int year() const;
        bool operator==(const DateWrap& date_wrap);
        bool operator!=(const DateWrap& date_wrap);
        bool operator>(const DateWrap& date_wrap);
        bool operator<(const DateWrap& date_wrap);
        bool operator>=(const DateWrap& date_wrap);
        bool operator<=(const DateWrap& date_wrap);
        DateWrap operator++(int);
        DateWrap& operator+=(int days);
        friend DateWrap operator+(const DateWrap& date_wrap, int days);
        friend DateWrap operator+(int days, const DateWrap& date_wrap);
        friend std::ostream& operator<<(std::ostream& os, const DateWrap& date_wrap);
    };
}


#endif //DATE_WRAP_H