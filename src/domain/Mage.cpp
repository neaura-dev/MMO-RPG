#include "Mage.hpp"

Mage::Mage(int pos_x, int pos_y)
    : Unit(pos_x, pos_y, Health(150), Armor(5), Attack(15)) {}