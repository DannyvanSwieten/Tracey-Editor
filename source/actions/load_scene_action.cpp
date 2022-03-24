/*
  ==============================================================================

    load_scene_action.cpp
    Created: 1 Mar 2022 4:15:19pm
    Author:  danny

  ==============================================================================
*/

#include "load_scene_action.hpp"
#include "../controller/application_controller.hpp"
#include <sstream>
namespace tracey
{
    LoadSceneQuery::LoadSceneQuery(ApplicationController& controller, const juce::File& file): controller(controller), file(file)
    {
    }
    std::optional<Error> LoadSceneQuery::redo() const
    {
        std::stringstream ss;
        ss << "mutation {load(path:";
        ss << "\"" << file.getFullPathName().replace("\\", "\\\\") << "\"" << ")}";

        controller.sendQuery(ss.str(), nullptr);

        return std::optional<Error>();
    }
    std::optional<Error> LoadSceneQuery::undo() const
    {
        return std::optional<Error>();
    }
}
