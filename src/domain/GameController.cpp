#include "GameController.hpp"
#include "Logger.hpp"
#include <string>

GameController::GameController(int field_w, int field_h, int max_units)
    : base_(std::make_shared<Base>(1000, max_units)),
      field_(field_w, field_h, max_units),
      factory_(std::make_unique<KingdomGuardianFactory>()) 
{
    Logger::instance().log("[GAME CONTROLLER](S) init.");
}

// ----- TEST 1 -----

void GameController::setup_test_1() {
    Logger::instance().log("[GAME CONTROLLER](S) Test 1 (Base) start.");
    Logger::instance().log("[GAME CONTROLLER](S) Creating units via factory...");
    auto paladin = base_->create_unit(*factory_, UnitType::Knight, 0, 0);
    auto crossbowman = base_->create_unit(*factory_, UnitType::Archer, 1, 0);
    Logger::instance().log("[GAME CONTROLLER](S) Placing units on the field...");
    field_.add_unit(std::move(paladin));
    field_.add_unit(std::move(crossbowman));
    Logger::instance().log("[GAME CONTROLLER](S) Units amount in base: " + std::to_string(base_->current_units_count()) + ".");
}

// ----- TEST 2 -----

void GameController::setup_test_2() {
    Logger::instance().log("[GAME CONTROLLER](S) Test 2 (Terrain) start.");
    field_.set_terrain(2, 2, std::make_shared<TerrainProxy>(std::make_shared<Forest>()));
    field_.set_terrain(3, 3, std::make_shared<TerrainProxy>(std::make_shared<Kingdom>()));
    field_.set_terrain(4, 4, std::make_shared<TerrainProxy>(std::make_shared<Graveyard>()));
    Logger::instance().log("[GAME CONTROLLER](S) Attempt to move Paladin to the Forest (2, 2).");
    if (!field_.move_unit(0, 0, 2, 2)) {
        Logger::instance().log("[GAME CONTROLLER](S) Fail because Knight type units cannot move to the Forest.");
    }
    Logger::instance().log("[GAME CONTROLLER](S) Move Crossbow Man to the Forest (2, 2).");
    if (field_.move_unit(1, 0, 2, 2)) {
        Logger::instance().log("[GAME CONTROLLER](S) Success because Archer type units can move to the Forest.");
    }
    Logger::instance().log("[GAME CONTROLLER](S) Move Crossbow Man to the Kingdom (3, 3).");
    if (field_.move_unit(2, 2, 3, 3)) {
        Logger::instance().log("[GAME CONTROLLER](S) Success because not Undead type units can move to the Kingdom.");
    }
}

// ----- TEST 3 -----

void GameController::setup_test_3() {
    Logger::instance().log("[GAME CONTROLLER](S) Test 3 (Neutral Objects) start.");
    field_.add_neutral_object(3, 3, std::make_unique<Trap>(30));
    field_.add_neutral_object(2, 2, std::make_unique<Chest>());
    field_.add_neutral_object(1, 0, std::make_unique<Altar>(std::make_unique<ArcherBuffStrategy>()));
    Logger::instance().log("[GAME CONTROLLER](S) Crossbow Man steps on the Trap (3, 3).");
    field_.interact(3, 3, '-');
    Logger::instance().log("[GAME CONTROLLER](S) Move Crossbow Man to Chest (2, 2).");
    if (field_.move_unit(3, 3, 2, 2)) {
        field_.interact(2, 2, '+');
    }
    Logger::instance().log("[GAME CONTROLLER](S) Move Crossbow Man to Altar (1, 0).");
    if (field_.move_unit(2, 2, 1, 0)) {
        field_.interact(1, 0, '*');
    }
    Logger::instance().log("[GAME CONTROLLER](S) Resources in base: " + std::to_string(base_->resources()) + ".");
}

// ----- TEST 4 -----

void GameController::setup_test_4() {
    Logger::instance().log("[GAME CONTROLLER](S) Test 4 (Observer) start.");
    Logger::instance().log("[GAME CONTROLLER](S) --- Part 1: Creation ---");
    Logger::instance().log("[GAME CONTROLLER](S) Units before creation: " + std::to_string(base_->current_units_count()) + ".");
    auto new_knight = base_->create_unit(*factory_, UnitType::Knight, 5, 5);
    field_.add_unit(std::move(new_knight));
    Logger::instance().log("[GAME CONTROLLER](S) Units after creation: " + std::to_string(base_->current_units_count()) + ".");
    Logger::instance().log("[GAME CONTROLLER](S) --- Part 2: Destruction ---");
    Logger::instance().log("[GAME CONTROLLER](S) Units before removal: " + std::to_string(base_->current_units_count()) + ".");
    field_.remove_unit(5, 5);
    Logger::instance().log("[GAME CONTROLLER](S) Units after removal: " + std::to_string(base_->current_units_count()) + ".");
    Logger::instance().log("[GAME CONTROLLER](S) If amount changed, Observer (Base) got the notifications.");
}

// ----- TESTS RUN -----

void GameController::run_tests() {
    Logger::instance().log("[GAME CONTROLLER](S) All tests have been started.");
    setup_test_1();
    setup_test_2();
    setup_test_3();
    setup_test_4();
    Logger::instance().log("[GAME CONTROLLER](S) All tests have been finished.");
}