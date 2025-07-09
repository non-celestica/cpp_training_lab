#include "knight.h"
#include <cstdio>

void Knight::setKnightStats(const std::string& n, int h, int s, int a) {
    // TODO-4: Knight modify name, hp, stamina via setFighterStats, try access 'name', 'hp' and 'stamina' directly
    setFighterStats(n, h, s);
    armor = a;
}

void Knight::attack() {
    printf("Knight %s charges with armor %d!\n", name.c_str(), armor);
}

int Knight::getArmor() const {
    return armor;
}

void Knight::showStatus() const {
    // TODO-3: Fighter access hp through getHP(), change it to access 'hp' directly (as well as 'stamina')
    int myHP = getHP();
    int myStamina = getStamina();
    printf("Knight: %s, HP: %d stamina: %d armor: %d\n", name.c_str(), myHP, myStamina, armor);
}
