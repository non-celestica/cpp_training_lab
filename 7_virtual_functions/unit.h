#ifndef UNIT_H
#define UNIT_H

#include <string>

enum UnitType {
    UNIT_TYPE_BASE, 
    UNIT_TYPE_FIGHTER,
    UNIT_TYPE_KNIGHT
};

// TODO-3: if you have time, please modify class Unit to abstract base class
// Actuall we do not need to create Unit directly, just use it as base class
// let's change attack() and showStatus() to pure virtual functions
class Unit {
protected:
    std::string name;
    const UnitType type;
    int hp;
public:
    Unit(UnitType t=UNIT_TYPE_BASE):type(t) {}
    ~Unit() {};

    void setNameHp(const std::string& n, int h);
    void attack();
    void showStatus() const;
    std::string getName() const { return name; }
    // TODO-2: Modify getType() on this and derived classes to virtual function,
    // so we do not need to have const UnitType type anymore
    UnitType getType() { return type; }
};

#endif
