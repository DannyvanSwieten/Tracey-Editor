/*
  ==============================================================================

    scene_graph.h
    Created: 21 Feb 2022 5:31:21pm
    Author:  danny

  ==============================================================================
*/

#pragma once
#include <nlohmann/json.hpp>
#include <optional>
#include <array>
#include <vector>

namespace tracey
{
    struct Transform
    {
        std::array<float, 3> position{ 0.f, 0.f, 0.f };
        std::array<float, 3> scale{ 1.f, 1.f, 1.f };
        std::array<float, 3> orientation{ 0.f, 0.f, 0.f };
    };

    struct Node
    {
        Node(const nlohmann::json& var);
        std::optional<size_t> mesh;
        std::optional<size_t> camera;
        Transform transform;
    };

    struct Primitive
    {
        Primitive(const nlohmann::json& var);
        std::size_t material{ 0 };
    };

    struct Mesh
    {
        Mesh(const nlohmann::json& var);
        std::string name;
        std::vector<Primitive> primitives;
    };

    struct Image
    {
        std::string name;
        std::vector<std::uint8_t> preview;
    };

    struct Scene
    {
        Scene(const nlohmann::json& var);

        std::size_t id{0};
        std::vector<Node> nodes;
        std::vector<Mesh> meshes;
        std::vector<Image> images;
    };

    struct Project
    {
        Project(const nlohmann::json& var);

        std::vector<Scene> scenes;
    };
}