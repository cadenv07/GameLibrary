/***************************************************\
* @file ModelData.h
* @brief Holds various structs for sorting out
* information pertaining to creating models.
*
* @author cadenv07
* @date 10/25/26
\***************************************************/

#pragma once

#include <gamelibrary/model/data/AnimationData.h>
#include <gamelibrary/model/data/SkeletonData.h>

#include <glm/glm.hpp>
#include <glm/detail/type_quat.hpp>

#include <string>
#include <vector>
#include <filesystem>
#include <optional>

namespace GameLibrary {
    /**
     * @struct MeshData
     *
     * @brief Stores information for a singular mesh.
     *
     * @details Contains information for:
     *  - A mesh name.
     *  - The mesh vertices.
     *  - The mesh normals.
     *  - The mesh colors.
     *  - The mesh UV channels
     *  - The mesh indices.
     *
     * @details And optionally:
     *  - A material index
     *  - A skin index.
     */
    struct MeshData {
        std::string name;
        std::vector<glm::vec3> vertices;
        std::vector<glm::vec3> normals;
        std::vector<glm::vec4> colors;
        std::vector<std::vector<glm::vec2>> uvChannels;
        std::vector<uint32_t> indices;
        std::optional<size_t> materialIndex;
        std::optional<size_t> skinIndex;
    };

    /**
     * @struct TextureData
     *
     * @brief Holds information for storing textures.
     *
     * @details Contains information such as:
     *  - A path to the texture.
     *  - The texture flags.
     *  - The texture blend.
     *  - The position of the texture.
     *  - The scale of the texture.
     *  - The rotation of the texture.
     */
    struct TextureData {
        /** @brief The filesystem path of the texture. */
        std::filesystem::path path;

        /** @brief Flags to use to create the texture. */
        int32_t flags = 0;
        int32_t blend = 0;

        glm::vec2 position{0.0f};
        glm::vec2 scale{1.0f};

        float rotation{0.0f};
    };

    // Materials
    struct MaterialData {
        std::string name;
        glm::vec4 color{1.0f};
        float shininess{0.0f};
        int32_t blend = 0;
        int32_t fx = 0;
        std::vector<std::optional<size_t>> textureIndices;
    };

    // Scene hierarchy
    struct NodeData {
        std::string name;
        int parentIndex = -1;
        glm::vec3 position{0.0f};
        glm::quat rotation{1.0f, 0.0f, 0.0f, 0.0f};
        glm::vec3 scale{1.0f};
        std::vector<size_t> meshIndices;
    };

    // Complete model
    struct ModelData {
        std::vector<MeshData> meshes;
        std::vector<TextureData> textures;
        std::vector<MaterialData> materials;
        std::vector<NodeData> nodes;
        std::optional<SkeletonData> skeleton;
        std::vector<SkinData> skins;
        std::vector<AnimationData> animations;
    };
}