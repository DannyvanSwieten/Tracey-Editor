/*
  ==============================================================================

	menu.cpp
	Created: 10 Feb 2022 1:59:25pm
	Author:  danny

  ==============================================================================
*/

#include "menu.hpp"
#include "../controller/application_controller.hpp"
#include "../actions/load_scene_action.hpp"
#include "../actions/render_scene_action.hpp"
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
			  break;
		case 1: {
			menu.addItem(3, "Render");
		}
			  break;
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
		case 1:
		{
			switch (menuItemID)
			{
			case 3:
				appController.scheduleAction(std::make_unique<RenderSceneQuery>(appController));

				break;
			}
		}
		}

	}
} // namespace tracey