#include "Ent.hpp"

Ent::Ent(int pos_x, int pos_y)
    : Knight(pos_x, pos_y), type_(UnitType::ForestKeeper) {}

UnitType Ent::type() const { return type_; }