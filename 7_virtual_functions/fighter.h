#ifndef FIGHTER_H
#define FIGHTER_H

#include "unit.h"

class Fighter : public Unit {
protected:
    int stamina;

public:
    Fighter(UnitType t=UNIT_TYPE_FIGHTER):Unit(t) {}
    ~Fighter() {};

    void setFighterStats(const std::string& n, int h, int s);
    void attack();  // Hides Unit::attack()
    int getStamina() const { return stamina; }
    void showStatus() const;
    UnitType getType() { return type; }
};

#endif
