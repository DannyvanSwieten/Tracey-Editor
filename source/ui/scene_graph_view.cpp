/*
  ==============================================================================

	scene_graph_view.cpp
	Created: 21 Feb 2022 4:50:07pm
	Author:  danny

  ==============================================================================
*/

#include "scene_graph_view.hpp"
#include "../actions/project_query_action.hpp"
#include "../model/scene_graph.hpp"

namespace tracey {
	namespace gui {
		SceneGraphViewComponent::SceneGraphViewComponent(ApplicationController& appController)
			: appController(appController)
		{

			appController.registerEventListener("sceneLoaded", this);
			auto root = new ProjectTreeViewItem();
			tree.setRootItem(root);
			addAndMakeVisible(tree);
		}
		void SceneGraphViewComponent::paint(juce::Graphics& g)
		{
			g.fillAll(juce::Colours::darkgrey);
		}
		void SceneGraphViewComponent::resized()
		{
			tree.setSize(getWidth(), getHeight() / 2);
		}
		NodeTreeViewItem* SceneGraphViewComponent::buildNodeView(size_t sceneId, const nlohmann::json& node, const::nlohmann::json& nodes)
		{
			juce::String name = node["name"];
			auto nodeView = new NodeTreeViewItem(name, sceneId, node["id"]);
			nodeView->onClick = [&](size_t sceneId, size_t nodeId) {
				std::stringstream body;
				body << "query{getNode(sceneId: " << std::to_string(sceneId);
				body << " nodeId :" << std::to_string(nodeId);
				body << "){name meshes{material{name roughness metalness baseColor}}}}";

				appController.sendQuery(body.str(), [&](const nlohmann::json& result) {
					juce::MessageManager::callAsync([&, result] {
						nodeInspector = std::make_unique<NodeInspector>(result["getNode"]);
						nodeInspector->setSize(getWidth(), getHeight() / 2);
						nodeInspector->setTopLeftPosition(0, tree.getBottom());
						addAndMakeVisible(*nodeInspector);
					});
				});
			};

			for (auto& child : node["children"])
			{
				size_t idx = child;
				auto view = buildNodeView(sceneId, nodes[idx], nodes);
				nodeView->addSubItem(view);
			}

			return nodeView;
		}
		void SceneGraphViewComponent::handleEvent(const nlohmann::json& event)
		{
			juce::MessageManager::callAsync([&, event]{
				const size_t rootIndex = event["root"];

				const auto nodes = event["nodes"];
				const size_t id = event["id"];
				const std::string name = event["name"];
				auto sceneView = new SceneTreeViewItem( name, id );
				sceneView->addSubItem(buildNodeView(id, nodes[rootIndex], nodes));

				tree.getRootItem()->addSubItem(sceneView);
			});
		}
		SceneTreeViewItem::SceneTreeViewItem(const juce::String& name, size_t id) : name(name)
		{

		}
		bool SceneTreeViewItem::mightContainSubItems()
		{
			return true;
		}
		void SceneTreeViewItem::paintItem(juce::Graphics& g, int width, int height)
		{
			g.setColour(juce::Colours::grey);
			g.drawRect(0, 0, width, height);
			g.setColour(juce::Colours::lightgrey);
			g.drawText(name, 0, 0, width, height, juce::Justification::centred);
		}
		NodeTreeViewItem::NodeTreeViewItem(const juce::String& name, size_t sceneId, size_t nodeId) : name(name), sceneId(sceneId), nodeId(nodeId)
		{
		}
		bool NodeTreeViewItem::mightContainSubItems()
		{
			return true;
		}
		void NodeTreeViewItem::paintItem(juce::Graphics& g, int width, int height)
		{
			g.setColour(juce::Colours::grey);
			g.drawRect(0, 0, width, height);
			g.setColour(juce::Colours::lightgrey);
			g.drawText(name, 0, 0, width, height, juce::Justification::centred);
		}
		void NodeTreeViewItem::itemClicked(const MouseEvent&)
		{
			if(onClick)
				onClick(sceneId, nodeId);
		}
		bool ProjectTreeViewItem::mightContainSubItems()
		{
			return true;
		}
		void ProjectTreeViewItem::paintItem(juce::Graphics& g, int width, int height)
		{
			g.setColour(juce::Colours::grey);
			g.drawRect(0, 0, width, height);
			g.setColour(juce::Colours::lightgrey);
			g.drawText("Scenes:", 0, 0, width, height, juce::Justification::centred);
		}
}
}