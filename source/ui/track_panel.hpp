/*
  ==============================================================================

	left_side_bar.h
	Created: 21 Feb 2022 11:07:37am
	Author:  danny

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

namespace tracey {
	namespace gui {
		class TrackContainer : public juce::Component {
		public:
			void paint(juce::Graphics& g);
		};
	}
}