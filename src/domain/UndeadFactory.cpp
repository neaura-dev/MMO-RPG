#include "UndeadFactory.hpp"

std::unique_ptr<Knight> UndeadFactory::create_knight(int pos_x, int pos_y) const {
    return std::make_unique<Skeleton>(pos_x, pos_y);
}

std::unique_ptr<Archer> UndeadFactory::create_archer(int pos_x, int pos_y) const {
    return std::make_unique<ShadowArcher>(pos_x, pos_y);
}

std::unique_ptr<Mage> UndeadFactory::create_mage(int pos_x, int pos_y) const {
    return std::make_unique<Necromancer>(pos_x, pos_y);
}