#include "CrossbowMan.hpp"

CrossbowMan::CrossbowMan(int pos_x, int pos_y)
    : Archer(pos_x, pos_y), type_(UnitType::KingdomGuardian) {}

UnitType CrossbowMan::type() const { return type_; }

std::unique_ptr<Unit> CrossbowMan::clone() const {
    return std::make_unique<CrossbowMan>(*this);
}