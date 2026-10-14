#include "ForestKeeperFactory.hpp"

std::unique_ptr<Knight> ForestKeeperFactory::create_knight(int pos_x, int pos_y) const {
    return std::make_unique<Ent>(pos_x, pos_y);
}

std::unique_ptr<Archer> ForestKeeperFactory::create_archer(int pos_x, int pos_y) const {
    return std::make_unique<Centaur>(pos_x, pos_y);
}

std::unique_ptr<Mage> ForestKeeperFactory::create_mage(int pos_x, int pos_y) const {
    return std::make_unique<Druid>(pos_x, pos_y);
}