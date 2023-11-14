#pragma once

#define GLFW_INCLUDE_VULKAN

#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include <string>

namespace lve {
    class LveWindow{
        public:
        LveWindow(int width, int height, std::string windowName);
        ~LveWindow(); // Destructor

        private:
        
        void initWindow();
        const int width;
        const int height;

        std::string windowName;

        GLFWwindow *window;
    };
}