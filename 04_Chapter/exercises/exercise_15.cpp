// exercise 15 from chapter 4
#include "../../std_lib_facilities.h"

int is_prime(int x){
    vector <int> primes = {2, 3, 5, 7};
    int result = 1; // assume the number to be prime
    for(int i : primes){
        if(x == 1){
            result = 0; // 0 means the number is not prime
            return result;
        }
        else if(x != i && (x % i) == 0){
            result = 0; // 0 means the number is not prime
            return result;
        }
    }
    return result;
}

int main()
{
    vector <int> prime_vector;
    // Initialising a variable to hold the number of primes the program will find
    int number_of_primes = 0;

    int max = 1000; // declaring the max variable
    cout << "This program calculates the first n prime numbers. \n"
         << "Please insert the value of n:\n";

    cin >> number_of_primes;
    
    for(int i = 1; i < max + 1; ++i){
        if(prime_vector.size() >= number_of_primes)
            break;
        else if(is_prime(i) == 1){
            prime_vector.push_back(i);
        }
    }
    cout << "The first " << number_of_primes << " primes are: \n";

    for(int num : prime_vector){
        cout << num << '\n';
    }
}