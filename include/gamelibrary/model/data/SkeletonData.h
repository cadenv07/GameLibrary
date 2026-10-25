/***************************************************\
* @file SkeletonData.h
* @brief [fill out description]
*
* [fill out description]
*
* @author cadenv07
* @date 10/25/26
\***************************************************/

#pragma once

#include <cstdint>
#include <vector>
#include <glm/glm.hpp>

namespace GameLibrary {
    struct BoneInfluence {
        uint32_t vertexIndex = 0;
        uint32_t boneNodeIndex = 0;
        float weight = 0.0f;
    };
    struct SkeletonData {
        std::vector<size_t> boneNodes;
        std::vector<glm::mat4> inverseBindMatrices;
    };
    struct SkinData {
        size_t meshNodeIndex = 0;
        size_t vertexCount = 0;
        std::vector<BoneInfluence> boneInfluences;
    };
    struct SkinningCache {
        std::vector<glm::mat4> bindGlobals;
        std::vector<glm::mat4> inverseBindGlobals;
    };
}