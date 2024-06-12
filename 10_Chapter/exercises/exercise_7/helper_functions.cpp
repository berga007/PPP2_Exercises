// File contains the definition of the functions needed
// to parse the Roman numerals

// Author: Bernardo Alves

//------------------------------------------------------------------------------
#include "../../../std_lib_facilities.h"
#include "Roman_int.h"

const unordered_map<string, int>& default_roman_numerals()
{
    static const unordered_map<string, int> numerals{
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
    return numerals;
}

//------------------------------------------------------------------------------
// helper functions
// Parser functions

unordered_map<string, int> roman_numerals{default_roman_numerals()};

int below_five_or_nine(int& i, const string& roman_numeral)
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

int between_five_eight(int& i, const string& roman_numeral)
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

int units(int& i, const string& roman_numeral)
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
int below_fifty_or_ninety(int& i, const string& roman_numeral)
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

int  between_fifty_eighty(int& i, const string& roman_numeral)
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

int tens(int& i, const string& roman_numeral)
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
int below_five_or_nine_hundred(int& i, const string& roman_numeral)
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
int between_five_eight_hundred(int& i, const string& roman_numeral)
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

int hundreds(int& i, const string& roman_numeral)
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
int thousands(const string& roman_numeral)
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