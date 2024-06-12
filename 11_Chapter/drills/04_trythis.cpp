// Try This exercise from section 11.2.5- Fields of the book:
// Programming: Principles and Practice Using C++

// Author: Bernardo Alves

#include "../../std_lib_facilities.h"

int main()
{
    string col_1{"Last Name"};
    string col_2{"First Name"};
    string col_3{"Telephone Number"};
    string col_4{"E-mail"};

    string last_name_1{"Alves"};
    string last_name_2{"Soares"};
    string last_name_3{"Neto"};
    string last_name_4{"Pontes"};
    string last_name_5{"Silva"};

    string first_name_1{"Bernardo"};
    string first_name_2{"Matilde"};
    string first_name_3{"Joana"};
    string first_name_4{"Marta"};
    string first_name_5{"Pedro"};

    string number_1{"918186357"};
    string number_2{"912280761"};
    string number_3{"914549942"};
    string number_4{"961900378"};
    string number_5{"933478634"};

    string e_mail_1{"email01@gmail.com"};
    string e_mail_2{"email02@hotmail.com"};
    string e_mail_3{"email03@shark.com"};
    string e_mail_4{"email04@outlook.com"};
    string e_mail_5{"email05@gmail.com"};

    cout << '\n'    << setw(9)  << col_1        << '|' << setw(10) << col_2 
         << '|'     << setw(16) << col_3        << '|' << setw(19) << col_4 
         << '\n'    << setw(9)  << last_name_1  << '|' << setw(10) << first_name_1
         << '|'     << setw(16) << number_1     << '|' << setw(19) << e_mail_1
         << '\n'    << setw(9)  << last_name_2  << '|' << setw(10) << first_name_2
         << '|'     << setw(16) << number_2     << '|' << setw(19) << e_mail_2
         << '\n'    << setw(9)  << last_name_3  << '|' << setw(10) << first_name_3
         << '|'     << setw(16) << number_3     << '|' << setw(19) << e_mail_3
         << '\n'    << setw(9)  << last_name_4  << '|' << setw(10) << first_name_4
         << '|'     << setw(16) << number_4     << '|' << setw(19) << e_mail_4
         << '\n'    << setw(9)  << last_name_5  << '|' << setw(10) << first_name_5
         << '|'     << setw(16) << number_5     << '|' << setw(19) << e_mail_5
         << '\n'    << '\n';
}