// Exercise 3 from Chapter 10 of the book
// Programming: Principles and Practice using C++

// Goal: Write a program to read the file of data created by
// exercise 2

#include "../../../std_lib_facilities.h"

struct Reading{             // a temperature Reading
    int hour{};             // hour after midnight [0:23]
    double temperature{};   // Temperature in Fahrenheit
};

bool is_even(const int& num){
    if(num%2==0) return true;

    return false;
}

vector<double> get_temperature(const vector<Reading>& readings){
    vector<double> temperatures{};
    for(Reading r: readings){
        temperatures.push_back(r.temperature);
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

// operator overloading
istream& operator>>(istream& is, Reading& r)
// read a temperature Reading
// format: hour(int) temperature(double)
{
    int h{};
    double t{};
    is >> h >> t;

    // operation failed, return the stream
    if(!is) return is;

    // update the temperature Reading
    r.hour = h;
    r.temperature = t;

    return is;
}

ostream& operator<<(ostream &os, Reading& r)
// write a temperature Reading
{
    return os << r.hour << '\t' << r.temperature;
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
        temp_readings.push_back(r);
    }

    // check why the file state is not good
    string message{"<<<Bad termination of file"};
    end_of_loop(ifs, message);

    cout << "<<<Temperature readings summary:\n"
         << "<<<\tMean\t" << "Median\n"
         << "<<<\t" << mean(temp_readings) << '\t' << median(temp_readings);
}
