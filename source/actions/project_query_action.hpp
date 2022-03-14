#pragma once
#include "JuceHeader.h"
#include "action.h"
#include <functional>
namespace tracey {
	class ApplicationController;
	class ProjectQuery : public Action {
	public:
		ProjectQuery(ApplicationController& controller);
		~ProjectQuery(){};
		// Inherited via Action
		std::optional<Error> redo() const override;
		std::optional<Error> undo() const override;
		bool isUndoable() const override { return false; }

	public:

		std::function<void(const juce::var&)> onResult;

	private:

		ApplicationController& controller;
		const char* body = "{\"query\": \"{scenes{root name nodes { name mesh }}}\"}";
	};
}