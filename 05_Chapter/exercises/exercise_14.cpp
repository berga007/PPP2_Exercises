// read day of the week - value pairs
// exercise 14 from chapter 05
#include "../../std_lib_facilities.h"

int main()
{
    vector <vector<string>> week_days = {}; // vector to hold mon-sun vectors

    // declaring a vector to hold all usr given values
    // idx 0 will have a vector with all integers for monday
    // idx 1 will have a vector with all integers for tuesday
    // ...
    // idx 6 will have a vector with all integers for sunday

    vector <vector<int>> values = {{}, {}, {}, {}, {}, {}, {} };  

    // for each day of the week, all allowable names
    vector <string> monday = {
        "Mon", "Monday", "mon", "monday"
    };
    vector <string> tuesday = {
        "Tue", "Tuesday", "tue", "tuesday"
    };
    vector <string> wednesday = {
        "Wed", "Wednesday", "wed", "wednesday"
    };
    vector <string> thursday = {
        "Thu", "Thursday", "thu", "thursday"
    };
    vector <string> friday = {
        "Fri", "Friday", "fri", "friday"
    };
    vector <string> saturday = {
        "Sat", "Saturday", "sat", "saturday"
    };
    vector <string> sunday = {
        "Sun", "Sunday", "sun", "sunday"
    };

    // vector of string vectors:
    // idx 0 (monday) has all equivalent names for monday
    // idx 1 (tuesday) has all equivalent names for tuesday
    // ...
    //idx 6 has all equivalent names for sunday
    week_days = {
        monday, tuesday, wednesday, thursday, friday, saturday, sunday
    };

    bool reject; // will be false if value is stored, true otherwise
    int reject_count = 0;   // counter of rejected values

    while(cin){
        string day_of_week = " ";   // initialising name of the week var
                                    // to read user input
        int value = 0;  // initialising the value var to hold user input

        reject = true;
        cin >> day_of_week >> value;
 
        for(int i=0; i<week_days.size(); ++i)
        {
            for(int j=0; j<week_days[i].size(); ++j)
            {
                if(day_of_week == week_days[i][j]){
                    values[i].push_back(value);
                    reject = false;
                }
            }
        }
        if(reject == true) ++reject_count;
    }

    vector <int> sum_of_values = {}; // vector will have for each day of the week
                                     // the sum of values
                                     // e.g sum_of_values[0] has the sum of all monday
                                     // values
    
    int sum;

    for(vector<int> v:values){
        sum = 0;
        for(int n:v){
            sum += n;
        }
        sum_of_values.push_back(sum);
    }

    for(int i=0; i<week_days.size(); ++i)
    {
        cout << week_days[i][1] << " values are: \n";
        for(int num:values[i])
        {
            cout << num << '\n';
        }
        cout << "And the sum is: "
             << sum_of_values[i]
             << '\n'; 
    }

    cout << "In total, " << reject_count << " were rejected.";
}