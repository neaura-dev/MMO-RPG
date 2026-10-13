#pragma once

#include <memory>
#include <vector>
#include <Unit.hpp>

class GameFieldIterator;

class GameField {
public:
    GameField(int width, int height, int max_units);

    ~GameField();

    GameField(const GameField& other);
    GameField& operator=(const GameField& other);

    GameField(GameField&& other) noexcept;
    GameField& operator=(GameField&& other) noexcept;

    int width() const;
    int height() const;
    int max_units() const;
    size_t size() const;
    const std::vector<std::unique_ptr<Unit>>& units() const;

    void add_unit(std::unique_ptr<Unit> unit);
    
    void remove_unit(int pos_x, int pos_y);

    Unit* get_unit(int pos_x, int pos_y) const;

    bool empty() const;

    void clear();

    GameFieldIterator begin();
    GameFieldIterator end();

    friend class GameFieldIterator;

private:
    int width_;
    int height_;
    int max_units_;
    size_t size_;
    std::vector<std::unique_ptr<Unit>> units_;
};