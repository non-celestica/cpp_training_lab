#ifndef MAGE_H
#define MAGE_H

#include "unit.h"

class Mage : public Unit {
protected:
    int mana;

public:
    Mage() {}
    ~Mage() {};

    void setMageStats(const std::string& n, int h, int m);
    void attack();
    int getMana() const { return mana; }
    void showStatus() const;
    UnitType getType() { return UnitType::UNIT_TYPE_MAGE; }
};

#endif
