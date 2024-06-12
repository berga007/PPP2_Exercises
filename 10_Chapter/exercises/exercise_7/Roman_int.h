// header file for declaring Roman_int class
#include "../../../std_lib_facilities.h"

//------------------------------------------------------------------------------
const string one_thousand{'M'};
const string two_thousand{"MM"};
const string three_thousand{"MMM"};

//------------------------------------------------------------------------------
const string one_hundred{"C"};
const string two_hundred{"CC"};
const string three_hundred{"CCC"};
const string four_hundred{"CD"};
const string five_hundred{"D"};
const string six_hundred{"DC"};
const string seven_hundred{"DCC"};
const string eight_hundred{"DCCC"};
const string nine_hundred{"CM"};

//------------------------------------------------------------------------------
const string ten{"X"};
const string twenty{"XX"};
const string thirty{"XXX"};
const string forty{"XL"};
const string fifty{"L"};
const string sixty{"LX"};
const string seventy{"LXX"};
const string eighty{"LXXX"};
const string ninety{"XC"};

//------------------------------------------------------------------------------
const string one{"I"};
const string two{"II"};
const string three{"III"};
const string four{"IV"};
const string five{"V"};
const string six{"VI"};
const string seven{"VII"};
const string eight{"VIII"};
const string nine{"IX"};

//------------------------------------------------------------------------------
const string prompt{">>>"};

class Invalid{};    // For throwing exceptions

class Roman_int{
public:
    Roman_int();                        // default constructor
    Roman_int(string n);
    int as_int() const {return value; }  // return the integer value
    // return the string representation
    string get_numeral() const {return numeral; }   
    void update_value(string s);

private:
    string numeral{""};   // numeral representation e.g. VIII
    int value{0};         // numeric equivalent of the numeral                          
};

//------------------------------------------------------------------------------
// helper function declaration

int thousands(const string&);

bool is_roman(string );

istream& operator>>(istream& , Roman_int& );

ostream& operator<<(ostream&, Roman_int& );
