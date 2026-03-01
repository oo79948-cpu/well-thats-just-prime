#include <vector>

using namespace std;

class Factorizer {
    private:
        vector<bool> sieveOfEratosthenes(int n);
        vector<int> getAllPrimes(int n);
    public:
        vector<int> factorize(int number);
        static bool isPrime(int number);
        static bool isComposite(int number);
};
