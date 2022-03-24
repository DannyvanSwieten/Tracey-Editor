/*
  ==============================================================================

	scene_graph_view.h
	Created: 21 Feb 2022 4:50:07pm
	Author:  danny

  ==============================================================================
*/

#pragma once
#include <functional>
#include <nlohmann/json.hpp>
#include "JuceHeader.h"
#include "../controller/application_controller.hpp"
#include "node_inspector.hpp"
namespace tracey {
	namespace gui {

		class ProjectTreeViewItem : public juce::TreeViewItem {
		public:
			// Inherited via TreeViewItem
			virtual bool mightContainSubItems() override;
			void paintItem(juce::Graphics& g, int width, int height) override;
		};

		class SceneTreeViewItem : public juce::TreeViewItem {
		public:
			SceneTreeViewItem(const juce::String& name, size_t id);
			// Inherited via TreeViewItem
			virtual bool mightContainSubItems() override;
			void paintItem(juce::Graphics& g, int width, int height) override;
		private:

			juce::String name;
		};

		class NodeTreeViewItem : public juce::TreeViewItem {
		public:
			NodeTreeViewItem(const juce::String& name, size_t sceneId, size_t nodeId);

			// Inherited via TreeViewItem
			virtual bool mightContainSubItems() override;
			void paintItem(juce::Graphics& g, int width, int height) override;
			void itemClicked(const MouseEvent&);

		public:

			std::function<void(size_t sceneId, size_t nodeId)> onClick;

		private:

			juce::String name;
			size_t sceneId = 0;
			size_t nodeId = 0;
		};

		class SceneGraphViewComponent : public juce::Component, public GraphQLEventListener {
		public:
			SceneGraphViewComponent(ApplicationController& appController);
			void paint(juce::Graphics& g) final;
			void resized() final;

		private:

			NodeTreeViewItem* buildNodeView(size_t sceneId, const nlohmann::json& value, const::nlohmann::json& nodes);

		private:

			ApplicationController& appController;
			juce::TreeView tree;
			std::unique_ptr<NodeInspector> nodeInspector;

			// Inherited via GraphQLEventListener
			virtual void handleEvent(const nlohmann::json& event) override;
		};
	}
}