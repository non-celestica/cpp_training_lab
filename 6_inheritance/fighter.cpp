#include "fighter.h"
#include <cstdio>

void Fighter::setFighterStats(const std::string& n, int h, int s) {
    // TODO-2: Fighter modify name and hp via setNameHp, try access 'name' and 'hp' directly
    setNameHp(n, h);
    stamina = s;
}

void Fighter::attack() {
    printf("Fighter %s attacks with stamina %d!\n", name.c_str(), stamina);
}

void Fighter::showStatus() const {
    // TODO-1: Fighter access hp through getHP(), change it to access 'hp' directly
    int myHP = getHP();
    printf("Fighter: %s, HP: %d stamina: %d\n", name.c_str(), myHP, stamina);
}