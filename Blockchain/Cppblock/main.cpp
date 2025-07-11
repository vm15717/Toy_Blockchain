#include <iostream>
#include "account.hpp"

int main() {
    Account acc("Alice", 1001, 500.0, "Savings", "USD");
    std::cout << acc;
    return 0;
}