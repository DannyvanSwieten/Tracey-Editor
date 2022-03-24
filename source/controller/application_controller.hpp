/*
  ==============================================================================

	application_controller.h
	Created: 21 Feb 2022 8:15:46pm
	Author:  danny

  ==============================================================================
*/

#pragma once

#include <memory>
#include <map>
#include <stack>
#include "JuceHeader.h"
#include "../actions/action.hpp"

#include <graphql_ws/context.hpp>
#include <nlohmann/json.hpp>

namespace tracey {

	class GraphQLEventListener {
	public:
		virtual ~GraphQLEventListener(){}
		virtual void handleEvent(const nlohmann::json& event) = 0;
	};

	class ApplicationController {
	public:

		ApplicationController();
		~ApplicationController();
		void registerEventListener(const std::string& subscription, GraphQLEventListener* listener);
		void scheduleAction(std::unique_ptr<Action>&& action);
		void undo();
		void handleStateMutation(/*Some json format*/);
		void sendQuery(const std::string_view body, std::function<void(const nlohmann::json& value)> onResult);
	private:

		std::map<std::string, std::vector<GraphQLEventListener*>> eventListeners;

	private:

		graphql_ws::Context ctx;
		std::stack < std::unique_ptr<Action >> undoStack;
		std::stack < std::unique_ptr<Action >> redoStack;

		graphql_ws::Connection sceneLoadedSubscription;
	};
}