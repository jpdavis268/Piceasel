#pragma once

#include <string>
using std::string;

/**
 * @brief Wrapper for logging functions, both to simplify their use
 * and allow for batch modification of their structure and implementation as needed.
 */
namespace Logger {
    /**
     * @brief Print an info message to the standard output stream.
     * 
     * @param message Message to print.
     */
    void message(string message);

    /**
     * @brief Print a warning message to the standard error stream.
     * This should be used for recoverable errors that are not fatal to the execution of the program.
     * 
     * @param message Message to print.
     */
    void warning(string message);

    /**
     * @brief Print an error message to the standard error stream.
     * This should be used for fatal errors that prevent the program from functioning in any usable state,
     * and is expected to be followed by an exit.
     * 
     * @param message Message to print.
     */
    void error(string message);
}