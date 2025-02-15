#include "BankSystem.h"
#include <iostream>

void BankSystem::addAccount(const std::string& name, int accountNumber, double initialBalance) {
    BankAccount newAccount(name, accountNumber, initialBalance);
    m_accounts.push_back(newAccount);
}

BankAccount* BankSystem::findAccount(int accountNumber) {
    for (auto& account : m_accounts) {
        if (accountNumber == account.getAccountNumber()) {
            return &account;
        }
    }
    return nullptr;
}

void BankSystem::transferFunds(int senderAcc, int receiverAcc, double amount) {
    BankAccount* sender = findAccount(senderAcc);
    BankAccount* receiver = findAccount(receiverAcc);
    if (sender && receiver && sender->withdraw(amount)) {
        receiver->deposit(amount);
    }
}

void BankSystem::displayAllAccounts() const {
    for (const auto& account : m_accounts) {
        account.display();
    }
}
