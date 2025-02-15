#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount() : m_accountHolder("Name"), m_accountNumber(0), m_balance(0.0) {}

BankAccount::BankAccount(const std::string& holder, int number, double initialBalance)
    : m_accountHolder(holder), m_accountNumber(number), m_balance(initialBalance) {}

BankAccount::BankAccount(const BankAccount& other)
    : m_accountHolder(other.m_accountHolder), m_accountNumber(other.m_accountNumber), m_balance(other.m_balance) {}

BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this != &other) {
        m_accountHolder = other.m_accountHolder;
        m_accountNumber = other.m_accountNumber;
        m_balance = other.m_balance;
    }
    return *this;
}

BankAccount::~BankAccount() {
    std::cout << "Account " << m_accountNumber << " is being destroyed." << std::endl;
}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        m_balance += amount;
    }
}

bool BankAccount::withdraw(double amount) {
    if (amount <= m_balance && amount > 0) {
        m_balance -= amount;
        return true;
    }
    return false;
}

void BankAccount::display() const {
    std::cout << "Account Holder: " << m_accountHolder << ", Account Number: " << m_accountNumber
              << ", Balance: " << m_balance << std::endl;
}

int BankAccount::getAccountNumber() const {
    return m_accountNumber;
}