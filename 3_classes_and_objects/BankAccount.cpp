#include "BankAccount.h"
#include <cstdio>
#include <cstring>
#include <cstdio>

// Definitions of member functions

void BankAccount::init(const char* name, double initialBalance) {
    std::strncpy(ownerName, name, sizeof(ownerName));
    ownerName[sizeof(ownerName) - 1] = '\0'; // ensure null-terminated
    balance = initialBalance;
}
