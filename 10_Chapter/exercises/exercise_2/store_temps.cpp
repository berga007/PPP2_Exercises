// Exercise 2 from Chapter 10 from the book
// Programming: Principles and Practice using C++

// Goal: Write a program to create a file of data with temperature readings
// ref. §10.5 for the Reading Type

#include "../../../std_lib_facilities.h"

struct Reading{             // a temperature Reading
    int hour{};             // hour after midnight [0:23]
    double temperature{};   // Temperature in Fahrenheit
};

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
        cout << "Sorry, that was not a temperature Reading, please try again\n";
        skip_to_reading();
    }
}

// check the stream state, if bad or fail throw an exception
void end_of_loop(istream& ist, const string& message)
{
    if(ist.fail() || ist.bad()){
        ist.clear();
        error(message);
    }
}

int main()
{   
    // name of output file
    string oname{"raw_temps.txt"};
    string prompt{">>>"};
    vector<Reading>temps;   // store the readings here
    cout << "<<<Please enter temperature readings\n"
         << "<<<hour" << '\t' << "temperatue [F]\n"
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