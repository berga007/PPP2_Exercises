// exercise 13 from chapter 4
// Compute prime numbers using method 'Sieve of Eratosthenes'
#include "../../std_lib_facilities.h"
int main()
{
    // vector with numbers between 1 and 100
    vector <int> all_numbers;
    for(int i = 1; i < 101; ++i){
        all_numbers.push_back(i);
    }
    // declaring vector to store all non-prime numbers
    vector <int> not_primes;

    // declare vector with the primes 2, 3, 5 and 7
    vector <int> aux_primes = {2, 3, 5, 7};

    // declare vector to contain all primes found in all_numbers
    vector <int> all_primes;

    // check non-prime numbers
    for(int num : aux_primes){
        for(int x : all_numbers){
            if(x == 1){
                not_primes.push_back(x);
            }
            else if(x % num == 0 && x >= (num*num)){
                not_primes.push_back(x);
            }
        }
    }

    //list of primes can be found by comparing both vectors
    for(int a : all_numbers){
        // initialising aux variable. If it remains 0 after the next loop
        // then a is prime
        int aux = 0;
        for(int b : not_primes){
            if(a == b){
                aux = 1;
            }
        }
        if(aux == 0)
            all_primes.push_back(a);
    }

    cout << "The prime numbers between 1 and 100 are\n";
    for(int m : all_primes){
        cout << m << '\n'; 
    }

}