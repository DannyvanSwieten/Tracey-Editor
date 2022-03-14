/*
  ==============================================================================

    scene_graph_view.h
    Created: 21 Feb 2022 4:50:07pm
    Author:  danny

  ==============================================================================
*/

#pragma once
#include <functional>
#include "JuceHeader.h"
namespace tracey {
    class ApplicationController;
    namespace gui {

        class ProjectTreeViewItem : public juce::TreeViewItem {
        public:


            // Inherited via TreeViewItem
            virtual bool mightContainSubItems() override;
            void paintItem(juce::Graphics& g, int width, int height) override;

        };

        class SceneTreeViewItem : public juce::TreeViewItem {
        public:

            SceneTreeViewItem(const juce::String& name);
            // Inherited via TreeViewItem
            virtual bool mightContainSubItems() override;
            void paintItem(juce::Graphics& g, int width, int height) override;
        private:

            juce::String name;
        };

        class NodeTreeViewItem : public juce::TreeViewItem {
        public:
            NodeTreeViewItem(const juce::String& name);

            // Inherited via TreeViewItem
            virtual bool mightContainSubItems() override;
            void paintItem(juce::Graphics& g, int width, int height) override;

        private:

            juce::String name;
        };

        class MeshTreeViewItem : public juce::TreeViewItem {
        public:
            MeshTreeViewItem(const juce::String& name);

            // Inherited via TreeViewItem
            virtual bool mightContainSubItems() override;
            void paintItem(juce::Graphics& g, int width, int height) override;

        private:

            juce::String name;
        };

        class SceneGraphViewComponent : public juce::Component {
        public:
            SceneGraphViewComponent(ApplicationController& appController);
            void paint(juce::Graphics& g) final;
            void resized() final;

        public:



        private:

            ApplicationController& appController;
            juce::TreeView tree;
        };
    }
}