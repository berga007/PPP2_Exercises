// exercise 9 from chapter 8
// Programming: Principles and Practice Using C++

#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------


double compute_index(const vector<double>& v1, const vector<double>& v2){
    double sum{0};
    if(v1.size() != v2.size()) error("The two vectors have different sizes");
    for(int i=0;i<v1.size(); ++i){
        sum += v1[i] * v2[i];
    }

    return sum;
}

int main()
{
    // initialising vectors
    vector <double> price_vector{};
    vector <double> weight_vector{};

    double price{}, weight{};

    // quit character
    const char quit{'q'};
    // ch to save input from cin and see if quit was inserted
    char ch{};

    cout << "Please insert the price weight pairs\n";

    while(true){
        cin.get(ch);
        if(ch == quit) break;
        cin.putback(ch);
        cin >> price >> weight;

        price_vector.push_back(price);
        weight_vector.push_back(weight);
        
        //read the next character (newline is a character)
        cin.get(ch);
    }

    cout << "The index is: " << compute_index(price_vector, weight_vector)
         << '\n';

    return 0;
}