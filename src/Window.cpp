#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "input.h"
#include <iostream>
#include <string>


Window::Window(int width, int height, std::string title) {
    _width = width;
    _height = height;
    _title = title;

    _init();
}

void Window::run() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    while(!glfwWindowShouldClose(_ID)) {
        glClear(GL_COLOR_BUFFER_BIT);

        std::cout << input::getMouseX() << ", " << input::getMouseY() << std::endl;

        glfwSwapBuffers(_ID);
        glfwPollEvents();
    }

    glfwTerminate();
}

void Window::_init() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _ID = glfwCreateWindow(_width, _height, _title.c_str(), NULL, NULL);
    if (_ID == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }

    glfwSetCursorPosCallback(_ID, input::mouse_position_callback);
    glfwSetMouseButtonCallback(_ID, input::mouse_button_callback);
    glfwSetScrollCallback(_ID, input::scroll_callback);
    glfwSetKeyCallback(_ID, input::key_callback);

    glfwMakeContextCurrent(_ID);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }

    glViewport(0, 0, _width, _height);
    
}
