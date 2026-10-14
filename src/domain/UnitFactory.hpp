#pragma once

#include <memory>
#include "Knight.hpp"
#include "Archer.hpp"
#include "Mage.hpp"

class UnitFactory {
public:
    virtual ~UnitFactory() = default;

    virtual std::unique_ptr<Knight> create_knight(int pos_x, int pos_y) const = 0;
    virtual std::unique_ptr<Archer> create_archer(int pos_x, int pos_y) const = 0;
    virtual std::unique_ptr<Mage> create_mage(int pos_x, int pos_y) const = 0;
};