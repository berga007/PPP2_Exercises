// implementing the Date class from section 9.4.3 ("Keep details private")
// Programming: Principles and Practice Using C++

#include "../../std_lib_facilities.h"

// simple Date (make the representation of Date inaccessible to users)
class Date{
    // by default members are kept private, i.e. inaccessible
    int y, m, d;    // year, month and day, respectively

public:
    Date(int y, int m, int d);  // check for valid Date and initialise
    void add_day(int n);        // increase the Date by n days
    
    // non-modifying member functions
    int month() const { return m;}
    int day() const {return d;}
    int year() const {return y;}
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

// operator overloading
// i.e. defining a meaning for the << operator with Date objects
ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year()
              << ',' << d.month()
              << ',' << d.day() << ')';
}

// member functions of the class Date
Date::Date(int yy, int mm, int dd)  // constructor
     :y{yy}, m{mm}, d{dd}           // member initialisers
{
    if(! is_date(yy, mm, dd)) throw Invalid{};
}

void Date::add_day(int n)
{
    d+=n;
    if(! is_date(y, m, d)) throw Invalid{};
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

}

int main()
{
    f();
    return 0;
}
