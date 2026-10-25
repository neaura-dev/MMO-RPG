#include <stdexcept>
#include "Unit.hpp"

// Unit class

Unit::Unit(int pos_x, int pos_y, Health health, Armor armor, Attack attack)
    : pos_x_(pos_x), pos_y_(pos_y),
    health_(health), armor_(armor), attack_(attack) {
    if (pos_x < 0) {
        throw std::invalid_argument("Unit: pos_x cannot be negative");
    }
    if (pos_y < 0) {
        throw std::invalid_argument("Unit: pos_y cannot be negative");
    }
}

int Unit::pos_x() const { return pos_x_; }
int Unit::pos_y() const { return pos_y_; }
Health& Unit::health() { return health_; }
const Health& Unit::health() const { return health_; }
const Armor& Unit::armor() const { return armor_; }
const Attack& Unit::attack() const { return attack_; }

void Unit::change_pos(int pos_x, int pos_y) {
    if (pos_x < 0) {
        throw std::invalid_argument("Unit: pos_x cannot be negative");
    }
    if (pos_y < 0) {
        throw std::invalid_argument("Unit: pos_y cannot be negative");
    }
    pos_x_ = pos_x;
    pos_y_ = pos_y;
}

// Knight Unit

Knight::Knight(int pos_x, int pos_y)
    : Unit(pos_x, pos_y, Health (100), Armor(10), Attack(10)) {}

// Archer Unit

Archer::Archer(int pos_x, int pos_y)
    : Unit(pos_x, pos_y, Health(75), Armor(5), Attack(20)) {}

// Mage Unit

Mage::Mage(int pos_x, int pos_y)
    : Unit(pos_x, pos_y, Health(150), Armor(5), Attack(15)) {}

// Kingdom Guardians

Paladin::Paladin(int pos_x, int pos_y)
    : Knight(pos_x, pos_y), type_(UnitType::KingdomGuardian) {}

UnitType Paladin::type() const { return type_; }

std::unique_ptr<Unit> Paladin::clone() const {
    return std::make_unique<Paladin>(*this);
}

CrossbowMan::CrossbowMan(int pos_x, int pos_y)
    : Archer(pos_x, pos_y), type_(UnitType::KingdomGuardian) {}

UnitType CrossbowMan::type() const { return type_; }

std::unique_ptr<Unit> CrossbowMan::clone() const {
    return std::make_unique<CrossbowMan>(*this);
}

Cleric::Cleric(int pos_x, int pos_y)
    : Mage(pos_x, pos_y), type_(UnitType::KingdomGuardian) {}

UnitType Cleric::type() const { return type_; }

std::unique_ptr<Unit> Cleric::clone() const {
    return std::make_unique<Cleric>(*this);
}

// Forest Keepers

Ent::Ent(int pos_x, int pos_y)
    : Knight(pos_x, pos_y), type_(UnitType::ForestKeeper) {}

UnitType Ent::type() const { return type_; }

std::unique_ptr<Unit> Ent::clone() const {
    return std::make_unique<Ent>(*this);
}

Centaur::Centaur(int pos_x, int pos_y)
    : Archer(pos_x, pos_y), type_(UnitType::ForestKeeper) {}

UnitType Centaur::type() const { return type_; }

std::unique_ptr<Unit> Centaur::clone() const {
    return std::make_unique<Centaur>(*this);
}

Druid::Druid(int pos_x, int pos_y)
    : Mage(pos_x, pos_y), type_(UnitType::ForestKeeper) {}

UnitType Druid::type() const { return type_; }

std::unique_ptr<Unit> Druid::clone() const {
    return std::make_unique<Druid>(*this);
}

// Undeads

Skeleton::Skeleton(int pos_x, int pos_y)
    : Knight(pos_x, pos_y), type_(UnitType::Undead) {}

UnitType Skeleton::type() const { return type_; }

std::unique_ptr<Unit> Skeleton::clone() const {
    return std::make_unique<Skeleton>(*this);
}

ShadowArcher::ShadowArcher(int pos_x, int pos_y)
    : Archer(pos_x, pos_y), type_(UnitType::Undead) {}

UnitType ShadowArcher::type() const { return type_; }

std::unique_ptr<Unit> ShadowArcher::clone() const {
    return std::make_unique<ShadowArcher>(*this);
}

Necromancer::Necromancer(int pos_x, int pos_y)
    : Mage(pos_x, pos_y), type_(UnitType::Undead) {}

UnitType Necromancer::type() const { return type_; }

std::unique_ptr<Unit> Necromancer::clone() const {
    return std::make_unique<Necromancer>(*this);
}