// This class as well as the helper functions were the result
// of exercise 6 from the book

// Author: Bernardo Alves

//------------------------------------------------------------------------------
#include "Roman_int.h"

//------------------------------------------------------------------------------
// check if given string represents a Roman numeral
bool is_roman(string numeral)
{
    try{
        int value = thousands(numeral);
        if(value>0) return true;
    }
    catch(exception& e){
        return false;
    }
}

// member functions
Roman_int::Roman_int()
{    
}

Roman_int::Roman_int(string n)
          :numeral{n}, value{thousands(n)}
{
    if(! is_roman(n)) throw Invalid{};
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