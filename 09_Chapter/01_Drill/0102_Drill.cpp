// implementing the Date class from section 9.4.2
// Programming: Principles and Practice Using C++

#include "../../std_lib_facilities.h"

// simple Date (not so simple :-) )
// ensure initialisation with constructor
// provide some notational convenicence
struct Date {
    int y, m, d;                // year, month and day, respectively
    Date(int y, int m, int d);  // check for valid date and initialise
    void add_day(int n);        // increase Date by n days
};

// helper functions
class Invalid {};   // for throwing exceptions

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

Date::Date(int yy, int mm, int dd)
     :y{yy}, m{mm}, d{dd}
{
    if(! is_date(yy, mm, dd)) throw Invalid{};
}

void Date::add_day(int n)
{
    d += n;
    if(! is_date(y, m, d)) throw Invalid{};

}

// operator overloading
// i.e. defining the meaning of the << operator with Date objects
ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y
              << ',' << d.m
              << ',' << d.d << ')';
}

void f()
{
    // initialise dates
    Date today{1978, 6, 25};
    Date tomorrow{1978, 6, 25};
    tomorrow.add_day(1);

    // printing out the Dates
    cout << "Today is: " << today << '\n';

    cout << "Tomorrow is: " << tomorrow;

    // try out invalid Date
    // throws exception as expected
    // Date date_invalid{1978, 2, 30};
}

int main()
{
    f();
    return 0;
}