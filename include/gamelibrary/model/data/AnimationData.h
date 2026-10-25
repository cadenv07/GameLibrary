/***************************************************\
* @file AnimationData.h
* @brief [fill out description]
*
* [fill out description]
*
* @author cadenv07
* @date 10/25/26
\***************************************************/

#pragma once

#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <glm/detail/type_quat.hpp>

namespace GameLibrary {
    template<typename T>
    struct keyframeData {
        int frame = 0;
        T value{};
    };

    struct AnimationChannelData {
        size_t nodeIndex = 0;
        std::vector<keyframeData<glm::vec3>> positions;
        std::vector<keyframeData<glm::quat>> rotations;
        std::vector<keyframeData<glm::vec3>> scales;
    };

    struct AnimationSequenceData {
        std::string name;
        int startFrame = 0;
        int endFrame = 0;
    };

    struct AnimationData {
        std::string name;
        int32_t flags = 0;
        int startFrame = 0;
        int endFrame = 0;
        float fps = 30.0f;
        std::vector<AnimationChannelData> channels;
        std::vector<AnimationSequenceData> sequences;
    };
}
