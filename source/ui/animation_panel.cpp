/*
  ==============================================================================

    animation_panel.cpp
    Created: 21 Feb 2022 1:31:47pm
    Author:  danny

  ==============================================================================
*/

#include <JuceHeader.h>
#include "animation_panel.hpp"

namespace tracey {
    namespace gui {
        AnimationPanel::AnimationPanel()
        {
            // In your constructor, you should add any child components, and
            // initialise any special settings that your component needs.

        }

        AnimationPanel::~AnimationPanel()
        {
        }

        void AnimationPanel::paint(juce::Graphics& g)
        {
            /* This demo code just fills the component's background and
               draws some placeholder text to get you started.

               You should replace everything in this method with your own
               drawing code..
            */

            g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));   // clear the background

            g.setColour(juce::Colours::grey);
            g.drawRect(getLocalBounds(), 1);   // draw an outline around the component
        }

        void AnimationPanel::resized()
        {
            // This method is where you should set the bounds of any child
            // components that your component contains..

        }

    }
}

//==============================================================================
