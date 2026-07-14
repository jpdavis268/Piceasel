#include "core/Session.h"
#include "util/Logger.h"
#include <optional>
#include <stdexcept>
#include <string>

using std::string;
using std::optional;

/**
 * @brief Launch Piceasel.
 * 
 * @param argc Number of arguments.
 * @param argv Name of file to load, if provided.
 * @return Exit code.
 */
int main(int argc, char** argv) {
    optional<string> image;
    if (argc < 2) {
        image = {};
    }
    else {
        image = argv[1];
    }
    
    try {
        Session session = Session(image);
        session.loop();
    }
    catch (std::runtime_error* e) {
        Logger::error(e->what());
        return -1;
    }
}