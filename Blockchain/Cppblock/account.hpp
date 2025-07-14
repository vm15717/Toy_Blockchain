#pragma once
#include <iostream>
#include <string>

class Account
{
    private:
        std::string name;
        double account_id;
        double balance;
        std::string account_type;
        std::string currency;
    //std::vector<Transaction> Transactions;
    public:
        Account(std::string name_, double account_id_, double balance_, std::string account_type_,
        std::string currency_): name(name_), account_id(account_id_), balance(balance_), account_type(account_type_), currency(currency_)
        {
            if (balance < 0)
            {
                std::cout << "Balance cannot be negative, Setting balance to 0 \n";
                balance = 0;
            }
        }
        
        double getID()
        {
            return account_id;
        }
        double getbalance()
        {
            return balance;
        }
        std::string getname()
        {
            return name;
        }
        void Deposit(const double amount) 
        {
            if (amount <= 0) {
                std::cout << "Invalid deposit amount. Must be greater than 0.\n";
                return;
            }
            balance += amount;
            std::cout << "Amount " << amount << " credited to the account, current balance "<< balance << "\n";
        }

        void Withdraw(const double amount)
        {
            if (amount <= 0) {
                std::cout << "Withdrawal amount must be positive.\n";
                return;
            }
            if ((balance - amount) < 0)
            {
                std::cout << "Do not have sufficient balance!!!, current balance is " << balance << "\n";
                return;
            }
            balance -= amount;
            std::cout << "Amount "<< amount << " withdrawn, current balance is " << balance << "\n"; 
        }

        friend std::ostream &operator << (std::ostream &out, const Account &account)
        {
            out << "Account Name: " << account.name << "\n";
            out << "Account ID: " << account.account_id << "\n";
            out << "Balance: " << account.balance << "\n";
            out << "Account type: " << account.account_type << "\n";
            out << "Account currency: " << account.currency << "\n";
            return out;
        }
};