#include <string>

/**
 * @brief Ensures the application actually starts.
 * 
 * @return Exit code (0 if test succeeded).
 */
int smokeTest() {
    return 0;
}

/**
 * @brief Run a provided test.
 * 
 * @param argc Argument count.
 * @param argv Name of test to run.
 * @return Result of test, should be 0 for passing.
 */
int main(int argc, char** argv) {
    if (argc < 2) {
        return -1;
    }

    std::string test = argv[1];

    if (test == "smokeTest") return smokeTest();
}