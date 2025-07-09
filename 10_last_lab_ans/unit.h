#ifndef UNIT_H
#define UNIT_H

#include <string>

enum UnitType {
    UNIT_TYPE_BASE, 
    UNIT_TYPE_FIGHTER,
    UNIT_TYPE_KNIGHT,
    // TODO-1: Mage and Wizzard need type name
    UNIT_TYPE_MAGE,
    UNIT_TYPE_WIZZARD
};

class Unit {
protected:
    std::string name;
    int hp;
public:
    Unit() {}
    virtual ~Unit() {};

    void setNameHp(const std::string& n, int h);
    virtual void attack() = 0;
    virtual void showStatus() const = 0;
    std::string getName() const { return name; }
    virtual UnitType getType() { return UnitType::UNIT_TYPE_BASE; }
};

#endif
