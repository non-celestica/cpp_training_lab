#include "wizzard.h"
#include <cstdio>

void Wizzard::setWizzardStats(const std::string& n, int h, int m, int s) {
    name = n;
    hp = h;
    mana = m;
    spirit = s;
}

void Wizzard::attack() {
    printf("Wizzard %s attack with mana %d and spirit: %d power!\n", name.c_str(), mana, spirit);
}

void Wizzard::showStatus() const {
    printf("Wizzard: %s, HP: %d mana: %d spirit: %d\n", name.c_str(), hp, mana, spirit);
}
