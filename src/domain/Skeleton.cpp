#include "Skeleton.hpp"

Skeleton::Skeleton(int pos_x, int pos_y)
    : Knight(pos_x, pos_y), type_(UnitType::Undead) {}

UnitType Skeleton::type() const { return type_; }