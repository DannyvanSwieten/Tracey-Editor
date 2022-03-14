/*
  ==============================================================================

	menu.cpp
	Created: 10 Feb 2022 1:59:25pm
	Author:  danny

  ==============================================================================
*/

#include "menu.hpp"
#include "../controller/application_controller.h"
#include "../actions/load_scene_action.h"
namespace tracey {
	MenuModel::MenuModel(ApplicationController& appController): appController(appController)
	{
	}
	juce::StringArray tracey::MenuModel::getMenuBarNames() {
		return { "File", "Scene" };
	}

	juce::PopupMenu
		tracey::MenuModel::getMenuForIndex(int topLevelMenuIndex,
			const juce::String& menuName) {

		juce::PopupMenu menu;
		switch (topLevelMenuIndex) {
		case 0: {
			menu.addItem(1, "New");
			menu.addItem(2, "Open");
		}
		}

		return menu;
	}

	void tracey::MenuModel::menuItemSelected(int menuItemID,
		int topLevelMenuIndex)
	{
		switch (topLevelMenuIndex)
		{
		case 0:
		{
			switch (menuItemID)
			{
			case 2:
			{
				chooser = std::make_unique< juce::FileChooser >("Choose a file...", juce::File(), "*.gltf");
				chooser->launchAsync(juce::FileBrowserComponent::canSelectFiles, [&](const juce::FileChooser& c) {
					const auto file = c.getResult();
					appController.scheduleAction(std::make_unique<LoadSceneQuery>(appController, file));
				});
				break;
			}
			}
		}
		}

	}
} // namespace tracey