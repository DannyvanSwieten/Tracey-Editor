/*
  ==============================================================================

    project_query_action.cpp
    Created: 1 Mar 2022 2:08:37pm
    Author:  danny

  ==============================================================================
*/

#include "project_query_action.hpp"
#include "../controller/application_controller.h"

namespace tracey
{
    ProjectQuery::ProjectQuery(ApplicationController& controller): controller(controller)
    {
    }
    std::optional<Error> ProjectQuery::redo() const
    {
        const auto result = controller.sendQuery(body);
        onResult(result);
        return std::nullopt;
    }

    std::optional<Error> ProjectQuery::undo() const
    {
        return std::optional<Error>();
    }
}

