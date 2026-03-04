#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include "../src/prime.hpp"

TEST_CASE( "#prime" ) {
    Factorizer primes;

    SECTION("false") {
        REQUIRE_FALSE(false);
    }

    SECTION("prime factors of 0") {
        REQUIRE( primes.factorize(0) == vector<int>({}) );
    }

    SECTION("prime factors of 1") {
        REQUIRE( primes.factorize(1) == vector<int>({}) );
    }


    SECTION("prime factors of 2") {
        REQUIRE( primes.factorize(2) == vector<int>({2}) );
    }

    SECTION("prime factors of 3") {
        REQUIRE( primes.factorize(3) == vector<int>({3}) );
    }

    SECTION("prime factors of 4") {
        REQUIRE( primes.factorize(4) == vector<int>({2, 2}) );
    }

    SECTION("prime factors of 9") {
        REQUIRE( primes.factorize(9) == vector<int>({3, 3}) );
    }

    SECTION("prime factors of 2548") {
        REQUIRE( primes.factorize(2548) == vector<int>({2, 2, 7, 7, 13}) );
    }

    SECTION("prime factors of 4116") {
        REQUIRE(primes.factorize(4116) == vector<int>({2, 2, 3, 7, 7, 7}));
    }

    SECTION("prime factors of 2366") {
        REQUIRE( primes.factorize(2366) == vector<int>({2, 7, 13, 13}) );
    }

    SECTION("5 is prime") {
        REQUIRE(Factorizer::isPrime(5) == true);
    }

    SECTION("5 is not composite") {
        REQUIRE(Factorizer::isComposite(5) == false);
    }

    SECTION("6 is not prime") {
        REQUIRE(Factorizer::isPrime(6) == false);
    }

    SECTION("6 is composite") {
        REQUIRE(Factorizer::isComposite(6) == true);
    }

    SECTION("727 is prime") {
        REQUIRE(Factorizer::isPrime(727) == true);
    }
}
