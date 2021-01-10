#include <iostream>
#include "date_wrap.h"
using namespace mtm;


DateWrap::DateWrap(int day, int month, int year)
{
    this->date = dateCreate(day, month, year);
    if(this->date == NULL)
    {
        //TODO return exp InvalidDate
    }
}

DateWrap::DateWrap(Date date)
{
    this->date = dateCopy(date);
    if(this->date == NULL)
    {
        //TODO return exp InvalidDate
    }
}

DateWrap::~DateWrap()
{
    dateDestroy(this->date);
}

int DateWrap::get_date_parameter(Date date, enum date_parameter date_parameter)
{
    int day, month, year;
    bool date_get_return = dateGet(date, &day, &month, &year);
    if(date_get_return == false)
    {
        //TODO return exp 
        return -1;
    }

    switch (date_parameter)
    {
        case DAY:
            return day;
        case MONTH:
            return month;
        case YEAR:
            return year;
        default:
            //TODO return exp 
            return -1;
    }
}

int DateWrap::get_day()
{
    int day = get_date_parameter(this->date,DAY);
    if(day == -1)
    {
        //TODO return exp 
    }
    return day;
}

int DateWrap::get_month()
{
    int month = get_date_parameter(this->date,MONTH);
    if(month == -1)
    {
        //TODO return exp 
    }
    return month;
}

int DateWrap::get_year()
{
    int year = get_date_parameter(this->date,YEAR);
    if(year == -1)
    {
        //TODO return exp 
    }
    return year;
}

// friend std::ostream& operator<<(std::ostream& out, DateWrap const& date);
// friend std::ostream& DateWrap::operator<<(std::ostream& out, const DateWrap& date) {
//     out << date.day << '/' << date.month << '/' << date.year;
//     return out;
// }

bool DateWrap::operator>(const DateWrap& date_wrap) 
{
   int comparison = dateCompare(this->date, date_wrap.date);
   return (comparison > 0);
}

bool DateWrap::operator<(const DateWrap& date_wrap) 
{
   int comparison = dateCompare(this->date, date_wrap.date);
   return (comparison < 0);
}

bool DateWrap::operator=(const DateWrap& date_wrap) 
{
   int comparison = dateCompare(this->date, date_wrap.date);
   return (comparison == 0);
}

bool DateWrap::operator>=(const DateWrap& date_wrap) 
{
   return !(DateWrap::operator<(date_wrap));
}

bool DateWrap::operator<=(const DateWrap& date_wrap) 
{
   return !(DateWrap::operator>(date_wrap));
}

bool DateWrap::operator!=(const DateWrap& date_wrap) 
{
   return !(DateWrap::operator=(date_wrap));
}

DateWrap DateWrap::operator++(int) 
{
    DateWrap tmp(this->date);
    dateTick(this->date);
    return *this;
}

DateWrap& DateWrap::operator+=(int days)
{
    if (days < 0)
    {
        // TODO: NegativeDays exp
    }
    
    for(int i=0; i < days; i++)
    {
        dateTick(this->date);
    }
    return *this;
}

DateWrap DateWrap::operator+(int days)
{
    return DateWrap(this->date)+=days;
}