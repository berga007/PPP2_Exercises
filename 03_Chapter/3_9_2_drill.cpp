#include "../std_lib_facilities.h"
int main()
{
    cout << "Enter the name of the person you want to write to\n";
    string first_name;      // first_name is a variable of type string
    cin >> first_name;      // read characters into first_name
    cout << "Dear " << first_name << ", \n"
            << "    How are you? I am fine, but I miss you. \n"
            << "    Time is stubborn. It keeps on passing. The weeks turned into months, then into seasons and now into years...\n";
    cout << "Enter the name of another friend\n";
    string friend_name;     // the name of the friend will be stored in a variable of type string
    cin >> friend_name;     // read characters into friend_name
    cout << "Have you seen " << friend_name << " lately?\n";
    char friend_sex{0};     // initialising a char variable with the value 0
    cout << "Enter the character 'f' in case the friend you mentioned is female, or 'm' if is male\n";
    cin >> friend_sex;      // read the sex character and stored it into friend_sex variable

    if(friend_sex == 'f')
        cout << "If you see " << friend_name << " please ask her to call me.\n";

    if(friend_sex == 'm')
        cout << "If you see " << friend_name << " please ask him to call me.\n";
    cout << "Enter the recipient's age\n";
    int age{0};             // initialising the age variable
    cin >> age;             // read the age value into the age variable
    if(age <= 0 || age >= 110)
        simple_error("You're kidding!");

    else
        cout << "I hear you just had a birthday and you are " 
                << age << " years old.\n";
    if(age < 12)
        cout << "Next year you will be " << ++age << " .\n";
    if(age == 17)
        cout << "Next year you will be able to vote.\n";
    if(age >= 70)
        cout << "I hope you are enjoying retirement.\n";

    cout << "Yours sincerely,\n \n"
            << "Bernardo";
}