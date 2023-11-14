#include "lve_pipeline.hpp"
#include <fstream>
#include <stdexcept>
#include <sys/_types/_size_t.h>
#include <vector>
#include <iostream>

namespace lve {
    std::vector<char> LvePipeline::readFile(const std::string& filePath){
        // ate = seek to the end immediately, avoiding weird transformations
        std::ifstream file{filePath, std::ios::ate | std::ios::binary};

        if (!file.is_open())
            throw std::runtime_error("Failed to open file: " + filePath);

        // Since we are already at the end of the file because of ate, 
        // we get the size with tellg safely by being at the bottom of
        // the bin stream
        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);

        // Back at the top
        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();
        return buffer;
    }

    void LvePipeline::createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath){
        auto vertCode = readFile(vertFilepath);
        auto fragCode = readFile(fragFilepath);

        std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n';
        std::cout << "Fragment Shader Code Size: " << fragCode.size() << '\n';
    }

    LvePipeline::LvePipeline(const std::string& vertFilePath, const std::string& fragFilePath){
        createGraphicsPipeline(vertFilePath, fragFilePath);
    }
}