#ifndef DATE_WRAP_H
#define DATE_WRAP_H

#include <iostream>

extern "C" {
    #include "../provided/date.h"
}

namespace mtm 
{
    class DateWrap{
    private:
        Date date;
        enum date_parameter {DAY,MONTH,YEAR};

        /**
        * getDateParameter: a static private method for getting one of the parameters of date - day or month or year.
        *
        * @param date - a date to get the parameter of.
        * @param date_parameter - a parameter to get from the date.
        * @return
        * 	int of the parameter in the date.
        *   if faile return -1
        */
        static int getDateParameter(Date date, enum date_parameter date_parameter);

    public:
        DateWrap(int day, int month, int year);
        DateWrap(const DateWrap& date_wrap);
        ~DateWrap();
        
        int day() const;
        int month() const;
        int year() const;

	    DateWrap& operator=(const DateWrap& date_wrap);
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