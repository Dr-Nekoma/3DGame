#pragma once

#define GLFW_INCLUDE_VULKAN

#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include <string>

namespace protocol {
    class ProtocolWindow{
        public:
        ProtocolWindow(int width, int height, std::string windowName);
        ~ProtocolWindow(); // Destructor

        ProtocolWindow(const ProtocolWindow&) = delete;
        ProtocolWindow &operator=(const ProtocolWindow&) = delete;

        bool shouldClose() {return glfwWindowShouldClose(window);}

        void createWindowSurface(VkInstance, VkSurfaceKHR*);

        private:
        
        void initWindow();
        const int width;
        const int height;

        std::string windowName;

        GLFWwindow *window;
    };
}