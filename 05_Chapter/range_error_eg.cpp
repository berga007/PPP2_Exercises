// this program contains an example of a range error
#include "../std_lib_facilities.h"

int main()
try{
    vector <int> v; //vector of ints
    for(int x; cin >> x; )  
        v.push_back(x); // set values
    for(int i = 0; i <= v.size(); ++i)  // print values
        cout << "v[" << i << "] == " << v[i] << '\n';
} catch (out_of_range) {
    cerr << "Oops! Range error\n";
    return 1;
} catch (...) { // catch all other exceptions
    cerr << "Exception: Something went wrong\n";
    return 2;
}