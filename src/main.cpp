#pragma once

#include <cstdlib>
#define GLFW_INCLUDE_VULKAN

// #include <GL/gl.h>
// #include <GLFW/glfw3.h>

// #define GLM_FORCE_RADIANS
// #define GLM_FORCE_DEPTH_ZERO_TO_ONE
// #include <glm/vec4.hpp>
// #include <glm/mat4x4.hpp>


#include <iostream>

#include "lve_window.hpp"
#include "lve_pipeline.hpp"

class Runner {
    public:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;
    void run (){};

    private:
    lve::LveWindow lveWindow{WIDTH, HEIGHT, "SomeName"};
    lve::LvePipeline lvePipeline{"shaders/simple_shader.vert.spv", "shaders/simple_shader.vert.spv"};
};

int main() {
    Runner app{};

    try{
        app.run();
    } catch (const std::exception &ex){
        std::cerr << ex.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
