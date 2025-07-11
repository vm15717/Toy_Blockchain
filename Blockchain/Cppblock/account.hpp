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