#pragma once

#include <JuceHeader.h>
#include "track_panel.hpp"
#include "view_port.hpp"
#include "animation_panel.hpp"
#include "scene_graph_view.hpp"

//==============================================================================
/*
	This component lives inside our window, and this is where you should put all
	your controls and content.
*/

namespace tracey
{
	class ApplicationController;
}

class MainComponent : public juce::Component
{
public:
	//==============================================================================
	MainComponent(tracey::ApplicationController& appController);
	~MainComponent() override;

	//==============================================================================
	void paint(juce::Graphics&) override;
	void resized() override;

private:
	//==============================================================================
	// Your private member variables go here...

	tracey::ApplicationController& appController;
	tracey::gui::TrackContainer trackContainer;
	tracey::gui::ViewportComponent viewport;
	tracey::gui::AnimationPanel animationPanel;
	tracey::gui::SceneGraphViewComponent sceneGraphView;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
