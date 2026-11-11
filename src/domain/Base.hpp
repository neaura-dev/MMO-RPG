#pragma once

#include <vector>
#include <memory>

#include "GameObjectObserver.hpp"
#include "Unit.hpp"

class GameObject;
class UnitFactory;

class Base : public GameObjectObserver {
public:
    Base(int health, int max_units, int defense_level = 1);
    virtual ~Base() = default;

    void on_object_created(GameObject* object) override;
    void on_object_destroyed(GameObject* object) override;

    std::unique_ptr<Unit> create_unit(const UnitFactory& factory, UnitType type, int pos_x, int pos_y);

    void take_damage(int amount);
    void add_resources(int amount);

    int health() const { return health_; }
    int max_units() const { return max_units_; }
    int current_units_count() const { return static_cast<int>(active_objects_.size()); }
    int defense_level() const { return defense_level_; };
    int resources() const { return resources_; };

private:
    int health_;
    int max_units_;
    int defense_level_;
    int resources_;
    std::vector<GameObject*> active_objects_;
};