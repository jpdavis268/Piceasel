#include "core/Session.h"
#include "core/Window.h"
#include "util/Logger.h"
#include <format>
#include <optional>
#include <string>
#include <chrono>

using namespace std::chrono;
using std::optional;
using std::string;

Session::Session(optional<string> initialImage) {
    Logger::message("Beginning initialization...");
    time_point start = steady_clock::now();
    
    window = new Window(1280, 720, "Untitled - Piceasel");
    window->setVisible(true);

    // Finish initialization
    time_point end = steady_clock::now();
    long initTimeMS = duration_cast<milliseconds>(end - start).count();
    Logger::message(std::format("Finished initialization in {}ms", initTimeMS));
}

void Session::loop() {
    Logger::message("Entering main loop...");
    while (!shouldClose()) {
        window->awaitEvents();
    }
}

bool Session::shouldClose() {
    return window->isWindowClosed();
}

Session::~Session() {
    Logger::message("Closing program...");

    delete window;
    
    Logger::message("Program termination complete.");
}