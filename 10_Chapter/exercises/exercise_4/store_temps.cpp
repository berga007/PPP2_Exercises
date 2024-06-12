// Exercise 4 from Chapter 10 from the book
// Programming: Principles and Practice using C++

// Goal: modify previous store_temps.cpp source file to have
// temperature readings in both Celsius and Fahrenheit

#include "../../../std_lib_facilities.h"

// define Invalid class for throwing exceptions
class Invalid {};

class Reading{              // a temperature Reading
public:
    Reading(int hour, double temp, char unit);
    Reading();  // default constructor

    void update_hour(int hour);         // update the hour of the reading
    void update_temperature(double t);  // update temperature
    void update_unit(char ch);          // update the temperature unit

    // non-modifying operations:
    int hour() const {return h; }
    double temperature() const {return t; }
    char unit() const {return u; }  

private:
    int h{};        // hour after midnight [0:23]
    double t{};     // Temperature in Fahrenheit
    char u{};       // Unit: C- Celsius, F Fahrenheit
};

const string prompt{">>>"};

constexpr char Celsius{'C'};
constexpr char Fahrenheit{'F'};
constexpr double abs_zero{-273.15};

// helper functions
bool is_reading(int hour, double t, char unit)
{
    // hour must be in [0, 23]
    if(hour<0 || 23<hour) return false;

    // Only Celsius and Fahrenheit temperatures are allowed
    switch (unit)
    {
    case Celsius: case Fahrenheit:
        break;
    
    default:
        return false;
    }

    // temperature cannot be lower than 0 Kelvin
    if(unit==Fahrenheit){
        t = (t-32)/1.8;
    }
    if(t<abs_zero) return false;

    // all members are valid
    return true;
}

Reading::Reading(int hour, double temp, char unit)
        :h{hour}, t{temp}, u{unit}
{
    // check Reading validity after initialising
    if(! is_reading(hour, temp, unit)) throw Invalid{}; 
}

const Reading& default_reading()
{
    static Reading reading{0, abs_zero, Celsius};    // start of the day with 0 K
    return reading;
}

// member-functions of Reading Class
Reading::Reading()
        :h{default_reading().hour()},
        t{default_reading().temperature()},
        u{default_reading().unit()}
{
}

void Reading::update_hour(int hour)
{
    h = hour;
    if(! is_reading(h, t, u)) throw Invalid{};
}

void Reading::update_temperature(double temperature)
{
    t = temperature;
    if(! is_reading(h, t, u)) throw Invalid{};
}

void Reading::update_unit(char ch)
{
    u = ch;
    if(! is_reading(h, t, u)) throw Invalid{};
}

// operator overloading
istream& operator>>(istream& is, Reading& r)
// read a temperature Reading
// format: hour(int) temperature(double)
{
    int h{};
    double t{};
    char unit{};
    is >> h >> t >> unit;

    // operation failed, return the stream
    if(!is) return is;

    // update the temperature Reading
    // note: each update function will check for validity
    r.update_hour(h);
    r.update_temperature(t);
    r.update_unit(unit);

    return is;
}

ostream& operator<<(ostream &os, Reading& r)
// write a temperature Reading
{
    return os << r.hour() << '\t' << r.temperature() << '\t' << r.unit();
}

void skip_to_reading()
{
    if(cin.fail()){
        cin.clear();
        for(char ch; cin >> ch; ){
            if(isdigit(ch) || ch == '-'){
                cin.unget();    // put digit back,
                                // so that the number can be read
                return;
            }
        }
    }
    // either eof or bad: giver up
    error("no input");
}

Reading get_reading()
{
    Reading r{};
    while(true){
        if(cin >> r) return r;
        cout << "Sorry, that was not a temperature Reading, please try again\n"
             << prompt;
        skip_to_reading();
    }
}

// check the stream state, if bad or fail throw an exception
void end_of_loop(istream& ist, const string& message)
{
    if(ist.fail() || ist.bad()){
        ist.clear();
        char ch{};
        if(cin >> ch) error(message);
        // if ist cannot read a character, then eof has been reached
    }
}

int main()
{   
    // name of output file
    string oname{"raw_temps.txt"};
    vector<Reading>temps;   // store the readings here
    cout << "<<<Please enter temperature readings\n"
         << "<<<hour" << '\t' << "temperatue [F] or [C]\n"
         << prompt;

    // input loop to read from cin
    for(Reading r{}; cin>>r; ){
        temps.push_back(r);
        cout << prompt;
    }

    // check why cin is not good
    // if eof, all is good
    string message{"Bad termination of cin"};
    end_of_loop(cin, message);

    ofstream ofs{oname};
    if(!ofs) error("can't open output file, ", oname);

    for(int i=0; i<temps.size(); ++i){
        ofs << temps[i] << '\n';
    }
}