#pragma once

#include "core/Window.h"
#include <optional>
#include <string>

/**
 * @brief Main session class that controls program state.
 */
class Session {
    public:
        /**
         * @brief Initialize the session and program.
         * 
         * @param initialImage Initial image to load, if provided.
         */
        Session(std::optional<std::string> initialImage);

        /**
         * @brief Continuously await events until program is told to close.
         */
        void loop();

        /**
         * @brief Check if program has been told to close.
         * 
         * @return If program was exited by user.
         */
        bool shouldClose();

        /**
         * @brief Clean up session resources when program closes.
         */
        ~Session();

    private:
        Window* window;
};