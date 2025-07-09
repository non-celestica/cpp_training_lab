#ifndef WIZZARD_H
#define WIZZARD_H

#include "mage.h"

class Wizzard : public Mage {
private:
    int spirit;

public:
    Wizzard() {}
    ~Wizzard() {};

    void setWizzardStats(const std::string& n, int h, int m, int s);
    void attack();
    int getSpirit() const {return spirit;};
    void showStatus() const;
    UnitType getType() { return UnitType::UNIT_TYPE_WIZZARD; }
};

#endif
