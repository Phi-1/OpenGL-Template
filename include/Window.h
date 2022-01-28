#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


class Window {
public:
    Window(int width, int height, std::string title);
    void run();

private:
    GLFWwindow* _ID;
    int _width, _height;
    std::string _title;

    void _init();
};


#endif