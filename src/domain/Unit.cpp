#include "Unit.hpp"

#include <memory>

// ----- UNIT -----
Unit::Unit(int pos_x, int pos_y, Health health, Armor armor, Attack attack) :
    GameObject(pos_x, pos_y, health, armor, attack) {}

// ----- TYPES -----
Knight::Knight(int pos_x, int pos_y) : Unit(pos_x, pos_y, Health(100), Armor(10), Attack(10)) {}

Archer::Archer(int pos_x, int pos_y) : Unit(pos_x, pos_y, Health(75), Armor(5), Attack(20)) {}

Mage::Mage(int pos_x, int pos_y) : Unit(pos_x, pos_y, Health(150), Armor(5), Attack(15)) {}

// ----- KINGDOM GUARDIANS -----
Paladin::Paladin(int pos_x, int pos_y) : Knight(pos_x, pos_y) {}
std::unique_ptr<Unit> Paladin::clone() const { return std::make_unique<Paladin>(*this); }

CrossbowMan::CrossbowMan(int pos_x, int pos_y) : Archer(pos_x, pos_y) {}
std::unique_ptr<Unit> CrossbowMan::clone() const { return std::make_unique<CrossbowMan>(*this); }

Cleric::Cleric(int pos_x, int pos_y) : Mage(pos_x, pos_y) {}
std::unique_ptr<Unit> Cleric::clone() const { return std::make_unique<Cleric>(*this); }

// ----- FOREST KEEPERS -----
Ent::Ent(int pos_x, int pos_y) : Knight(pos_x, pos_y) {}
std::unique_ptr<Unit> Ent::clone() const { return std::make_unique<Ent>(*this); }

Centaur::Centaur(int pos_x, int pos_y) : Archer(pos_x, pos_y) {}
std::unique_ptr<Unit> Centaur::clone() const { return std::make_unique<Centaur>(*this); }

Druid::Druid(int pos_x, int pos_y) : Mage(pos_x, pos_y) {}
std::unique_ptr<Unit> Druid::clone() const { return std::make_unique<Druid>(*this); }

// ----- UNDEADS -----
Skeleton::Skeleton(int pos_x, int pos_y) : Knight(pos_x, pos_y) {}
std::unique_ptr<Unit> Skeleton::clone() const { return std::make_unique<Skeleton>(*this); }

ShadowArcher::ShadowArcher(int pos_x, int pos_y) : Archer(pos_x, pos_y) {}
std::unique_ptr<Unit> ShadowArcher::clone() const { return std::make_unique<ShadowArcher>(*this); }

Necromancer::Necromancer(int pos_x, int pos_y) : Mage(pos_x, pos_y) {}
std::unique_ptr<Unit> Necromancer::clone() const { return std::make_unique<Necromancer>(*this); }