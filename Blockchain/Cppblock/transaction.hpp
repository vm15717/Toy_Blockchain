#include <iostream>
#include <cstdlib>
#include <string>
#include "account.hpp"
#include <ctime>

class Transaction
{
    private:
        Account &from_account;
        Account &to_account;
        double amount;
        time_t timestamp;
        std::string status;
        int transaction_id;

    public:
        Transaction(Account &from_account_, Account &to_account_, double amount_): 
        from_account(from_account_), to_account(to_account_), amount(amount_)
        {
            if (amount < 0)
            {
                std::cout << "Amount has to be positive > 0!!" << std::endl;
                status = "Failed";
                return;
            }
            if ((from_account.getbalance() - amount) < 0) 
            {
                std::cout << "Amount cannot be transferred!!! Account doesnt have sufficient balance!!" << std::endl;
                status = "Failed";
                return;
            }
            from_account.Withdraw(amount);
            to_account.Deposit(amount);
            status = "Completed";
            transaction_id = rand();
            time(&timestamp);
        }

        friend std::ostream &operator << (std::ostream &out, Transaction &tx)
        {
            out << "Transaction from: " << tx.from_account.getname();
            out << ", to: " << tx.to_account.getname()<< "\n";
            out << "Amount: " << tx.amount;
            out << ", Status: "<< tx.status;
            out << ", Transaction Id: "<< tx.transaction_id;
            out << ", Timestamp: "<< ctime(&tx.timestamp) << "\n";
            return out;
        }
};