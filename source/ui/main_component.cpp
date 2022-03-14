#include "main_component.hpp"

//==============================================================================
MainComponent::MainComponent(tracey::ApplicationController& appController) : appController(appController), sceneGraphView(appController)
{
	setSize(600, 400);
	addAndMakeVisible(trackContainer);
	addAndMakeVisible(viewport);
	addAndMakeVisible(animationPanel);
	addAndMakeVisible(sceneGraphView);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint(juce::Graphics& g)
{
	g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
	const auto widthFactor = getWidth() / 5;
	const auto heightFactor = getHeight() / 4;
	trackContainer.setSize(widthFactor, heightFactor * 3);
	viewport.setSize(widthFactor * 3, heightFactor * 3);
	viewport.setTopLeftPosition(trackContainer.getRight(), 0);
	animationPanel.setSize(getWidth(), heightFactor);
	animationPanel.setTopLeftPosition(0, viewport.getBottom());
	sceneGraphView.setSize(widthFactor * 1, heightFactor * 3);
	sceneGraphView.setTopLeftPosition(viewport.getRight(), 0);
}
