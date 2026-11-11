#pragma once

#include <memory>
#include <string>
#include "Base.hpp"
#include "GameField.hpp"
#include "UnitFactory.hpp"

class GameController {
public:
    GameController(int field_w, int field_h, int max_units);
    ~GameController() = default;

    void setup_test_1();
    void setup_test_2();
    void setup_test_3();
    void setup_test_4();
    
    void run_tests();

private:
    std::shared_ptr<Base> base_;
    GameField field_;
    std::unique_ptr<UnitFactory> factory_;
};