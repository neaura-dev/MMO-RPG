#include <iostream>
#include <memory>
#include <utility>
#include "domain/GameField.hpp"
#include "domain/KingdomGuardianFactory.hpp"
#include "domain/ForestKeeperFactory.hpp"
#include "domain/UndeadFactory.hpp"

void print_field(const GameField& field) {
    std::cout << "Units on field: " << field.size() << std::endl;
    for (int y = 0; y < field.height(); ++y) {
        for (int x = 0; x < field.width(); ++x) {
            const Unit* unit = field.get_unit(x, y);
            if (unit != nullptr) {
                std::cout << "Unit at (" << x << ", " << y << ")" << 
                ", health" << unit->health().value() << std::endl;
            }
        }
    }
}

void demonstarate_factories() {
    std::cout << std::endl << "=== Factories use ===" << std::endl;
    GameField field(3, 3, 9);
    KingdomGuardianFactory kingdom_guardian_factory;
    ForestKeeperFactory forest_keeper_factory;
    UndeadFactory undead_factory;
    field.add_unit(kingdom_guardian_factory.create_knight(0, 0));
    field.add_unit(forest_keeper_factory.create_archer(1, 0));
    field.add_unit(undead_factory.create_mage(2, 0));

    print_field(field);
}

void demonstrate_copy_and_move() {
    std::cout << std::endl << "=== GameField copy and move ===" << std::endl;
    GameField field(3, 3, 9);
    KingdomGuardianFactory kingdom_guardian_factory;
    field.add_unit(kingdom_guardian_factory.create_knight(0, 0));
    field.add_unit(kingdom_guardian_factory.create_archer(1, 0));
    std::cout << "Field: " << std::endl;
    print_field(field);
    GameField copied_field = field;
    std::cout << std::endl << "Copied field: " << std::endl;
    print_field(copied_field);
    Unit* unit = field.get_unit(0, 0);
    Unit* copied_unit = copied_field.get_unit(0, 0);
    if(unit != nullptr && copied_unit != nullptr) {
        std::cout << std::endl << "Different objects: "
        << std::boolalpha << (unit != copied_unit) << std::endl;
    }
    copied_unit->health().decrease(10);
    std::cout << "Health of first unit after changing health of copy: "
    << unit->health().value() << std::endl;
    std::cout << "Health of copy: "
    << copied_unit->health().value() << std::endl;
    GameField moved_field = std::move(copied_field);
    std::cout << std::endl << "Moved field:" << std::endl;
    print_field(moved_field);
}

void demonstrate_iterator() {
    std::cout << std::endl << "=== Iterator use ===" << std::endl;
    GameField field(3, 3, 9);
    KingdomGuardianFactory kingdom_guardian_factory;
    ForestKeeperFactory forest_keeper_factory;
    UndeadFactory undead_factory;
    field.add_unit(kingdom_guardian_factory.create_knight(0, 0));
    field.add_unit(kingdom_guardian_factory.create_archer(1, 0));
    field.add_unit(forest_keeper_factory.create_mage(2, 0));
    field.add_unit(undead_factory.create_knight(0, 1));
    std::cout << "Initial field:" << std::endl;
    print_field(field);
    std::cout << std::endl << "Iterating over units:" << std::endl;
    for (auto i = field.begin(); i != field.end(); ++i) {
        Unit& unit = *i;
        std::cout << "Unit at (" << unit.pos_x() << ", "
        << unit.pos_y() << "), health: " << unit.health().value()
        << std::endl;

        unit.health().decrease(10);
    }
    std::cout << std::endl << "After health decreasing:" << std::endl;
    print_field(field);
    std::cout << std::endl << "Removing a unit during  iteration:" << std::endl;
    for (auto i = field.begin(); i != field.end(); ++i) {
        Unit& unit = *i;
        if (unit.pos_x() == 1 && unit.pos_y() == 0) {
            const int x = unit.pos_x();
            const int y = unit.pos_y();
            field.remove_unit(x, y);
            std::cout << "Unit removed from (" << x << ", " << y << ')' << std::endl;
            break;
        }
    }
    std::cout << std::endl << "After remove:" << std::endl;
    print_field(field);
}

int main() {
    demonstarate_factories();
    demonstrate_copy_and_move();
    demonstrate_iterator();
    return 0;
}