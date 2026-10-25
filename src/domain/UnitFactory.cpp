#include "UnitFactory.hpp"

std::unique_ptr<Knight> KingdomGuardianFactory::create_knight(int pos_x, int pos_y) const {
    return std::make_unique<Paladin>(pos_x, pos_y);
}

std::unique_ptr<Archer> KingdomGuardianFactory::create_archer(int pos_x, int pos_y) const {
    return std::make_unique<CrossbowMan>(pos_x, pos_y);
}

std::unique_ptr<Mage> KingdomGuardianFactory::create_mage(int pos_x, int pos_y) const {
    return std::make_unique<Cleric>(pos_x, pos_y);
}

std::unique_ptr<Knight> ForestKeeperFactory::create_knight(int pos_x, int pos_y) const {
    return std::make_unique<Ent>(pos_x, pos_y);
}

std::unique_ptr<Archer> ForestKeeperFactory::create_archer(int pos_x, int pos_y) const {
    return std::make_unique<Centaur>(pos_x, pos_y);
}

std::unique_ptr<Mage> ForestKeeperFactory::create_mage(int pos_x, int pos_y) const {
    return std::make_unique<Druid>(pos_x, pos_y);
}

std::unique_ptr<Knight> UndeadFactory::create_knight(int pos_x, int pos_y) const {
    return std::make_unique<Skeleton>(pos_x, pos_y);
}

std::unique_ptr<Archer> UndeadFactory::create_archer(int pos_x, int pos_y) const {
    return std::make_unique<ShadowArcher>(pos_x, pos_y);
}

std::unique_ptr<Mage> UndeadFactory::create_mage(int pos_x, int pos_y) const {
    return std::make_unique<Necromancer>(pos_x, pos_y);
}