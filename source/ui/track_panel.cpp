/*
  ==============================================================================

    left_side_bar.cpp
    Created: 21 Feb 2022 11:07:37am
    Author:  danny

  ==============================================================================
*/
#include "track_panel.hpp"

namespace tracey {
    namespace gui {
        void TrackContainer::paint(juce::Graphics& g)
        {
            g.setColour(juce::Colours::grey);
            g.fillRect(getBounds());
        }
    }
}
