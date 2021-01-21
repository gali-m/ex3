#include "date_wrap.h"
#include "exceptions.h"

namespace mtm
{
    int DateWrap::get_date_parameter(Date date, enum date_parameter date_parameter)
    {
        int day, month, year;
        bool date_get_return = dateGet(date, &day, &month, &year);
        if(date_get_return == false)
        {
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
                return -1;
        }
    }

    DateWrap::DateWrap(int day, int month, int year)
    {
        this->date = dateCreate(day, month, year);
        if(this->date == NULL)
        {
            throw InvalidDate();
        }
    }

    DateWrap::DateWrap(const DateWrap& date_wrap)
    {
        this->date = dateCopy(date_wrap.date);
        if(this->date == NULL)
        {
            throw InvalidDate();
        }
    }

    DateWrap::~DateWrap()
    {
        dateDestroy(this->date);
    }

    DateWrap& DateWrap::operator=(const DateWrap& date_wrap)
    {
        if (this == &date_wrap) {
            return *this;
        }
        Date tmp_date = dateCopy(date_wrap.date);
        dateDestroy(this->date);
        this->date = tmp_date;
        return *this;

    }

    int DateWrap::day() const
    {
        return get_date_parameter(this->date,DAY);
    }

    int DateWrap::month() const
    {
        return get_date_parameter(this->date,MONTH);
    }

    int DateWrap::year() const
    {
        return get_date_parameter(this->date,YEAR);
    }

    bool DateWrap::operator==(const DateWrap& date_wrap)
    {
    int comparison = dateCompare(this->date, date_wrap.date);
    return (comparison == 0);
    }

    bool DateWrap::operator!=(const DateWrap& date_wrap) 
    {
    return !(operator==(date_wrap));
    }

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

    bool DateWrap::operator>=(const DateWrap& date_wrap) 
    {
    return !(DateWrap::operator<(date_wrap));
    }

    bool DateWrap::operator<=(const DateWrap& date_wrap) 
    {
    return !(DateWrap::operator>(date_wrap));
    }

    DateWrap DateWrap::operator++(int) 
    {
        DateWrap tmp = DateWrap(*this);
        dateTick(this->date);
        return tmp;
    }

    DateWrap& DateWrap::operator+=(int days)
    {
        if (days < 0)
        {
            throw NegativeDays();
        }
        
        for(int i=0; i < days; i++)
        {
            dateTick(this->date);
        }
        return *this;
    }

    DateWrap operator+(const DateWrap& date_wrap, int days) 
    {
        return DateWrap(date_wrap) += days;
    }

    DateWrap operator+(int days, const DateWrap& date_wrap) 
    {
        return DateWrap(date_wrap) += days;
    }

    std::ostream& operator<<(std::ostream& os, const DateWrap& date_wrap)
    {
        return os << date_wrap.day() << "/" << date_wrap.month() << "/" << date_wrap.year();
    }
}