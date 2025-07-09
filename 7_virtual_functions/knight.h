#ifndef KNIGHT_H
#define KNIGHT_H

#include "fighter.h"

class Knight : public Fighter {
private:
    int armor;

public:
    Knight(UnitType t=UNIT_TYPE_KNIGHT):Fighter(t) {}
    ~Knight() {};

    void setKnightStats(const std::string& n, int h, int s, int a);
    void attack();  // Hides Fighter::attack()
    int getArmor() const;
    void showStatus() const;
    UnitType getType() { return type; }
};

#endif
