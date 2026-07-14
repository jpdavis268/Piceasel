#include "core/Window.h"
#include "GLFW/glfw3.h"
#include "util/Logger.h"
#include <stdexcept>

Window::Window(int width, int height, string title) {
    Logger::message("Opening program window...");

    // Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window
    glfwWindowHint(GLFW_VISIBLE, false);
    windowHandle = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    this->width = width;
    this->height = height;
    if (windowHandle == nullptr) {
        glfwTerminate();
        throw std::runtime_error("GLFW window creation returned null pointer.");
    }

    // Initialize OpenGL context.
    glfwMakeContextCurrent(windowHandle);

    // Set callbacks
    glfwSetWindowUserPointer(windowHandle, this);
    glfwSetWindowSizeCallback(windowHandle, [](GLFWwindow* window, int width, int height) -> void {
        Window* self = static_cast<Window*>(glfwGetWindowUserPointer(window));
        self->width = width;
        self->height = height;
    });

    Logger::message("Window creation finished.");
}

void Window::awaitEvents() {
    glfwWaitEvents();
}

void Window::swapBuffers() {
    glfwSwapBuffers(windowHandle);
}

int Window::getWidth() {
    return width;
}

int Window::getHeight() {
    return height;
}

void Window::setVisible(bool visible) {
    if (visible) {
        glfwShowWindow(windowHandle);
    }
    else {
        glfwHideWindow(windowHandle);
    }
}

bool Window::isWindowClosed() {
    return glfwWindowShouldClose(windowHandle);
}

Window::~Window() {
    glfwTerminate();
}