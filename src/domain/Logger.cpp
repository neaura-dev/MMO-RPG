#include "Logger.hpp"

#include <iostream>

// ----- LOGGER -----

Logger& Logger::instance() {
    static Logger instance;
    return instance;
}

void Logger::log(const std::string& message) {
    logs_.push_back(message);
    std::cout << message << std::endl; 
}

void Logger::print_all() const {
    std::cout << std::endl << "----- LOG STORY -----" << std::endl << std::endl;
    for (const auto& msg : logs_) {
        std::cout << msg << std::endl;
    }
}

void Logger::clear() {
    logs_.clear();
}