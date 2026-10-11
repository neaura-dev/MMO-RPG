#include "Druid.hpp"

Druid::Druid(int pos_x, int pos_y)
    : Mage(pos_x, pos_y), type_(UnitType::ForestKeeper) {}

UnitType Druid::type() const { return type_; }