/*
  ==============================================================================

	action.h
	Created: 21 Feb 2022 8:03:24pm
	Author:  danny

  ==============================================================================
*/

#pragma once

#include <optional>
#include <string>

namespace tracey {

	class Error {
	public:
		Error(const std::string& message);
		const std::string message;
	};

	class Action {
	public:
		virtual ~Action() {};
		virtual std::optional<Error> redo() const = 0;
		virtual std::optional<Error> undo() const = 0;
		virtual bool isUndoable() const { return true; }
	};
}