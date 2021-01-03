#include <iostream>
#include "date_wrap.h"
#include "../provided/date.h"
using namespace mtm;


DateWrap::DateWrap(int day, int month, int year)
{
    Date date = dateCreate(day, month, year);
    if(date == NULL)
    {
        //TODO return exp InvalidDate
    }

    bool date_get_return = dateGet(date, &(this->day), &(this->month), &(this->year));
    if(date_get_return == false)
    {
        //TODO return exp 
    }
}

int DateWrap::get_day()
{
    return this->day;
}

int DateWrap::get_month()
{
    return this->month;
}

int DateWrap::get_year()
{
    return this->year;
}

// friend std::ostream& operator<<(std::ostream& out, DateWrap const& date);
// friend std::ostream& DateWrap::operator<<(std::ostream& out, const DateWrap& date) {
//     out << date.day << '/' << date.month << '/' << date.year;
//     return out;
// }

// class mtm::DateWrap{
//     int day;
//     int month;
//     int year;

// public:
//     // DateWrap(int day, int month, int year);
//     DateWrap(int day, int month, int year)
//     {
//         Date date = dateCreate(day, month, year);
//         if(date == NULL)
//         {
//             //TODO return exp InvalidDate
//         }

//         bool date_get_return = dateGet(date, &(this->day), &(this->month), &(this->year));
//         if(date_get_return == false)
//         {
//             //TODO return exp 
//         }
//     }
//     // int get_day();
//     // int get_month();
//     // int get_year();
//     int get_day()
//     {
//         return this->day;
//     }

//     int get_month()
//     {
//         return this->month;
//     }

//     int get_year()
//     {
//         return this->year;
//     }

//     // friend std::ostream& operator<<(std::ostream& out, DateWrap const& date);
//     friend std::ostream& operator<<(std::ostream& out, const DateWrap& date) {
//         out << date.day << '/' << date.month << '/' << date.year;
//         return out;
//     }

// };


