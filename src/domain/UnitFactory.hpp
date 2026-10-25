#pragma once

#include <memory>
#include "Unit.hpp"

class UnitFactory {
public:
    virtual ~UnitFactory() = default;

    virtual std::unique_ptr<Knight> create_knight(int pos_x, int pos_y) const = 0;
    virtual std::unique_ptr<Archer> create_archer(int pos_x, int pos_y) const = 0;
    virtual std::unique_ptr<Mage> create_mage(int pos_x, int pos_y) const = 0;
};

class KingdomGuardianFactory : public UnitFactory {
public:
    std::unique_ptr<Knight> create_knight(int pos_x, int pos_y) const override;
    std::unique_ptr<Archer> create_archer(int pos_x, int pos_y) const override;
    std::unique_ptr<Mage> create_mage(int pos_x, int pos_y) const override;
};

class ForestKeeperFactory : public UnitFactory {
public:
    std::unique_ptr<Knight> create_knight(int pos_x, int pos_y) const override;
    std::unique_ptr<Archer> create_archer(int pos_x, int pos_y) const override;
    std::unique_ptr<Mage> create_mage(int pos_x, int pos_y) const override;
};

class UndeadFactory : public UnitFactory {
public:
    std::unique_ptr<Knight> create_knight(int pos_x, int pos_y) const override;
    std::unique_ptr<Archer> create_archer(int pos_x, int pos_y) const override;
    std::unique_ptr<Mage> create_mage(int pos_x, int pos_y) const override;
};