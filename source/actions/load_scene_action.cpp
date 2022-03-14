/*
  ==============================================================================

    load_scene_action.cpp
    Created: 1 Mar 2022 4:15:19pm
    Author:  danny

  ==============================================================================
*/

#include "load_scene_action.h"
#include "../controller/application_controller.h"
#include <sstream>
namespace tracey
{
    LoadSceneQuery::LoadSceneQuery(ApplicationController& controller, const juce::File& file): controller(controller), file(file)
    {
    }
    std::optional<Error> LoadSceneQuery::redo() const
    {
        std::stringstream ss;
        ss << "{\"query\": \"{load(path:";
        ss << "\\\"" << file.getFullPathName().replace("\\", "\\\\") << "\\\"" << ")}";
        ss << "\"}";

        controller.sendQuery(ss.str().c_str());

        return std::optional<Error>();
    }
    std::optional<Error> LoadSceneQuery::undo() const
    {
        return std::optional<Error>();
    }
}
