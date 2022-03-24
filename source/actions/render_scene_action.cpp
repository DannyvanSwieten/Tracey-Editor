/*
  ==============================================================================

    load_scene_action.cpp
    Created: 1 Mar 2022 4:15:19pm
    Author:  danny

  ==============================================================================
*/

#include "render_scene_action.hpp"
#include "../controller/application_controller.hpp"
#include <sstream>
namespace tracey
{
    RenderSceneQuery::RenderSceneQuery(ApplicationController& controller): controller(controller)
    {
    }
    std::optional<Error> RenderSceneQuery::redo() const
    {
        controller.sendQuery("mutation {build(sceneId: 0) render(batches: 32 sceneId: 0)}", nullptr);

        return std::optional<Error>();
    }
    std::optional<Error> RenderSceneQuery::undo() const
    {
        return std::optional<Error>();
    }
}
