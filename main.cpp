#include <iostream>
#include "src/prime.hpp"

bool isInteger(const string &str) {
  return all_of(str.begin(), str.end(), [](char c) {
      return isdigit(c);
  });
}

int main() {
    Factorizer factorizer;
    string input;

    do {
        std::cout << "\nEnter a positive integer to get its prime factors ('quit' to exit): ";
        getline(cin, input);

        if (isInteger(input)) {
            cout << "Factors of '" << input << "': ";
            for (auto factor : factorizer.factorize(stoi(input))) {
                std::cout << factor << ' ';
            }
        }
        if (input == "quit") {
            break;
        }
    } while (true);
}
