#ifndef UNIT_H
#define UNIT_H

#include <string>

enum UnitType {
    UNIT_TYPE_BASE, 
    UNIT_TYPE_FIGHTER,
    UNIT_TYPE_KNIGHT
};

class Unit {
protected:
    std::string name;
    const UnitType type;
private:
    int hp;
public:
    Unit(UnitType t=UNIT_TYPE_BASE):type(t) {}
    ~Unit() {};

    void setNameHp(const std::string& n, int h);
    void attack();
    int getHP() const { return hp; }
    void showStatus() const;
    UnitType getType() { return type; }
};

#endif
