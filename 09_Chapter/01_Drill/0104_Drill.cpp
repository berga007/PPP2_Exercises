// implementing the Date class from section 9.7.1 ("Argument Types")
// Programming: Principles and Practice Using C++

#include "../../std_lib_facilities.h"

// define the Month type as an enumeration
enum class Month{
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

// class Invalid for throwing exceptions
class Invalid {};

// simple Date(use Month type)
class Date{
public:
    Date(int y, Month m, int d); // check for validity and initialise
    void add_day(int n);    // increase the date by n days

    // non-modifying member functions
    Month month() const { return m;}
    int day() const {return d;}
    int year() const {return y;}
private:
    int y;
    Month m;
    int d;
};

// helper functions
bool is_date(int y, Month m, int d)
{
    // function that checks if date is valid
    if(d <= 0) return false;

    if(m < Month::jan || Month::dec < m) return false;

    if(y < 0) return false; // negative years are not allowed

    int days_in_month = 31; // majority of months have 31 days

    if(m == Month::feb){ // february
        days_in_month = 28; // for now assume year was not a leapyear
    } else if (m == Month::apr || m == Month::jun || m == Month::sep || m == Month::nov){
        days_in_month = 30; 
    }

    if(days_in_month < d ) return false;

    return true;
}

// operator overloading

// define vector with months

const vector <string> month_tbl = {
    "", "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

// i.e. defining a meaning for the << operator with Month objects
ostream& operator<<(ostream& os, const Month& m)
{
    return os << month_tbl[int(m)];
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year()
              << ',' << d.month()
              << ',' << d.day() << ')';
}


Date::Date(int yy, Month mm, int dd)
    :y{yy}, m{mm}, d{dd}
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
    Date today{1978, Month::jun, 25};
    Date tomorrow{1978, Month::jun, 25};

    tomorrow.add_day(1);

    // printing out the Dates
    cout << "Today is: " << today << '\n';

    cout << "Tomorrow is: " << tomorrow;

    // initialise invalid date
    // throws an error
    // Date invalid_date{1978, Month::feb, 30};

}

int main()
{
    f();

    return 0;
}
