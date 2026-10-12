#pragma once

#include "UnitFactory.hpp"
#include "Skeleton.hpp"
#include "ShadowArcher.hpp"
#include "Necromancer.hpp"

class UndeadFactory : public UnitFactory {
public:
    std::unique_ptr<Knight> create_knight() const override;
    std::unique_ptr<Archer> create_archer() const override;
    std::unique_ptr<Mage> create_mage() const override;
};