#include "NeutralObject.hpp"
#include "GameObject.hpp"
#include "Unit.hpp"
#include "Base.hpp"
#include "Logger.hpp"

#include <string>
#include <cstdlib>

// ----- CHEST -----

void Chest::interact(GameObject* object) {
    if (!object) {
        return;
    }
    Unit* unit = dynamic_cast<Unit*>(object);
    if (!unit) {
        Logger::instance().log("[CHEST](E) Only units can open the chest.");
        return;
    }
    int resources_amount = rand() % 1000;
    Logger::instance().log("[CHEST](S) Chest opened! +" + std::to_string(resources_amount) + " resources.");
    if (unit->get_owner_base()) {
        unit->get_owner_base()->add_resources(resources_amount);
    }
}

std::unique_ptr<NeutralObject> Chest::clone() const {
    return std::make_unique<Chest>(*this);
}

// ----- TRAP -----

void Trap::interact(GameObject* object) {
    if (!object) {
        return;
    }
    Logger::instance().log("[TRAP](S) Trap triggered! Dealing " + std::to_string(damage_) + " damage.");
    object->take_damage(damage_);
}

std::unique_ptr<NeutralObject> Trap::clone() const {
    return std::make_unique<Trap>(*this);
}

// ----- MINES -----

void Mines::interact(GameObject* object) {
    if (!object) {
        return;
    }
    Unit* unit = dynamic_cast<Unit*>(object);
    if (!unit) {
        Logger::instance().log("[MINES](E) Only units can mine resources.");
        return;
    }
    Logger::instance().log("[MINES](S) Mines tapped! +100 resources.");
    if (unit->get_owner_base()) {
        unit->get_owner_base()->add_resources(100);
    }
}

std::unique_ptr<NeutralObject> Mines::clone() const {
    return std::make_unique<Mines>(*this);
}

// ----- ALTAR STRATEGIES -----

void KnightBuffStrategy::apply_effect(Unit* unit) {
    if (!unit) return;
    
    if (unit->type() == UnitType::Knight) {
        Logger::instance().log("[ALTAR](S) Knight receives +20 defense buff.");
        unit->armor().increase(20);
    } else {
        Logger::instance().log("[ALTAR](E) Buff is not effective for this unit type.");
    }
}

std::unique_ptr<AltarStrategy> KnightBuffStrategy::clone() const {
    return std::make_unique<KnightBuffStrategy>(*this);
}

void ArcherBuffStrategy::apply_effect(Unit* unit) {
    if (!unit) return;
    
    if (unit->type() == UnitType::Archer) {
        Logger::instance().log("[ALTAR](S) Archer receives +10 attack buff.");
        unit->attack().increase(10);
    } else {
        Logger::instance().log("[ALTAR](E) Buff is not effective for this unit type.");
    }
}

std::unique_ptr<AltarStrategy> ArcherBuffStrategy::clone() const {
    return std::make_unique<ArcherBuffStrategy>(*this);
}

void MageBuffStrategy::apply_effect(Unit* unit) {
    if (!unit) return;
    
    if (unit->type() == UnitType::Mage) {
        Logger::instance().log("[ALTAR](S) Mage receives +20 health buff.");
        unit->health().increase(20);
    } else {
        Logger::instance().log("[ALTAR](E) Buff is not effective for this unit type.");
    }
}

std::unique_ptr<AltarStrategy> MageBuffStrategy::clone() const {
    return std::make_unique<MageBuffStrategy>(*this);
}

// ----- ALTAR -----

Altar::Altar(const Altar& other) {
    if (other.strategy_) {
        strategy_ = other.strategy_->clone();
    }
}

Altar& Altar::operator=(const Altar& other) {
    if (this != &other) {
        if (other.strategy_) {
            strategy_ = other.strategy_->clone();
        } else {
            strategy_.reset();
        }
    }
    return *this;
}

void Altar::interact(GameObject* object) {
    if (!object) return;

    Unit* unit = dynamic_cast<Unit*>(object);
    if (!unit) {
        Logger::instance().log("[ALTAR](E) Only units can use the altar.");
        return;
    }

    Logger::instance().log("[ALTAR](S) Unit interacts with the Altar of Power.");
    if (strategy_) {
        strategy_->apply_effect(unit);
    }
}

std::unique_ptr<NeutralObject> Altar::clone() const {
    return std::make_unique<Altar>(*this);
}