#include "date_wrap.h"
#include "exceptions.h"
#include <iostream>
using mtm::DateWrap;
using std::cout;
using std::endl;

template <class T> void print(const T& x) { cout << x << endl; }
int main() {
    DateWrap date(30, 11, 2020);
    print(date);
    print(date + 4);
    print(3 + date);
    date++;
    print(date);
    date += 7;
    print(date);
    print(date > DateWrap(29, 11, 2020));
    print(date <= DateWrap(29, 11, 2020));
    print(date == DateWrap(30, 11, 2020));
    print(date == DateWrap(8, 12, 2020));
    try {
        date += (-3);
    } catch (mtm::NegativeDays) {
        print("NegativeDays");
    }
    try {
        date = date + (-3);
    } catch (mtm::NegativeDays) {
        print("NegativeDays");
    }


    // our test cases:

    try
    {
        DateWrap(31,11,2020);
    }
    catch (mtm::InvalidDate) {
        print("InvalidDate");
    }
    try
    {
        DateWrap(30,13,2020);
    }
    catch (mtm::InvalidDate) {
        print("InvalidDate");
    }
    try
    {
        DateWrap(0,12,2020);
    }
    catch (mtm::InvalidDate) {
        print("InvalidDate");
    }
    try
    {
        DateWrap(12,-1,2020);
    }
    catch (mtm::InvalidDate) {
        print("InvalidDate");
    }
    {
        DateWrap date2(date);
    }
    print(date);
    DateWrap date2(01,02,0003);
    print(date2);
    print(date.day());
    print(date.month());
    print(date.year());
    print(date2.day());
    print(date2.month());
    print(date2.year());
    print("date != dates:");
    print(date != DateWrap(8, 12, 2020));
    print(date != date2);
    print(date != DateWrap(9, 12, 2020));
    print(date != DateWrap(29, 10, 2020));
    print(date != DateWrap(29, 11, 20));
    print("date == dates:");
    print(date == DateWrap(8, 12, 2020));
    print(date == date2);
    print(date == DateWrap(9, 12, 2020));
    print(date == DateWrap(29, 10, 2020));
    print(date == DateWrap(29, 11, 20));
    print("date <= dates:");
    print(date <= DateWrap(8, 12, 2020));
    print(date <= date2);
    print(date <= DateWrap(9, 12, 2020));
    print(date <= DateWrap(7, 12, 2020));
    print(date <= DateWrap(29, 11, 2020));
    print(date <= DateWrap(29, 11, 2021));
    print(date <= DateWrap(9, 12, 2019));
    print("date >= dates:");
    print(date >= DateWrap(8, 12, 2020));
    print(date >= date2);
    print(date >= DateWrap(9, 12, 2020));
    print(date >= DateWrap(7, 12, 2020));
    print(date >= DateWrap(29, 11, 2020));
    print(date >= DateWrap(29, 11, 2021));
    print(date >= DateWrap(9, 12, 2019));
    print("date < dates:");
    print(date < DateWrap(8, 12, 2020));
    print(date < date2);
    print(date < DateWrap(9, 12, 2020));
    print(date < DateWrap(7, 12, 2020));
    print(date < DateWrap(29, 11, 2020));
    print(date < DateWrap(29, 11, 2021));
    print(date < DateWrap(9, 12, 2019));
    print("date > dates:");
    print(date > DateWrap(8, 12, 2020));
    print(date > date2);
    print(date > DateWrap(9, 12, 2020));
    print(date > DateWrap(7, 12, 2020));
    print(date > DateWrap(29, 11, 2020));
    print(date > DateWrap(29, 11, 2021));
    print(date > DateWrap(9, 12, 2019));

    date = DateWrap(30,12,2020);
    print(date);
    print(date++);
    print(date);
    date2 = date++ + 1;
    print(date);
    print(date2);
    try
    {
        date2 += 0;
    }
    catch (mtm::NegativeDays) {
        print("InvalidDate");
    }
    date = DateWrap(30,12,2020);
    date += 1;
    print(date);
    date += 2;
    print(date);
    try
    {
        date2 = date2 + 0;
    }
    catch (mtm::NegativeDays) {
        print("InvalidDate");
    }
    try
    {
        date2 = 0 + date2;
    }
    catch (mtm::NegativeDays) {
        print("InvalidDate");
    }
    date2 = DateWrap(15,12,45);
    date2 = 5 + date2;
    print(date2);
    date2 = date2 + 11;
    print(date2);
    




    return 0;
}