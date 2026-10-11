#include "Centaur.hpp"

Centaur::Centaur(int pos_x, int pos_y)
    : Archer(pos_x, pos_y), type_(UnitType::ForestKeeper) {}

UnitType Centaur::type() const { return type_; }