// exercise 11 from chapter 8
// Programming: Principles and Practice Using C++

#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Statistics
{
    int min;
    int max;
    double median;
    double mean;
};

Statistics compute_stats(vector<int>& v1){
    // first lets sort the vector
    sort(v1);
    int min_value{v1[0]};
    int max_value{v1[v1.size()-1]};

    double median{};

    // computing the median
    if(v1.size()%2 == 1){
        int idx = (v1.size() - 1)/2;
        median = v1[idx];
    }
    else{
        int idx = (v1.size()-1)/2;
        median = (v1[idx-1] + v1[idx])/2;
    }

    // computing the mean
    double sum{0}, mean{0};
    for(int num:v1){
        sum += num;
    }

    mean = sum/v1.size();

    return Statistics{min_value, max_value, median, mean};
}

int main()
{
    // the quit character
    const char quit{'q'};
    cout << "Introduce your numerical values\n"
         << "To finish inserting elements introduce 'q'\n";

    // character to read fom cin
    char ch{};

    // vector to store all the elements
    vector <int> v1{};

    // initialising val to read numeric value from cin
    int val{};

    while(true)
    {
        cin.get(ch);
        if(ch == quit) break;
        cin.putback(ch);

        cin >> val;

        v1.push_back(val);

        // read character from cin (newline is a character)
        cin.get(ch);
    }

    Statistics stats_data{compute_stats(v1)};

    cout << "Max value: " << stats_data.max    << '\n'
         << "Min value: " << stats_data.min    << '\n'
         << "Median: "    << stats_data.median << '\n'
         << "Mean: "      << stats_data.mean   << '\n'; 
}
