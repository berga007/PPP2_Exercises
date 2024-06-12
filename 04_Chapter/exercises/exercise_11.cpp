// exercise 11 from chapter 4
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
  for(int i = 1; i < 101; ++i){
  if(is_prime(i) == 1){
      prime_vector.push_back(i);
  }
  }
  cout << "List of primes found between 1 and 100:\n";

  for(int num : prime_vector){
  cout << num << '\n';
  }
}