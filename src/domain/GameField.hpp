#pragma once

#include <memory>
#include <vector>
#include <Unit.hpp>

class GameField {
public:
    GameField(int width, int height);

    ~GameField();

    GameField(const GameField& other);
    GameField& operator=(const GameField& other);

    GameField(GameField&& other) noexcept;
    GameField& operator=(GameField&& other) noexcept;

    int width() const;
    int height() const;
    std::vector<std::unique_ptr<Unit>> units() const;

    int units_count() const;

    void add_unit(std::unique_ptr<Unit>);
    
    void remove_unit(int pos_x, int pos_y);

private:
    int width_;
    int height_;
    std::vector<std::unique_ptr<Unit>> units_;
};