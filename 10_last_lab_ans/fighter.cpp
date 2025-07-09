#include "fighter.h"
#include <cstdio>

void Fighter::setFighterStats(const std::string& n, int h, int s) {
    name = n;
    hp = h;
    stamina = s;
}

void Fighter::attack() {
    printf("Fighter %s attacks with stamina %d!\n", name.c_str(), stamina);
}

void Fighter::showStatus() const {
    printf("Fighter: %s, HP: %d stamina: %d\n", name.c_str(), hp, stamina);
}