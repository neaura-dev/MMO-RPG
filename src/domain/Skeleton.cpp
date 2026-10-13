#include "Skeleton.hpp"

Skeleton::Skeleton(int pos_x, int pos_y)
    : Knight(pos_x, pos_y), type_(UnitType::Undead) {}

UnitType Skeleton::type() const { return type_; }

std::unique_ptr<Unit> Skeleton::clone() const {
    return std::make_unique<Skeleton>(*this);
}