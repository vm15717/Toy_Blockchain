#include <iostream>
#include <unordered_map>
#include "account.hpp"

class Bank
{
    private:
        std::unordered_map <double, Account> accounts;
        std::string bank_id;
        std::string bank_name;
    
    public:

    Bank(std::vector<Account> &accounts_, const std::string &bank_id_, const std::string &bank_name_)
    : bank_id(bank_id_), bank_name(bank_name_) {
        for (auto& acc: accounts_)
        {
            accounts[acc.getID()] = acc;
        }
    }
    
    void addAccount(Account &account)
    {
        accounts[account.getID()] = account;
    }

    Account *GetAccountById(double id)
    {
        auto it = accounts.find(id);
        if (it != accounts.end())
        {
            return &(it->second);
        }
        return nullptr;
    }

    friend std::ostream &operator << (std::ostream &out,const Bank &bank)
    {
        out << "Bank Name: " << bank.bank_name << "\n";
        out << "Bank Id: " << bank.bank_id << "\n";
        out << "Number of Accounts: " << bank.accounts.size() << "\n";
        return out;
    }
};