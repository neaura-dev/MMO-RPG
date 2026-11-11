#include "GameField.hpp"
#include "Logger.hpp"
#include "Unit.hpp"
#include "Terrain.hpp"
#include "NeutralObject.hpp"

#include <algorithm>
#include <limits>
#include <stdexcept>
#include <utility>

GameField::GameField(int width, int height, int max_units)
    : width_(width), height_(height), max_units_(max_units), size_(0) {
    if (width <= 0) {
        throw std::invalid_argument("GameField: width cannot be negative or equal zero");
    }
    if (height <= 0) {
        throw std::invalid_argument("GameField: height cannot be negative or equal zero");
    }
    if (max_units < 0) {
        throw std::invalid_argument("GameField: max_units cannot be negative");
    }
    if (width_ > std::numeric_limits<int>::max() / height_) {
        throw std::length_error("GameField: dimensions are too large");
    }
    const auto cell_count = static_cast<std::size_t>(width_) * static_cast<std::size_t>(height_);
    units_.resize(cell_count);
    terrains_.resize(cell_count, nullptr);
    if (static_cast<std::size_t>(max_units_) > cell_count) {
        max_units_ = static_cast<int>(cell_count);
    }
}

GameField::~GameField() {
    clear();
}

GameField::GameField(const GameField& other)
    : width_(other.width_), height_(other.height_), max_units_(other.max_units_), size_(other.size_) {
    units_.reserve(other.units_.size());
    for (const auto& unit : other.units_) {
        if (unit) {
            units_.push_back(unit->clone());
        } else {
            units_.push_back(nullptr);
        }
    }
    terrains_ = other.terrains_;
    for (const auto& pair : other.neutral_objects_) {
        if (pair.second) {
            neutral_objects_[pair.first] = pair.second->clone();
        }
    }
}

GameField& GameField::operator=(const GameField& other) {
    if (this != &other) {
        GameField temp(other);
        std::swap(width_, temp.width_);
        std::swap(height_, temp.height_);
        std::swap(max_units_, temp.max_units_);
        std::swap(size_, temp.size_);
        std::swap(units_, temp.units_);
        std::swap(terrains_, temp.terrains_);
        std::swap(neutral_objects_, temp.neutral_objects_);
    }
    return *this;
}

GameField::GameField(GameField&& other) noexcept
    : width_(other.width_), height_(other.height_), max_units_(other.max_units_), size_(other.size_),
      units_(std::move(other.units_)), terrains_(std::move(other.terrains_)), neutral_objects_(std::move(other.neutral_objects_)) {
    other.width_ = 0;
    other.height_ = 0;
    other.max_units_ = 0;
    other.size_ = 0;
}

GameField& GameField::operator=(GameField&& other) noexcept {
    if (this != &other) {
        width_ = other.width_;
        height_ = other.height_;
        max_units_ = other.max_units_;
        size_ = other.size_;
        units_ = std::move(other.units_);
        terrains_ = std::move(other.terrains_);
        neutral_objects_ = std::move(other.neutral_objects_);
        other.width_ = 0;
        other.height_ = 0;
        other.max_units_ = 0;
        other.size_ = 0;
    }
    return *this;
}

size_t GameField::index(int x, int y) const {
    return static_cast<std::size_t>(y) * static_cast<std::size_t>(width_) + static_cast<std::size_t>(x);
}

int GameField::width() const { return width_; }
int GameField::height() const { return height_; }
int GameField::max_units() const { return max_units_; }
size_t GameField::size() const { return size_; }
const std::vector<std::unique_ptr<Unit>>& GameField::units() const { return units_; }

void GameField::add_unit(std::unique_ptr<Unit> unit) {
    if (!unit) {
        throw std::invalid_argument("GameField: unit cannot be null");
    }
    if (size_ >= static_cast<std::size_t>(max_units_)) {
        throw std::out_of_range("GameField: units are already full");
    }
    const int x = unit->pos_x();
    const int y = unit->pos_y();
    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        throw std::out_of_range("GameField: unit position is out of range");
    }
    const auto idx = index(x, y);
    if (units_[idx] != nullptr) {
        throw std::logic_error("GameField: cell is already occupied");
    }
    units_[idx] = std::move(unit);
    size_++;
}

void GameField::remove_unit(int pos_x, int pos_y) {
    if (pos_x < 0 || pos_x >= width_ || pos_y < 0 || pos_y >= height_) {
        throw std::invalid_argument("GameField: position is out of range");
    }
    const auto idx = index(pos_x, pos_y);
    if (units_[idx] != nullptr) {
        units_[idx].reset();
        size_--;
    }
}

