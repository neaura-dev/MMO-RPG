#pragma once

#include "UnitFactory.hpp"
#include "Paladin.hpp"
#include "CrossbowMan.hpp"
#include "Cleric.hpp"

class KingdomGuardianFactory : public UnitFactory {
public:
    std::unique_ptr<Knight> create_knight(int pos_x, int pos_y) const override;
    std::unique_ptr<Archer> create_archer(int pos_x, int pos_y) const override;
    std::unique_ptr<Mage> create_mage(int pos_x, int pos_y) const override;
};