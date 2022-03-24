#pragma once
#include "JuceHeader.h"
#include "action.hpp"
#include <functional>
#include <nlohmann/json.hpp>
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

		std::function<void(const nlohmann::json&)> onResult;

	private:

		ApplicationController& controller;
		const char* body = "{ scenes{root name nodes {name mesh}} }";
	};
}