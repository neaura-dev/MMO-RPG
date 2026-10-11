#include "Archer.hpp"

Archer::Archer(int pos_x, int pos_y)
    : Unit(pos_x, pos_y, Health(75), Armor(5), Attack(20)) {}