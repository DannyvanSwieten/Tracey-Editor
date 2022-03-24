/*
  ==============================================================================

    scene_graph.cpp
    Created: 21 Feb 2022 5:31:21pm
    Author:  danny

  ==============================================================================
*/

#include "scene_graph.hpp"

namespace tracey
{
    Scene::Scene(const nlohmann::json& var)
    {
        for (const auto& node : var["nodes"])
            nodes.emplace_back(Node(node));

        for (const auto& mesh : var["meshes"])
            meshes.emplace_back(Mesh(mesh));
    }

    Node::Node(const nlohmann::json& var)
    {
        if (!var["mesh"].empty())
        {
            mesh.emplace( var["mesh"] );
        }
    }


    Primitive::Primitive(const nlohmann::json& var)
    {
        material = var["materialId"];
    }


    Mesh::Mesh(const nlohmann::json& var)
    {
        for (const auto& primitive : var["primitives"])
        {
            primitives.emplace_back(Primitive(primitive));
        }
    }


    Project::Project(const nlohmann::json& var)
    {
        for (const auto& scene : var["scenes"])
        {
            scenes.emplace_back(Scene(scene));
        }
    }


}