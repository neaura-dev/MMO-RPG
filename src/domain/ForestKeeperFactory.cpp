#include "ForestKeeperFactory.hpp"

std::unique_ptr<Knight> ForestKeeperFactory::create_knight() const {
    return std::make_unique<Ent>();
}

std::unique_ptr<Archer> ForestKeeperFactory::create_archer() const {
    return std::make_unique<Centaur>();
}

std::unique_ptr<Mage> ForestKeeperFactory::create_mage() const {
    return std::make_unique<Druid>();
}