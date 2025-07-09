#include "unit.h"
#include <cstdio>

void Unit::setNameHp(const std::string& n, int h) {
    name = n;
    hp = h;
}

void Unit::attack() {
    printf("Unit %s attacks with base power!\n", name.c_str());
}

void Unit::showStatus() const {
    printf("Unit: %s, HP: %d\n", name.c_str(), hp);
}
