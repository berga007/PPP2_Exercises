// This program converts spelled-out numbers into digits

#include "../../std_lib_facilities.h"

int main()
{
    cout << "Please write a number in spelled-out form.\n";
    string num_1{""};
    cin >> num_1;

    if(num_1 == "zero")
        cout << "The number inserted was " << 0 << ".\n";
    
    else
        if(num_1 == "one")
            cout << "The number inserted was " << 1 << ".\n";

        else
            if(num_1 == "two")
                cout << "The number inserted was " << 2 << ".\n";
    
            else
                if(num_1 == "three")
                    cout << "The number inserted was " << 3 << ".\n";

                    else
                        if(num_1 == "four")
                            cout << "The number inserted was " << 4 << ".\n";
    
                        else
                            cout << "Not a number I know.\n";

}