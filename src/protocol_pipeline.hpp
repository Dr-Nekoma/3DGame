#pragma once

#include "device.hpp"
#include "vulkan/vulkan_core.h"

#include <_types/_uint32_t.h>
#include <string>
#include <vector>

namespace protocol {
    struct PipelineConfiguration {};

    class ProtocolPipeline {
        public:
        ProtocolPipeline(const std::string& vertFilePath, const std::string& fragFilePath, ProtocolDevice&, const PipelineConfiguration&);

        ~ProtocolPipeline(){}

        ProtocolPipeline(const ProtocolPipeline&) = delete;
        void operator=(const ProtocolPipeline&) = delete;

        static PipelineConfiguration defaultPipelineConfiguration(uint32_t width, uint32_t height);

        private:
        static std::vector<char> readFile(const std::string& filePath);

        void createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfiguration&);

        void createShaderModule(const std::vector<char>&, VkShaderModule*);

        ProtocolDevice & device;
        VkPipeline graphicsPipeline;
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;
    };
}