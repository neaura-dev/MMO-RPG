#include "UndeadFactory.hpp"

std::unique_ptr<Knight> UndeadFactory::create_knight() const {
    return std::make_unique<Skeleton>();
}

std::unique_ptr<Archer> UndeadFactory::create_archer() const {
    return std::make_unique<ShadowArcher>();
}

std::unique_ptr<Mage> UndeadFactory::create_mage() const {
    return std::make_unique<Necromancer>();
}