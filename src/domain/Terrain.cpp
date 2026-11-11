#include "Terrain.hpp"
#include "Unit.hpp"
#include "Logger.hpp"
#include <string>

// ----- UNIT TYPE GETTER -----

std::string get_unit_name(const Unit& unit) {
    std::string unit_name;
    switch (unit.type()) {
    case UnitType::Knight:
        switch (unit.family()) {
        case UnitFamily::KingdomGuardian:
            unit_name = "Paladin";
            break;

        case UnitFamily::ForestKeeper:
            unit_name = "Ent";
            break;

        case UnitFamily::Undead:
            unit_name = "Skeleton";
            break;

        default:
            break;
        }
        break;

    case UnitType::Archer:
        switch (unit.family()) {
        case UnitFamily::KingdomGuardian:
            unit_name = "Crossbow Man";
            break;

        case UnitFamily::ForestKeeper:
            unit_name = "Centaur";
            break;

        case UnitFamily::Undead:
            unit_name = "Shadow Archer";
            break;
            
        default:
            break;
        }
        break;

    case UnitType::Mage:
        switch (unit.family()) {
        case UnitFamily::KingdomGuardian:
            unit_name = "Cleric";
            break;

        case UnitFamily::ForestKeeper:
            unit_name = "Druid";
            break;

        case UnitFamily::Undead:
            unit_name = "Necromancer";
            break;
            
        default:
            break;
        }
        break;
    
    default:
        break;
    }
    return unit_name;
}

// ----- RUINS -----

double Ruins::get_attack_modifier(const Unit& unit) const {
    if (unit.type() == UnitType::Mage) {
        return 1.4;
    }
    return 1.0;
}

// ----- KINGDOM -----

bool Kingdom::is_passable(const Unit& unit) const {
    if (unit.family() == UnitFamily::Undead) {
        return false;
    }
    return true;
}

double Kingdom::get_attack_modifier(const Unit& unit) const {
    if (unit.family() == UnitFamily::KingdomGuardian) {
        return 1.5;
    }
    return 1.0;
}

double Kingdom::get_defense_modifier(const Unit& unit) const {
    if (unit.family() == UnitFamily::KingdomGuardian) {
        return 1.2;
    }
    return 1.0;
}

// ----- FOREST -----

bool Forest::is_passable(const Unit& unit) const {
    return unit.type() != UnitType::Knight;
}

double Forest::get_attack_modifier(const Unit& unit) const {
    if (unit.family() == UnitFamily::ForestKeeper) {
        return 1.5;
    }
    return 1.0;
}

double Forest::get_defense_modifier(const Unit& unit) const {
    if (unit.type() == UnitType::Archer || unit.family() == UnitFamily::ForestKeeper) {
        return 1.5;
    }
    return 1.2;
}

// ----- GRAVEYARD -----

double Graveyard::get_attack_modifier(const Unit& unit) const {
    if (unit.family() == UnitFamily::Undead) {
        return 1.5;
    }
    return 1.0;
}

double Graveyard::get_defense_modifier(const Unit& unit) const {
    if (unit.family() == UnitFamily::Undead) { 
        return 1.2;
    }
    return 1.0;
}

// ----- TERRAIN PROXY -----
bool TerrainProxy::is_passable(const Unit& unit) const {
    bool passable = real_terrain_->is_passable(unit);
    if (passable) {
        Logger::instance().log("[TERRAIN](S) Terrain is passable for " + get_unit_name(unit) + ".");
    }
    else {
        Logger::instance().log("[TERRAIN](E) Terrain is not passable for " + get_unit_name(unit) + ".");
    }
    return passable;
}

double TerrainProxy::get_attack_modifier(const Unit& unit) const {
    double modifier = real_terrain_->get_attack_modifier(unit);
    if (modifier != 1.0) {
        Logger::instance().log("[TERRAIN](S) " + get_unit_name(unit) + " attack modifier: x" + std::to_string(modifier) + ".");
    }
    return modifier;
}

double TerrainProxy::get_defense_modifier(const Unit& unit) const {
    double modifier = real_terrain_->get_defense_modifier(unit);
    if (modifier != 1.0) {
        Logger::instance().log("[TERRAIN](S) " + get_unit_name(unit) + " defense modifier: x" + std::to_string(modifier) + ".");
    }
    return modifier;
}