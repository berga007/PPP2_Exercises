// Chapter 04 drill

#include "../std_lib_facilities.h"

int main()
{
    double num = 0.0;   // initialising num variable
    string unit = "";   // initialising the unit string

    double ft_to_meters = 12 * 2.54 * 0.01; // conversion factor from ft to meters
                                            // 1 ft = 12 inch
                                            // 1 in = 2.54 cm
                                            // 1 cm = 0.01 m

    vector <double> numbers;    //declaring a numbers vector to store all numbers inserted
    double sum = 0;     // initialising a variable to keep track of the sum
    int i = 0;  // loop variable

    while(cin >> num){
        cin >> unit;        // store the unit of the numbered entered
        
        cout << "The value entered was " << num << " " << unit << '\n';

        if(unit == "cm"){
            numbers.push_back(num);     // store num into vector nums
            numbers[i] *= 0.01;     // convert centimeters to meters
        }
        else if(unit == "in"){
            numbers.push_back(num);     // store num into vector nums
            numbers[i] *= 0.0254;   // convert inches to meters
        }
        else if(unit == "ft"){
            numbers.push_back(num);     // store num into vector nums
            numbers[i] *= ft_to_meters;
            
        }
        else if(unit == "m")
            numbers.push_back(num);     // if value is given in meters,
                                        // no need to convert
        else{
            cout << "Unknown unit: " << unit << '\n';
            numbers.push_back(0);
        }
        
        if(numbers.size() != 1){
            sum += numbers[i];
            sort(numbers);      // sort the numbers introduced from lower to higher
            double smallest = numbers[0];
            double largest = numbers[numbers.size() - 1];

            double absolute_diff = abs(numbers[i] - numbers[i-1]);  // calculate absolute difference
                                                                    // between both numbers
            cout << "The smallest value so far is " << smallest << " m" << '\n';  
            cout << "The biggest value so far is " << largest << " m" << '\n';
        }
        else{
            sum += numbers[0];
        }
        
        cout << "The sum so far is: " << sum << '\n'
             << "The total number of values entered is: " << numbers.size() << '\n';

        for(double number: numbers) cout << number << '\n';

        ++i;
    }
}