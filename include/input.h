#ifndef INPUT_H
#define INPUT_H

#include <GLFW/glfw3.h>
#include <array>

namespace input {

    // Keylistener
    std::array<bool, 1024> keys = {};

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (key >= keys.size()) { return; }
        if (action == GLFW_PRESS) { keys[key] = true; } 
        else if (action == GLFW_RELEASE) { keys[key] = false; }
    }

    bool isKeyPressed(int key) {
        return keys[key];
    }

    // Mouselistener
    std::array<bool, 3> mouseButtons = {};
    double mouseX = 0, mouseY = 0, lastX = 0, lastY = 0;
    double scrollX = 0, scrollY = 0;
    bool mouseDragging = false;

    void mouse_position_callback(GLFWwindow* window, double xpos, double ypos) {
        lastX = mouseX;
        lastY = mouseY;
        mouseX = xpos;
        mouseY = ypos;
        mouseDragging = mouseButtons[GLFW_MOUSE_BUTTON_LEFT] || mouseButtons[GLFW_MOUSE_BUTTON_RIGHT];
    }

    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
        if (button >= mouseButtons.size()) { return; }
        if (action == GLFW_PRESS) { mouseButtons[button] = true; }
        else if (action == GLFW_RELEASE) { 
            mouseButtons[button] = false; 
            mouseDragging = false;
        }
    }

    void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
        scrollX = xoffset;
        scrollY = yoffset;
    }

    double getMouseX() {
        return mouseX;
    }

    double getMouseY() {
        return mouseY;
    }

    double getScrollX() {
        return scrollX;
    }

    double getScrollY() {
        return scrollY;
    }

    bool isDragging() {
        return mouseDragging;
    }
    
}

#endif