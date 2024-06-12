// This program converts yen, kroner and pounds to dollars

#include "../std_lib_facilities.h"

int main()
{
    constexpr double yen_in_dollar = 136.63;     // amount of yens in one dollar
    constexpr double kroner_in_dollar = 9.83;   // amount of kroners in one dollar
    constexpr double pound_in_dollar = 0.83;    // amount of pounds in one dollar

    double amount = 0;  // the monetary amount in yen, kroner or pound
    char currency = ' '; // a space is not a currency

    cout << "Please enter the amount followed by the currency.\n"
         << "Currencies accepted include yen, kroner and pounds.\n";
    
    cin >> amount >> currency;

    switch(currency){
    case 'y':
        cout << amount << "y == " << amount/yen_in_dollar << "$\n";
        break;
    case 'k':
        cout << amount << "k == " << amount/kroner_in_dollar << "$\n";
        break;
    case 'p':
        cout << amount << "p == " << amount/pound_in_dollar << "$\n";
        break;
    default:
        cout << "Sorry, I do not have a currency called " << currency << ".\n";
        break;
    }

}
