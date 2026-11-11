#pragma once

#include <memory>

class Unit;

class Terrain {
public:
    virtual ~Terrain() = default;
    
    virtual bool is_passable(const Unit& unit) const = 0;
    virtual double get_attack_modifier(const Unit& unit) const = 0;
    virtual double get_defense_modifier(const Unit& unit) const = 0;
};

class Fields : public Terrain {
public:
    bool is_passable(const Unit& unit) const override { return true; }
    double get_attack_modifier(const Unit& unit) const override { return 1.0; }
    double get_defense_modifier(const Unit& unit) const override { return 1.0; }
};

class Ruins : public Terrain {
public:
    bool is_passable(const Unit& unit) const override { return true; };
    double get_attack_modifier(const Unit& unit) const override;
    double get_defense_modifier(const Unit& unit) const override { return 1.2; }
};

class Kingdom : public Terrain {
public:
    bool is_passable(const Unit& unit) const override;
    double get_attack_modifier(const Unit& unit) const override;
    double get_defense_modifier(const Unit& unit) const override;
};

class Forest : public Terrain {
public:
    bool is_passable(const Unit& unit) const override;
    double get_attack_modifier(const Unit& unit) const override;
    double get_defense_modifier(const Unit& unit) const override;
};

class Graveyard : public Terrain {
public:
    bool is_passable(const Unit& unit) const override { return true; };
    double get_attack_modifier(const Unit& unit) const override;
    double get_defense_modifier(const Unit& unit) const override;
};

class TerrainProxy : public Terrain {
public:
    TerrainProxy(std::shared_ptr<Terrain> terrain) : real_terrain_(terrain) {}

    bool is_passable(const Unit& unit) const override;
    double get_attack_modifier(const Unit& unit) const override;
    double get_defense_modifier(const Unit& unit) const override;

private:
    std::shared_ptr<Terrain> real_terrain_;
};