#include "date_wrap.h"
#include "exceptions.h"

namespace mtm
{
    // DateWrap private methods:

    int DateWrap::getDateParameter(Date date, enum date_parameter date_parameter)
    {
        int day, month, year;
        bool date_get_return = dateGet(date, &day, &month, &year);
        if(date_get_return == false)
        { // faile to get date
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

    // DateWrap constructor and destructor methods:

    DateWrap::DateWrap(int day, int month, int year)
    {
        this->date = dateCreate(day, month, year);
        if(this->date == nullptr)
        {
            throw InvalidDate();
        }
    }

    DateWrap::DateWrap(const DateWrap& date_wrap)
    {
        this->date = dateCopy(date_wrap.date);
        if(this->date == nullptr)
        {
            throw InvalidDate();
        }
    }

    DateWrap::~DateWrap()
    {
        dateDestroy(this->date);
    }

    // DateWrap geters methods:

    int DateWrap::day() const
    {
        return getDateParameter(this->date,DAY);
    }

    int DateWrap::month() const
    {
        return getDateParameter(this->date,MONTH);
    }

    int DateWrap::year() const
    {
        return getDateParameter(this->date,YEAR);
    }

    // DateWrap operators methods:

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