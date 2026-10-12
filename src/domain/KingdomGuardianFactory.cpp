#include "KingdomGuardianFactory.hpp"

std::unique_ptr<Knight> KingdomGuardianFactory::create_knight() const {
    return std::make_unique<Paladin>();
}

std::unique_ptr<Archer> KingdomGuardianFactory::create_archer() const {
    return std::make_unique<CrossbowMan>();
}

std::unique_ptr<Mage> KingdomGuardianFactory::create_mage() const {
    return std::make_unique<Cleric>();
}