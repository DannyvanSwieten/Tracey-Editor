/*
  ==============================================================================

    load_scene_action.h
    Created: 1 Mar 2022 4:15:19pm
    Author:  danny

  ==============================================================================
*/

#pragma once
#include "action.hpp"
#include "JuceHeader.h"
#include <functional>
namespace tracey
{
	class ApplicationController;
	class RenderSceneQuery : public Action {
	public:
		RenderSceneQuery(ApplicationController& controller);
		~RenderSceneQuery() {};
		// Inherited via Action
		std::optional<Error> redo() const override;
		std::optional<Error> undo() const override;

	public:

		std::function<void(const juce::var&)> onResult;

	private:

		ApplicationController& controller;
	};
}