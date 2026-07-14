#include "core/Session.h"
#include <optional>
#include <string>

/**
 * @brief Launch Piceasel.
 * 
 * @param argc Number of arguments.
 * @param argv Name of file to load, if provided.
 * @return Exit code.
 */
int main(int argc, char** argv) {
    std::optional<std::string> image;
    if (argc < 2) {
        image = {};
    }
    else {
        image = argv[1];
    }
    
    Session session = Session(image);
    session.loop();
}