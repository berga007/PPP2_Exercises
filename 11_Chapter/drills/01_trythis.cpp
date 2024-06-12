// Try This exercise from section 11.2.1- integer Output of the book:
// Programming: Principles and Practice Using C++

// Author: Bernardo Alves

#include "../../std_lib_facilities.h"

int main()
{
    int birth_year{1997};
    int age{26};

    cout << "Birth year:\n"
         << birth_year << "\t(Decimal)\n"
         << hex << birth_year << "\t(Hexadecimal)\n"
         << oct << birth_year << "\t(Octal)\n"
         << "Age:\n"
         << dec << age << "\t(Decimal)\n"
         << hex << age << "\t(Hexadecimal)\n"
         << oct << age << "\t(Octal)\n";
}