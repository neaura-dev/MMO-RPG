#include "Base.hpp"
#include "UnitFactory.hpp"
#include "Logger.hpp"

#include <iostream>
#include <algorithm>
#include <stdexcept>

Base::Base(int health, int max_units, int defense_level) :
    health_(health), max_units_(max_units), defense_level_(defense_level), resources_(0) {}

void Base::on_object_created(GameObject* object) {
    if (!object) {
        return;
    }
    if (active_objects_.size() < static_cast<size_t>(max_units_)) {
        active_objects_.push_back(object);
        Logger::instance().log("[BASE](S) New object has been created.");
    }
    else {
        Logger::instance().log("[BASE](E) New object has not been created, too many objects.");
    }
}

void Base::on_object_destroyed(GameObject* object) {
    if (!object) { 
        return;
    }
    auto it = std::find(active_objects_.begin(), active_objects_.end(), object);
    if (it != active_objects_.end()) {
        active_objects_.erase(it);
        Logger::instance().log("[BASE](S) Object has been destoyed.");
    }
}

std::unique_ptr<Unit> Base::create_unit(const UnitFactory& factory, UnitType type, int pos_x, int pos_y) {
    if (active_objects_.size() >= static_cast<size_t>(max_units_)) {
        Logger::instance().log("[BASE](E) New unit has not been created, too many units.");
        return nullptr;
    }
    std::unique_ptr<Unit> new_unit;
    switch (type) {
    case UnitType::Knight:
        new_unit = factory.create_knight(pos_x, pos_y);
        break;

    case UnitType::Archer:
        new_unit = factory.create_archer(pos_x, pos_y);
        break;

    case UnitType::Mage:
        new_unit = factory.create_mage(pos_x, pos_y);
        break;

    default:
        break;
    }
    if (new_unit) {
        new_unit->set_owner_base(this);
        new_unit->attach(this);
    }
    return new_unit;
}

void Base::take_damage(int amount) {
    int actual_damage = std::max(0, amount - defense_level_);
    health_ -= actual_damage;
    if (health_ <= 0) {
        health_ = 0;
    }
}

void Base::add_resources(int amount) {
    if (amount > 0) {
        resources_ += amount;
    }
}