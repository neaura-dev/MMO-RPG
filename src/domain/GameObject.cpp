#include "GameObject.hpp"
#include "GameObjectObserver.hpp"
#include "NeutralObject.hpp"
#include "Logger.hpp"

#include <memory>
#include <algorithm>
#include <stdexcept>
#include <iostream>

GameObject::GameObject(int pos_x, int pos_y, Health health, Armor armor, Attack attack) :
    pos_x_(pos_x), pos_y_(pos_y), health_(health), armor_(armor), attack_(attack) {
    if (pos_x < 0) {
        throw std::invalid_argument("GameObject: pos_x cannot be negative");
    }
    if (pos_y < 0) { 
        throw std::invalid_argument("GameObject: pos_y cannot be negative");
    }
}

GameObject::~GameObject() {
    Logger::instance().log("[GAME OBJECT](S) Destructor called for object at (" +
        std::to_string(pos_x_) + ", " + std::to_string(pos_y_) + ").");
    for (GameObjectObserver* observer : observers_) {
        if (observer) {
            observer->on_object_destroyed(this);
        }
    }
}

void GameObject::change_pos(int pos_x, int pos_y) {
    if (pos_x < 0) throw std::invalid_argument("GameObject: pos_x cannot be negative");
    if (pos_y < 0) throw std::invalid_argument("GameObject: pos_y cannot be negative");
    pos_x_ = pos_x;
    pos_y_ = pos_y;
}

void GameObject::attach(GameObjectObserver* observer) {
    if (!observer) {
        return;
    }
    auto it = std::find(observers_.begin(), observers_.end(), observer);
    if (it == observers_.end()) {
        observers_.push_back(observer);
        observer->on_object_created(this);
    }
}

void GameObject::detach(GameObjectObserver* observer) {
    if (!observer) {
        return;
    }
    auto it = std::find(observers_.begin(), observers_.end(), observer);
    if (it != observers_.end()) {
        observers_.erase(it);
    }
}

void GameObject::operator+(NeutralObject& object) { object.interact(this); }
void GameObject::operator-(NeutralObject& object) { object.interact(this); }
void GameObject::operator*(NeutralObject& object) { object.interact(this); }
void GameObject::operator/(NeutralObject& object) { object.interact(this); }

void GameObject::take_damage(int amount) {
    if (amount < 0) {
        throw std::invalid_argument("GameObject::take_damage: amount cannot be negative");
    }
    int actual_damage = std::max(0, armor_.reduce_damage(Attack(amount)));
    health_.decrease(actual_damage);
    Logger::instance().log("[GAME OBJECT](S) Object at (" + std::to_string(pos_x_) +
        ", " + std::to_string(pos_y_) + ") took " + std::to_string(actual_damage) +
        " damage.");
}