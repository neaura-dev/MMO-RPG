#pragma once

#include <cstddef>
#include <iterator>

class GameField;
class Unit;

class GameFieldIterator {
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = Unit;
    using difference_type = std::ptrdiff_t;
    using pointer = Unit*;
    using reference = Unit&;

    GameFieldIterator(GameField* field, int x, int y);

    reference operator*() const;
    pointer operator->() const;

    GameFieldIterator& operator++();
    GameFieldIterator operator++(int);

    bool operator==(const GameFieldIterator& other) const;
    bool operator!=(const GameFieldIterator& other) const;

private:
    GameField* field_;
    int x_;
    int y_;

    void skip_empty();
};