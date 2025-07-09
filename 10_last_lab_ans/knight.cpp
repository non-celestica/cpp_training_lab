#include "knight.h"
#include <cstdio>

void Knight::setKnightStats(const std::string& n, int h, int s, int a) {
    name = n;
    hp = h;
    stamina = s;
    armor = a;
}

void Knight::attack() {
    printf("Knight %s charges with armor %d!\n", name.c_str(), armor);
}

int Knight::getArmor() const {
    return armor;
}

void Knight::showStatus() const {
    printf("Knight: %s, HP: %d stamina: %d armor: %d\n", name.c_str(), hp, stamina, armor);
}
