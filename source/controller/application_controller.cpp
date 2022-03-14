/*
  ==============================================================================

	application_controller.cpp
	Created: 21 Feb 2022 8:15:46pm
	Author:  danny

  ==============================================================================
*/
#include <string_view>
#include <sstream>
#include "application_controller.h"

namespace tracey {
	ApplicationController::ApplicationController():
		ctx("127.0.0.1:7000")
	{
		
	}
	ApplicationController::~ApplicationController()
	{
	}
	void ApplicationController::scheduleAction(std::unique_ptr<Action>&& action)
	{
		action->redo();
		if (action->isUndoable())
			undoStack.push(std::move(action));
	}
	void ApplicationController::undo()
	{
		if (!undoStack.empty())
		{
			auto action = std::move(undoStack.top());
			action->undo();
			redoStack.push(std::move(action));
		}
	}
	void ApplicationController::handleStateMutation()
	{
	}
	juce::var ApplicationController::sendQuery(const char* body)
	{
		//jassert(success);
		std::stringstream ss;
		ss << "POST / HTTP/1.0" << std::endl;
		ss << "Content-Length:" << strlen(body) << std::endl;
		ss << "Content-Type: application/json" << std::endl << std::endl;
		ss << body;

		const auto message = ss.str();
		const auto result = ctx.sendSync(ss.str(), {});
		return juce::var{};
	}
}