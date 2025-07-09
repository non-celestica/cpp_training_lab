#include "mage.h"
#include <cstdio>

void Mage::setMageStats(const std::string& n, int h, int m) {
    name = n;
    hp = h;
    mana = m;
}

void Mage::attack() {
    printf("Mage %s attacks with mana %d!\n", name.c_str(), mana);
}

void Mage::showStatus() const {
    printf("Mage: %s, HP: %d mana: %d\n", name.c_str(), hp, mana);
}