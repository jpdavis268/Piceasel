#include "util/Logger.h"
#include <iostream>

namespace Logger {
    void message(string message) {
        std::cout << "[INFO] " << message << std::endl;
    }

    void warning(string message) {
        std::cerr << "[WARNING] " << message << std::endl;
    }

    void error(string message) {
        std::cerr << "[ERROR] " << message << std::endl;
    }
}