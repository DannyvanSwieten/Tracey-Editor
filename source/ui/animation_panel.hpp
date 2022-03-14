/*
  ==============================================================================

    animation_panel.h
    Created: 21 Feb 2022 1:31:47pm
    Author:  danny

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

namespace tracey {
    namespace gui {
        class AnimationPanel : public juce::Component
        {
        public:
            AnimationPanel();
            ~AnimationPanel() override;

            void paint(juce::Graphics&) override;
            void resized() override;

        private:

            JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AnimationPanel)
        };
    }
}
