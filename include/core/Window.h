#pragma once

#include "GLFW/glfw3.h"
#include <string>
using std::string;

/**
 * @brief Manages the application window and its underlying resources.
 */
class Window {
    public:
        /**
         * @brief Create and initialize the program window.
         * 
         * @param width Initial window width.
         * @param height Initial window height.
         * @param title Initial window title.
         */
        Window(int width, int height, string title);

        /**
         * @brief Wait for the user to provide new inputs.
         */
        void awaitEvents();

        /**
         * @brief Push the buffered frame to the display.
         */
        void swapBuffers();

        /**
         * @brief Get the width of the window.
         * 
         * @return Window width.
         */
        int getWidth();

        /**
         * @brief Get the height of the window.
         * 
         * @return Window height.
         */
        int getHeight();

        /**
         * @brief Show or hide the window.
         * 
         * @param visible Whether to show or hide the window.
         */
        void setVisible(bool visible);

        /**
         * @brief Get whether the window has been closed by the user.
         * 
         * @return Whether window has been ordered to close.
         */
        bool isWindowClosed();

        /**
         * @brief Destroy the window and free underlying resources.
         */
        ~Window();

    private:
        GLFWwindow* windowHandle = nullptr;
        int width = 0;
        int height = 0;
};