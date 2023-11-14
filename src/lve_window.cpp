#include "lve_window.hpp"
#include "GLFW/glfw3.h"

namespace lve {
    
    LveWindow::LveWindow(int width, int height, std::string windowName): width{width}, height{height}, windowName{windowName}{
        initWindow();
    }

    LveWindow::~LveWindow(){
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void LveWindow::initWindow(){
        glfwInit();
        // No OpenGL, Vulkan instead
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    
        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    }

}