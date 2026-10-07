#include "Unit.hpp"

Unit::Unit(int pos_x, int pos_y, Health health, Armor armor, Attack attack)
    : pos_x_(pos_x), pos_y_(pos_y),
    health_(health), armor_(armor), attack_(attack) {}

int Unit::pos_x() const { return pos_x_; }
int Unit::pos_y() const { return pos_y_; }
Health Unit::health() const { return health_; }
Armor Unit::armor() const { return armor_; }
Attack Unit::attack() const { return attack_; }

void Unit::change_pos(int pos_x, int pos_y) {
    pos_x_ = pos_x;
    pos_y_ = pos_y;
}