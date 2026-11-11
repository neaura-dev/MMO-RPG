#pragma once

#include <vector>
#include <memory>
#include <map>
#include <utility>
#include "Unit.hpp"
#include "Terrain.hpp"
#include "NeutralObject.hpp"

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
    Unit* get_unit(int pos_x, int pos_y);
    const Unit* get_unit(int pos_x, int pos_y) const;

    bool empty() const;
    void clear();

    void set_terrain(int x, int y, std::shared_ptr<Terrain> terrain);
    std::shared_ptr<Terrain> get_terrain(int x, int y) const;

    void add_neutral_object(int x, int y, std::unique_ptr<NeutralObject> obj);
    NeutralObject* get_neutral_object(int x, int y) const;

    bool move_unit(int from_x, int from_y, int to_x, int to_y);
    void interact(int x, int y, char interaction_type);

    class GameFieldIterator {
    public:
        GameFieldIterator(std::vector<std::unique_ptr<Unit>>::iterator current,
                          std::vector<std::unique_ptr<Unit>>::iterator end);

        Unit& operator*() const;
        GameFieldIterator& operator++();
        GameFieldIterator operator++(int);
        bool operator==(const GameFieldIterator& other) const;
        bool operator!=(const GameFieldIterator& other) const;

    private:
        void skip_empty();
        std::vector<std::unique_ptr<Unit>>::iterator iterator_;
        std::vector<std::unique_ptr<Unit>>::iterator end_;
    };

    GameFieldIterator begin();
    GameFieldIterator end();

private:
    int width_;
    int height_;
    int max_units_;
    size_t size_;
    std::vector<std::unique_ptr<Unit>> units_;
    
    std::vector<std::shared_ptr<Terrain>> terrains_;
    std::map<std::pair<int, int>, std::unique_ptr<NeutralObject>> neutral_objects_;

    size_t index(int x, int y) const;
};