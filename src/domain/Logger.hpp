#pragma once

#include <string>
#include <vector>

class Logger {
public:
    static Logger& instance();

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    void log(const std::string& message);
    void print_all() const;
    void clear();

private:
    std::vector<std::string> logs_;

    Logger() = default;
};