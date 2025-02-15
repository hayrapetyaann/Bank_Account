#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {
private:
    std::string m_accountHolder;
    int m_accountNumber;
    double m_balance;

public:
    BankAccount();
    BankAccount(const std::string& holder, int number, double initialm_Balance);
    BankAccount(const BankAccount& other);
    BankAccount& operator=(const BankAccount& other);
    ~BankAccount();

    void deposit(double amount);
    bool withdraw(double amount);
    int getAccountNumber() const;
    void display() const;
};

#endif