Unit* GameField::get_unit(int pos_x, int pos_y) {
    if (pos_x < 0 || pos_x >= width_ || pos_y < 0 || pos_y >= height_) {
        return nullptr;
    }
    return units_[index(pos_x, pos_y)].get();
}

const Unit* GameField::get_unit(int pos_x, int pos_y) const {
    if (pos_x < 0 || pos_x >= width_ || pos_y < 0 || pos_y >= height_) {
        return nullptr;
    }
    return units_[index(pos_x, pos_y)].get();
}

void GameField::set_terrain(int x, int y, std::shared_ptr<Terrain> terrain) {
    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        throw std::out_of_range("GameField: terrain position is out of range");
    }
    terrains_[index(x, y)] = terrain;
}

std::shared_ptr<Terrain> GameField::get_terrain(int x, int y) const {
    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        return nullptr;
    }
    return terrains_[index(x, y)];
}

void GameField::add_neutral_object(int x, int y, std::unique_ptr<NeutralObject> obj) {
    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        throw std::out_of_range("GameField: object position is out of range");
    }
    neutral_objects_[{x, y}] = std::move(obj);
}

NeutralObject* GameField::get_neutral_object(int x, int y) const {
    auto it = neutral_objects_.find({x, y});
    return (it != neutral_objects_.end()) ? it->second.get() : nullptr;
}

bool GameField::move_unit(int from_x, int from_y, int to_x, int to_y) {
    if (from_x < 0 || from_x >= width_ || from_y < 0 || from_y >= height_ ||
        to_x < 0 || to_x >= width_ || to_y < 0 || to_y >= height_) {
        return false;
    }
    Unit* unit = get_unit(from_x, from_y);
    if (!unit) {
        return false;
    }
    auto terrain = get_terrain(to_x, to_y);
    if (terrain) {
        if (!terrain->is_passable(*unit)) {
            return false;
        }
        double atk_mod = terrain->get_attack_modifier(*unit);
        double def_mod = terrain->get_defense_modifier(*unit);
        if (atk_mod != 1.0 || def_mod != 1.0) {
            Logger::instance().log("[GAME FIELD](S) Terrain modifiers applied: attack x" + std::to_string(atk_mod) + ", defense x" + std::to_string(def_mod));
        }
    }
    auto idx_from = index(from_x, from_y);
    auto idx_to = index(to_x, to_y);
    if (units_[idx_to] != nullptr) {
        return false;
    }
    units_[idx_to] = std::move(units_[idx_from]);
    unit->change_pos(to_x, to_y);
    return true;
}

void GameField::interact(int x, int y, char interaction_type) {
    Unit* unit = get_unit(x, y);
    NeutralObject* obj = get_neutral_object(x, y);
    if (!unit || !obj) {
        return;
    }
    switch (interaction_type) {
    case '+':
        *unit + *obj;
        break;
    case '-':
        *unit - *obj;
        break;
    case '*':
        *unit * *obj;
        break;
    case '/':
        *unit / *obj;
        break;
    default:
        break;
    }
}

bool GameField::empty() const { return size_ == 0; }

void GameField::clear() {
    for (auto& unit : units_) {
        unit.reset();
    }
    size_ = 0;
    terrains_.clear();
    neutral_objects_.clear();
}

GameField::GameFieldIterator GameField::begin() {
    return GameFieldIterator(units_.begin(), units_.end());
}

GameField::GameFieldIterator GameField::end() {
    return GameFieldIterator(units_.end(), units_.end());
}

GameField::GameFieldIterator::GameFieldIterator(
    std::vector<std::unique_ptr<Unit>>::iterator current,
    std::vector<std::unique_ptr<Unit>>::iterator end)
    : iterator_(current), end_(end) {
    skip_empty();
}

void GameField::GameFieldIterator::skip_empty() {
    while (iterator_ != end_ && !*iterator_) {
        ++iterator_;
    }
}

Unit& GameField::GameFieldIterator::operator*() const {
    return **iterator_;
}

GameField::GameFieldIterator& GameField::GameFieldIterator::operator++() {
    if (iterator_ != end_) {
        ++iterator_;
        skip_empty();
    }
    return *this;
}

GameField::GameFieldIterator GameField::GameFieldIterator::operator++(int) {
    GameFieldIterator old = *this;
    ++(*this);
    return old;
}

bool GameField::GameFieldIterator::operator==(const GameFieldIterator& other) const {
    return iterator_ == other.iterator_;
}

bool GameField::GameFieldIterator::operator!=(const GameFieldIterator& other) const {
    return !(*this == other);
}