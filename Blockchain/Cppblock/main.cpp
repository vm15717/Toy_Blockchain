#include <iostream>
//#include "account.hpp"
#include "transaction.hpp"

int main() {
    Account acc1("Alice", 1001, 500.0, "Savings", "USD");
    std::cout << acc1;
    acc1.Withdraw(50);
    std::cout << acc1;
    Account acc2("Bob", 1002, 40.0, "Savings", "USD");
    Transaction tx1(acc1, acc2, 50);
    std::cout << tx1;
    return 0;
}