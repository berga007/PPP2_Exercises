// Exercise 4 from Chapter 10 of the book
// Programming: Principles and Practice using C++

// Goal: modify previous temp_stats file to test each temperature
// and save it in Fahrenheit

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
    void convert_to_fahrenheit();       // Convert temperature to Fahrenheit                            

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
// 0 K == -273.15 Celsius
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

void Reading::convert_to_fahrenheit()
{
    // convert the temperature value
    t = t * 9/5 + 32;
    // convert the unit to Fahrenheit
    u = Fahrenheit;
}

// operator overloading
istream& operator>>(istream& is, Reading& r)
// read a temperature Reading
// format: hour(int) temperature(double) unit(char)
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

bool is_even(const int& num){
    if(num%2==0) return true;

    return false;
}

vector<double> get_temperature(const vector<Reading>& readings){
    vector<double> temperatures{};
    for(Reading r: readings){
        temperatures.push_back(r.temperature());
    }
    return temperatures;
}

double mean(const vector<Reading>& readings)
// compute the mean value from a vector of numbers
{
    // get the temperature data
    vector<double> numbers{get_temperature(readings)};

    double sum{0};
    for(int i=0; i<numbers.size(); ++i){
        sum +=numbers[i];
    }
    double mean{sum/numbers.size()};

    return mean;
}

double median(const vector<Reading>& readings)
// calculate the median from a vector of numbers
{
    // get the temperature data
    vector<double> numbers{get_temperature(readings)};

    // 1st order the vector from lower to highest
    sort(numbers.begin(), numbers.end());

    // check number parity
    if(is_even(numbers.size())){
        double middle_1{numbers[numbers.size()/2]};
        double middle_2{numbers[numbers.size()/2] - 1};

        return (middle_1+middle_2)/2;
    }

    return numbers[numbers.size()/2];

}

// check the stream state, if bad or fail throw an exception
void end_of_loop(istream& ist, const string& message)
{
    if(ist.fail()){
        ist.clear();
        char ch{};
        if(ist>>ch) error(message);
        // if ist cannot read a character, then eof has been reached
    }
}

int main()
{
    string prompt{">>>"};

    vector<Reading> temp_readings{};

    // open an input file:
    cout << "<<<Please enter input file name\n"
         << prompt;
    string iname;
    cin >> iname;
    ifstream ifs{iname};
    if(!ifs) error("can't open input file", iname);

    ifs.exceptions(ifs.exceptions()|ios_base::badbit); // throw for bad()

    for(Reading r{}; ifs>>r; ){
        // check unit, convert Celsius to Fahrenheit
        if(r.unit() == Celsius){
            r.convert_to_fahrenheit();
        }
        temp_readings.push_back(r);
    }

    // check why the file state is not good
    string message{"<<<Bad termination of file"};
    end_of_loop(ifs, message);

    cout << "<<<Temperature readings summary:\n"
         << "<<<\tMean\t" << "Median\n"
         << "<<<\t" << mean(temp_readings) << '\t' << median(temp_readings);
}
