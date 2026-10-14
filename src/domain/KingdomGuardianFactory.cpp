#include "KingdomGuardianFactory.hpp"

std::unique_ptr<Knight> KingdomGuardianFactory::create_knight(int pos_x, int pos_y) const {
    return std::make_unique<Paladin>(pos_x, pos_y);
}

std::unique_ptr<Archer> KingdomGuardianFactory::create_archer(int pos_x, int pos_y) const {
    return std::make_unique<CrossbowMan>(pos_x, pos_y);
}

std::unique_ptr<Mage> KingdomGuardianFactory::create_mage(int pos_x, int pos_y) const {
    return std::make_unique<Cleric>(pos_x, pos_y);
}