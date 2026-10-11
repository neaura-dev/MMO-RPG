#include "CrossbowMan.hpp"

CrossbowMan::CrossbowMan(int pos_x, int pos_y)
    : Archer(pos_x, pos_y), type_(UnitType::KingdomGuardian) {}

UnitType CrossbowMan::type() const { return type_; }