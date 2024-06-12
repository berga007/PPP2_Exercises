// implementing the Date class from section 9.4.1
// Programming: Principles and Practice Using C++

#include "../../std_lib_facilities.h"

// simple Date
// probably too simple

// main problem with this design: since data members (y,m,d) are public
// the user can modify them directly, possibly assigning invalid values

struct Date {
    int y; // year
    int m; // month in year
    int d; // day of month
};

// helper functions

class Invalid {};

bool is_date(int y, int m, int d)
{
    // function that checks if date is valid
    if(d <= 0) return false;

    if(m < 1 || 12 < m) return false;

    if(y < 0) return false; // negative years are not allowed

    int days_in_month = 31; // majority of months have 31 days

    if(m == 2){ // february
        days_in_month = 28; // for now assume year was not a leapyear
    } else if (m == 4 || m == 6 || m == 9 || m == 11){
        days_in_month = 30; 
    }

    if(days_in_month < d ) return false;

    return true;

}

void init_day(Date& dd, int y, int m, int d)
{
    // check that (y,m,d) is a valid date
    // if it is, then initialise dd
    if(! is_date(y, m, d)) throw Invalid{};

    dd.y = y;
    dd.m = m;
    dd.d = d;

}

Date add_Day(Date& dd, int n)
{

    // check if (y, m, d+n) is a valid Date
    // if so, initialise
    Date new_date{};

    init_day(new_date, dd.y, dd.m, dd.d+n);

    return new_date;
}

// operator overloading
// i.e. redefining the meaning of the << 
ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y
              << ',' << d.m
              << ',' << d.d << ')';
}

void f()
{
    // initialise the date object
    Date today{};

    // assign today to June the 25th 1978
    init_day(today, 1978, 6, 25);

    Date tomorrow = add_Day(today, 1);

    // printing out the Dates
    cout << "Today is: " << today << '\n';

    cout << "Tomorrow is: " << tomorrow;

    // trying out an invalid Date
    // throws an error as expected
    Date date_invalid{};

    // date_invalid = add_Day(tomorrow, 5);
}

int main()
{
    f();

    return 0;
}