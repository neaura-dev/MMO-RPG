#include <cstdlib>
#include <ctime>
#include "GameController.hpp"
#include "Logger.hpp"

int main() {
    srand(time(0));
    GameController controller(10, 10, 5);
    controller.run_tests();
    Logger::instance().print_all();
    return 0;
}