// Exercise 6 from Chapter 10 of the book
// Programming: Principles and Practice using C++ by Bjarne Stroustrup

// Goal: Define a Roman_int class for holding roman numerals (as ints)

/*
    Author: Bernardo Alves

    The grammar for Roman_int input is:

    Roman_int:
        Thousands
    Thousands:
        'M'
        "MM"
        "MMM"
        Hundreds
        Thousands Hundreds
    Hundreds:
        below_five_or_nine_hundred
        between_five_eight_hundred
        Tens
        Hundreds Tens
    below_five_or_nine_hundred:
        'C'
        "CC"
        "CCC"
        "CD"
        "CM"
    between_five_eight_hundred:
        "D"
        "DC"
        "DCC"
        "DCCC"
    Tens:
        below_fifty_or_ninety
        between_fifty_eighty
        Units
        Tens Units
    below_fifty_or_ninety:
        'X'
        "XX"
        "XXX"
        "XL"
        "XC"
    between_fifty_eighty:
        'L'
        "LX"
        "LXX"
        "LXXX"
    Units:
        below_five_or_nine
        between_five_eight
    below_five_or_nine:
        'I'
        "II"
        "III"
        "IV"
        "IX"
    between_five_eight:
        'V'
        "VI"
        "VII"
        "VIII"

    Roman Numeral Digit:
    I -> 1
    V -> 5
    X -> 10
    L -> 50
    C -> 100
    D -> 500
    M -> 1000

*/

#include "../../../std_lib_facilities.h"

//------------------------------------------------------------------------------
constexpr int max_occurrences{4};

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
unordered_map<string, int> roman_numerals{
    {one_thousand, 1000},
    {two_thousand, 2000},
    {three_thousand, 3000},
    {one_hundred, 100},
    {two_hundred, 200},
    {three_hundred, 300},
    {four_hundred, 400},
    {five_hundred, 500},
    {six_hundred, 600},
    {seven_hundred, 700},
    {eight_hundred, 800},
    {nine_hundred, 900},
    {ten, 10},
    {twenty, 20},
    {thirty, 30},
    {forty, 40},
    {fifty, 50},
    {sixty, 60},
    {seventy, 70},
    {eighty, 80},
    {ninety, 90},
    {one, 1},
    {two, 2},
    {three, 3},
    {four, 4},
    {five, 5},
    {six, 6},
    {seven, 7},
    {eight, 8},
    {nine, 9}
};

//------------------------------------------------------------------------------
const string prompt{">>>"};

class Invalid{};    // For throwing exceptions

class Roman_int{
public:
    Roman_int();                        // default constructor
    int as_int() const {return value; }  // return the integer value
    // return the string representation
    string get_numeral() const {return numeral; }   
    void update_value(string s);

private:
    string numeral{""};   // numeral representation e.g. VIII
    int value{0};         // numeric equivalent of the numeral                          
};

//------------------------------------------------------------------------------
// helper functions

// Parser functions

double below_five_or_nine(int& i, const string& roman_numeral)
{
    string message{"More than 3 consecutive occurrences of one letter were found"};
    int sum{roman_numerals[one]};
    ++i;
    while(true){
        // retrieve the character and convert to string
        string s{roman_numeral[i]};

        // we have reached the end of the numeral after reading one
        if(i == roman_numeral.size()){
            return sum;
        }
        // "IV" == 5-1
        else if(s==five){
            if(sum!=roman_numerals[one]) error("IIV is invalid");
            ++i;
            return roman_numerals[four];
        }
        // Another "I" has been found
        else if(s==one){
            sum += roman_numerals[one];
            if(sum > roman_numerals[three]) error(message);
            ++i;
        }
        // "IX"
        else if(s==ten){
            if(sum!=roman_numerals[one]) error("IIX is invalid");
            ++i;
            return roman_numerals[nine];
        }
        else{
            error("Unexpected character ", roman_numeral[i]);
        }
    }
}

double between_five_eight(int& i, const string& roman_numeral)
{
    string message{"More than 3 consecutive occurrences of one letter were found"};
    int sum{roman_numerals[five]};
    ++i;
    while(true){
        // retrieve the character and convert to string
        string s{roman_numeral[i]};

        // we have reached the end of the numeral
        if(i==roman_numeral.size()) return sum;

        if(s==one){
            sum += roman_numerals[one];
            if(sum > roman_numerals[eight]) error(message);
            ++i;
        }
        // Units
        else{
            error("Unexpected character ", roman_numeral[i]);
        }
    }
}

double units(int& i, const string& roman_numeral)
{
    int sum{0};
    while(true){
        // we have reached the end of the roman numeral
        if(i==roman_numeral.size()) return sum;
        
        // retrieve the character and convert to string
        string s{roman_numeral[i]};

        if(s==one){
            sum += below_five_or_nine(i, roman_numeral);
        }
        else if(s==five){
            sum += between_five_eight(i, roman_numeral);
        }
        else{
            error("Unexpected character ", roman_numeral[i]);
        }
    }
}

