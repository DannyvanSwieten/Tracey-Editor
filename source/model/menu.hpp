/*
  ==============================================================================

	menu.h
	Created: 10 Feb 2022 1:59:25pm
	Author:  danny

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"

namespace tracey {
	class ApplicationController;
	class MenuModel : public juce::MenuBarModel
	{
	public:
		MenuModel(ApplicationController& appController);
		// Inherited via MenuBarModel
		juce::StringArray getMenuBarNames() override;
		juce::PopupMenu getMenuForIndex(int topLevelMenuIndex,
			const juce::String& menuName) override;
		void menuItemSelected(int menuItemID, int topLevelMenuIndex) override;

	private:
		ApplicationController& appController;
		std::unique_ptr<juce::FileChooser> chooser;
	};
} // namespace tracey