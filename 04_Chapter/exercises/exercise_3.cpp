// exercise 3 from chapter 4

#include "../../std_lib_facilities.h"

int main()
{
    vector <double> distances;  // declaring the distances vector
    cout << "Please insert a set of numbers \n";
    for(double distance; cin >> distance; ) // read into distance
        distances.push_back(distance);  // put into distances vector

    // calculating the total distance
    double sum = 0;
    for(double d: distances){
        sum += d;
    }

    sort(distances);    // sorting all the distances in the vector

    cout << "The total distance is: " << sum << " km \n"
         << "The smallest distance between two neighboring cities is: " << distances[0] << " km \n"
         << "The biggest distance between two neighboring cities is: " << distances[distances.size() - 1] << " km \n"
         << "The mean distance between two neighboring cities is: " << sum/distances.size() << " km \n";

}