//------------------------------------------------------------------------------
double below_fifty_or_ninety(int& i, const string& roman_numeral)
{
    string message{"More than 3 consecutive occurrences of one letter were found"};
    int sum{roman_numerals[ten]};
    ++i;
    while(true){
        // retrieve the character and convert to string
        string s{roman_numeral[i]};

        // we have reached the end of the numeral after reading ten
        if(i == roman_numeral.size()){
            return sum;
        }
        // "XL" == 50-10
        else if(s==fifty){
            if(sum!=roman_numerals[ten]) error("XXL is invalid");
            ++i;
            return roman_numerals[forty];
        }
        // Another "X" has been found
        else if(s==ten){
            sum += roman_numerals[ten];
            if(sum > roman_numerals[thirty]) error(message);
            ++i;
        }
        // "XC"
        else if(s==one_hundred){
            if(sum!=roman_numerals[ten]) error("XXC is invalid");
            ++i;
            return roman_numerals[ninety];
        }
        // Units
        else{
            return sum+units(i, roman_numeral);
        }
    }
}

double between_fifty_eighty(int& i, const string& roman_numeral)
{
    string message{"More than 3 consecutive occurrences of one letter were found"};
    int sum{roman_numerals[fifty]};
    ++i;
    while(true){
        // retrieve the character and convert to string
        string s{roman_numeral[i]};

        // we have reached the end of the numeral
        if(i==roman_numeral.size()) return sum;

        if(s==ten){
            sum += roman_numerals[ten];
            if(sum > roman_numerals[eighty]) error(message);
            ++i;
        }
        // Units
        else{
            return sum+units(i, roman_numeral);
        }
    }
}

double tens(int& i, const string& roman_numeral)
{
    int sum{0};
    while(true){
        // we have reached the end of the roman numeral
        if(i==roman_numeral.size()) return sum;

        // retrieve the character and convert to string
        string s{roman_numeral[i]};

        if(s==ten){
            sum += below_fifty_or_ninety(i, roman_numeral);
        }
        else if(s==fifty){
            sum += between_fifty_eighty(i, roman_numeral);
        }
        // Units
        else{
            return sum + units(i, roman_numeral);
        }
    }
}

//------------------------------------------------------------------------------
// a "C" has been found
double below_five_or_nine_hundred(int& i, const string& roman_numeral)
{
    string message{"More than 3 consecutive occurrences of one letter were found"};
    int sum{roman_numerals[one_hundred]};
    ++i;
    while(true){
        // retrieve the character and convert to string
        string s{roman_numeral[i]};

        // we have reached the end of the numeral after reading one_hundred
        if(i == roman_numeral.size()){
            return sum;
        }
        // "CD" == 500-100
        else if(s==five_hundred){
            if(sum!=roman_numerals[one_hundred]) error("CCD is invalid");
            ++i;
            return roman_numerals[four_hundred];
        }
        // Another "C" has been found
        else if(s==one_hundred){
            sum += roman_numerals[one_hundred];
            if(sum > roman_numerals[three_hundred]) error(message);
            ++i;
        }
        else if(s==one_thousand){
            if(sum!=roman_numerals[one_hundred]) error("CCM is invalid");
            ++i;
            return roman_numerals[nine_hundred];
        }
        // Tens or Units
        else{
            return sum+tens(i, roman_numeral);
        }
    }
}

// "D" has been found
double between_five_eight_hundred(int& i, const string& roman_numeral)
{
    string message{"More than 3 consecutive occurrences of one letter were found"};
    int sum{roman_numerals[five_hundred]};
    ++i;
    while(true){
        // retrieve the character and convert to string
        string s{roman_numeral[i]};

        // we have reached the end of the numeral
        if(i==roman_numeral.size()) return sum;

        if(s==one_hundred){
            sum += roman_numerals[one_hundred];
            if(sum > roman_numerals[eight_hundred]) error(message);
            ++i;
        }
        // Tens or Units
        else{
            return sum+tens(i, roman_numeral);
        }
    }
}

double hundreds(int& i, const string& roman_numeral)
{
    int sum{0};
    while(true){
        // we have reached the end of the roman numeral
        if(i==roman_numeral.size()) return sum;

        // retrieve the character and convert to string
        string s{roman_numeral[i]};

        if(s==one_hundred){
            sum += below_five_or_nine_hundred(i, roman_numeral);
        }
        else if(s==five_hundred){
            sum += between_five_eight_hundred(i, roman_numeral);
        }
        // Tens
        else{
            return sum + tens(i, roman_numeral);
        }
    }
}

//------------------------------------------------------------------------------
double thousands(const string& roman_numeral)
{
    int sum{0};
    for(int i=0; i<roman_numeral.size(); ++i){
        // retrieve the character and convert to string
        string s{roman_numeral[i]};

        if(s==one_thousand){
            sum += roman_numerals[one_thousand];
            if(sum > roman_numerals[three_thousand]){
                string message{
                    "More than 3 consecutive occurrences of one letter were found"
                };
                error(message);
            }
        }
        // Hundreds
        else{
            return sum + hundreds(i, roman_numeral);
        }
    }
    // we have reached the end of the roman numeral
    return sum;
}

//------------------------------------------------------------------------------
// check if given string represents a Roman numeral
bool is_roman(string numeral)
{
    int value = thousands(numeral);
    if (value>0) return true;

    return false;
}

// member functions
Roman_int::Roman_int()
{    
}
void Roman_int::update_value(string s)
{
    numeral = s;
    // parse the numeral string and store its numeric value
    value = thousands(numeral);
}

// operator overloading
istream& operator>>(istream& is, Roman_int& r){
    string numeral{""};
    is >> numeral;
    if(!is) return is;

    r.update_value(numeral);
    return is;
}

ostream& operator<<(ostream& os, Roman_int& r)
{
    return os << "<<<" << r.get_numeral() << "== " << r.as_int();
}

int main()
{
    cout << "<<<Please enter a Roman numeral:\n"
         << prompt;

    Roman_int r{};
    cin >> r;

    cout << r;
}