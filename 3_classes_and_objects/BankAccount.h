#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

class BankAccount {
private:
    char ownerName[50];
    double balance;

public:
    void init(const char* name, double initialBalance);
    // TODO-1: create function void deposit(double amount) - add input amount to account's balance
    // TODO-2: create function bool withdraw(double amount) - deduct amount from account's balance if balance has enough amount then return true, otherwise return false
};

#endif // BANK_ACCOUNT_H