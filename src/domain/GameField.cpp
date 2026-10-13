#include <stdexcept>
#include <algorithm>
#include "GameField.hpp"
#include "GameFieldIterator.hpp"

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
    units_.resize(static_cast<size_t>(width_ * height_));
}

GameField::~GameField() {
    clear();
}

GameField::GameField(const GameField& other)
    : width_(other.width_), height_(other.height_),
    max_units_(other.max_units_), size_(other.size_){
    units_.reserve(other.units_.size());
    for (const auto& unit : other.units_) {
        if (unit) {
            units_.push_back(unit->clone());
        }
        else {
            units_.push_back(nullptr);
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
    }
    return *this;
}

GameField::GameField(GameField&& other) noexcept
    : width_(other.width_), height_(other.height_),
    max_units_(other.max_units_), size_(other.size_),
    units_(std::move(other.units_)) {
    other.width_ = 0;
    other.height_ = 0;
    other.max_units_ = 0;
    other.size_ = 0;
}

GameField& GameField::operator=(GameField&& other) noexcept {
    if (this != & other) {
        width_ = other.width_;
        height_ = other.height_;
        max_units_ = other.max_units_;
        size_ = other.size_;
        units_ = std::move(other.units_);
        other.width_ = 0;
        other.height_ = 0;
        other.max_units_ = 0;
        other.size_ = 0;
    }
    return *this;
}

int GameField::width() const { return width_; }
int GameField::height() const { return height_; }
int GameField::max_units() const { return max_units_; }
size_t GameField::size() const { return size_; }
const std::vector<std::unique_ptr<Unit>>& GameField::units() const { return units_; }

void GameField::add_unit(std::unique_ptr<Unit> unit) {
    if (size_ >= max_units_) {
        throw std::out_of_range("GameField: units are already full");
    }
    if (unit->pos_x() >= width_ || unit->pos_y() >= height_) {
        throw std::out_of_range("GameField: unit position is out of range");
    }
    if (units_[unit->pos_y() * width_ + unit->pos_x()] != nullptr) {
        throw std::logic_error("GameField: cell is already occupied");
    }
    units_[unit->pos_y() * width_ + unit->pos_x()] = std::move(unit);
    size_++;
}

void GameField::remove_unit(int pos_x, int pos_y) {
    if (pos_x < 0 || pos_x >= width_) {
        throw std::invalid_argument("GameField: pos_x is out of range");
    }
    if (pos_y < 0 || pos_y >= height_) {
        throw std::invalid_argument("GameField: pos_y is out of range");
    }
    if (units_[pos_y * width_ + pos_x] != nullptr) {
        units_[pos_y * width_ + pos_x].reset();
        size_--;
    }
}

Unit* GameField::get_unit(int pos_x, int pos_y) const {
    if (pos_x < 0 || pos_x >= width_) {
        throw std::invalid_argument("GameField: pos_x is out of range");
    }
    if (pos_y < 0 || pos_y >= height_) {
        throw std::invalid_argument("GameField: pos_y is out of range");
    }
    if (units_[pos_y * width_ + pos_x] == nullptr) {
        return nullptr;
    }
    return units_[pos_y * width_ + pos_x].get();
}

bool GameField::empty() const { return size_ == 0; }

void GameField::clear() {
    for (auto& unit : units_) {
        unit.reset();
    }
    size_ = 0;
}

GameFieldIterator GameField::begin() {
    return GameFieldIterator(this, 0, 0);
}

GameFieldIterator GameField::end() {
    return GameFieldIterator(this, 0, height_);
}