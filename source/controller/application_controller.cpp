/*
  ==============================================================================

	application_controller.cpp
	Created: 21 Feb 2022 8:15:46pm
	Author:  danny

  ==============================================================================
*/
#include <string_view>
#include <sstream>
#include "application_controller.hpp"

namespace tracey {
	ApplicationController::ApplicationController():
		ctx("127.0.0.1:7000/ws")
	{
		sceneLoadedSubscription = ctx.sendAsync(
			R"(subscription{
				sceneLoaded { 
					id
					root 
					name 
					nodes {
						id
						name 
						meshes {
							name
							material {
								name
								roughness
								metalness
								baseColor
							}
						}
						children
					} 
				} 
			})", {}, [&](const nlohmann::json& value) {
			for (auto listener : eventListeners.at("sceneLoaded"))
			{
				listener->handleEvent(value["sceneLoaded"]);
			}
		});
	}
	ApplicationController::~ApplicationController()
	{
	}
	void ApplicationController::registerEventListener(const std::string& subscription, GraphQLEventListener* listener)
	{
		if (eventListeners.find(subscription) == eventListeners.end())
			eventListeners[subscription] = {};

		eventListeners[subscription].emplace_back(listener);
	}
	void ApplicationController::scheduleAction(std::unique_ptr<Action>&& action)
	{
		//juce::MessageManager::callAsync([&, action = std::move(action)]{
			action->redo();
			if (action->isUndoable())
				undoStack.push(std::move(action));
		//});
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

	void ApplicationController::sendQuery(const std::string_view message, std::function<void(const nlohmann::json& value)> onResult)
	{
		ctx.sendAsync(message, {}, onResult).detach();
	}
}