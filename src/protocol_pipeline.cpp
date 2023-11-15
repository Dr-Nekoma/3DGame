#include "protocol_pipeline.hpp"
#include "vulkan/vulkan_core.h"
#include <fstream>
#include <stdexcept>
#include <sys/_types/_size_t.h>
#include <vector>
#include <iostream>

namespace protocol {
    std::vector<char> ProtocolPipeline::readFile(const std::string& filePath){
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

    void ProtocolPipeline::createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfiguration& config){
        auto vertCode = readFile(vertFilepath);
        auto fragCode = readFile(fragFilepath);

        std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n';
        std::cout << "Fragment Shader Code Size: " << fragCode.size() << '\n';
    }

    ProtocolPipeline::ProtocolPipeline(const std::string& vertFilePath, const std::string& fragFilePath, ProtocolDevice& device, const PipelineConfiguration& config) : device{device}{
        createGraphicsPipeline(vertFilePath, fragFilePath, config);
    }

    void ProtocolPipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule){
        VkShaderModuleCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.codeSize = code.size();
        createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

        if(vkCreateShaderModule(device.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS)
            throw std::runtime_error("Failed to create shader module");
    }

    PipelineConfiguration ProtocolPipeline::defaultPipelineConfiguration(uint32_t width, uint32_t height){
        PipelineConfiguration configInfo{};
        return configInfo;
    }
}