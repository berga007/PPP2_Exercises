// Drills from Ch. 11 Costumising Input andf Output from the book
// Programming: Principles and Practice Using C++

// Author: Bernardo Alves

#include "../../../std_lib_facilities.h"

int main()
{
    int birth_year{1997};
    int age{26};
    int a, b, c, d;
    float num{1234567.89};

    cout << "<<<Birth year:\n"
         << showbase
         << "(Decimal)\t"               << birth_year << '\n' 
         << hex << "(Hexadecimal)\t"    << birth_year << '\n' 
         << oct << "(Octal)\t\t"        << birth_year << '\n'
         << '\n';

    cout << "<<<Age:\n"
         << dec << age << '\n' << ">>>";

    cin >> a >> oct >> b >> hex >> c >> d;
    
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

    cout << "<<<"         << num << '\t'
         << fixed         << num << '\t'
         << scientific    << num << '\n'; 

}