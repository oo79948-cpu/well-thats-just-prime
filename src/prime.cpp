#include "prime.hpp"

#include <cmath>

using namespace std;

vector<bool> Factorizer::sieveOfEratosthenes(int n) {
   vector<bool> primes(n + 1, true);

   primes[0] = false;
   primes[1] = false;
   for (int i = 2; i <= sqrt(n); i++) {
      if (primes[i]) {
         for (int j = i*i; j <= sqrt(n); j += i) {
            primes[j] = false;
         }
      }
   }

   return primes;
}

vector<int> Factorizer::getAllPrimes(int n) {
   vector<int> primes;

   auto sieve = sieveOfEratosthenes(n);
   for (int i = 0; i <= n; i++) {
      if (sieve[i]) {
         primes.push_back(i);
      }
   }
   return primes;
}

vector<int> Factorizer::factorize(int n) {
   // 1. get all primes for number n
   // 2. for each prime P in allPrimes try n mod P == 0
   // 3. if true add P to the primeFactors, and repeat 2. for n = n/P
   // 4. stop if the n is just a number in allPrimes

   vector<int> primeFactors;

   if (n > 1) {

      vector<int> allPrimes = getAllPrimes(n);

      for (auto i : allPrimes) {
          while (n % i == 0) {
            primeFactors.push_back(i);
            n = n / i;
         }
      }
   }
   return primeFactors;
}

bool Factorizer::isPrime(int number) {
   Factorizer factorizer;
   return factorizer.factorize(number).size() == 1;
}

bool Factorizer::isComposite(int number) {
   return number > 1 and !isPrime(number);
}

