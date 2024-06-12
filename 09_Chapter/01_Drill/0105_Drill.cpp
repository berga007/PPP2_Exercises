// implementing the Date class from section 9.7.4 ("const member functions")
// Programming: Principles and Practice Using C++

#include "../../std_lib_facilities.h"

// define Month type as an enumeration
enum class Month{
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

// define Invalid class for throwing exceptions
class Invalid {};

// Date class using const member functions
class Date{
public:
    Date(int y, Month m, int d);    // check validity and initialise
    Date();                         // default constructor
    // default copy operator is fine

    // non-modifying operations:
    int day() const {return d; }
    Month month() const {return m; }
    int year() const {return y; }


    // modifying operations
    void add_day(int n);    // increase the date by n days
    void add_month(int n);  // increase date by n months
    void add_year(int y);   // increase date by n years

private:
    int y;      // year
    Month m;
    int d;      // day of the month
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


bool leapyear(int y)
{
    // see exercise 10
    return false;
}

Date::Date(int yy, Month mm, int dd)
     :y{yy}, m{mm}, d{dd}
{ 
    if(! is_date(yy, mm, dd)) throw Invalid{};
}

const Date& default_date()
{
    static Date dd{2001, Month::jan, 1};    // start of the 21st century
    return dd;
}

Date::Date()
     :y{default_date().year()},
     m{default_date().month()},
     d{default_date().day()}
{
}

void Date::add_day(int n)
{
    d+=n;
    if(! is_date(y, m, d)) throw Invalid{};
}

void Date::add_month(int n)
{
    // ...
}

void Date::add_year(int n)
{
    if(m==Month::feb && d==29 && !leapyear(y + n)){
        m = Month::mar;
        d = 1;
    }
    y += n;
}

void f()
{
    // initialise dates
    Date today{1978, Month::jun, 25};
    Date tomorrow{1978, Month::jun, 25};

    tomorrow.add_day(1);

    // print out both dates
    cout << "Today is: " << today << '\n';
    cout << "Tomorrow is: " << tomorrow << '\n';

    // let's try an invalid Date
    // exception will be thrown
    // Date invalid_date{2002, Month::feb, 10};
    // invalid_date.add_day(20);

}

int main()
{
    f();

    return 0;
}