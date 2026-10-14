#include <stdexcept>
#include "Unit.hpp"

Unit::Unit(int pos_x, int pos_y, Health health, Armor armor, Attack attack)
    : pos_x_(pos_x), pos_y_(pos_y),
    health_(health), armor_(armor), attack_(attack) {
    if (pos_x < 0) {
        throw std::invalid_argument("Unit: pos_x cannot be negative");
    }
    if (pos_y < 0) {
        throw std::invalid_argument("Unit: pos_y cannot be negative");
    }
}

int Unit::pos_x() const { return pos_x_; }
int Unit::pos_y() const { return pos_y_; }
Health& Unit::health() { return health_; }
const Health& Unit::health() const { return health_; }
const Armor& Unit::armor() const { return armor_; }
const Attack& Unit::attack() const { return attack_; }

void Unit::change_pos(int pos_x, int pos_y) {
    if (pos_x < 0) {
        throw std::invalid_argument("Unit: pos_x cannot be negative");
    }
    if (pos_y < 0) {
        throw std::invalid_argument("Unit: pos_y cannot be negative");
    }
    pos_x_ = pos_x;
    pos_y_ = pos_y;
}