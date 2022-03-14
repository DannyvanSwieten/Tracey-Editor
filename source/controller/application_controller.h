/*
  ==============================================================================

	application_controller.h
	Created: 21 Feb 2022 8:15:46pm
	Author:  danny

  ==============================================================================
*/

#pragma once

#include <memory>
#include <stack>
#include "JuceHeader.h"
#include "../actions/action.h"

#include <graphql_ws/context.hpp>

namespace tracey {
	class ApplicationController {
	public:

		ApplicationController();
		~ApplicationController();
		void scheduleAction(std::unique_ptr<Action>&& action);
		void undo();
		void handleStateMutation(/*Some json format*/);
		juce::var sendQuery(const char* body);
	private:

	private:

		graphql_ws::Context ctx;
		std::stack < std::unique_ptr<Action >> undoStack;
		std::stack < std::unique_ptr<Action >> redoStack;
	};
}