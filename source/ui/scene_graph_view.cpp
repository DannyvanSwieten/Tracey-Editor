/*
  ==============================================================================

	scene_graph_view.cpp
	Created: 21 Feb 2022 4:50:07pm
	Author:  danny

  ==============================================================================
*/

#include "scene_graph_view.hpp"
#include "../actions/project_query_action.hpp"

namespace tracey {
	namespace gui {
		SceneGraphViewComponent::SceneGraphViewComponent(ApplicationController& appController) : appController(appController)
		{
			ProjectQuery query(appController);
			auto root = new ProjectTreeViewItem();
			query.onResult = [&](const juce::var& result) {
				if (result.hasProperty("scenes"))
				{
					const auto& scenes = result["scenes"].getArray();
					for (const auto& scene : *scenes)
					{
						auto sceneView = new SceneTreeViewItem(scene["name"]);
						if (scene.hasProperty("nodes"))
						{
							const auto nodes = scene["nodes"].getArray();
							for (const auto& node : *nodes)
							{
								juce::String name = node["name"];
								auto nodeView = new NodeTreeViewItem(name);
								if (node.hasProperty("mesh")) {
									const auto& mesh = node["mesh"];
									nodeView->addSubItem(new MeshTreeViewItem(juce::String("Mesh: ") + mesh));
								}
								sceneView->addSubItem(nodeView);
							}
						}

						if (scene.hasProperty("root"))
						{

						}

						root->addSubItem(sceneView);
					}
				}

			};
			
			query.redo();
			tree.setRootItem(root);
			addAndMakeVisible(tree);
		}
		void SceneGraphViewComponent::paint(juce::Graphics& g)
		{
			g.fillAll(juce::Colours::darkgrey);
		}
		void SceneGraphViewComponent::resized()
		{
			tree.setSize(getWidth(), getHeight());
		}
		SceneTreeViewItem::SceneTreeViewItem(const juce::String& name): name(name)
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
		NodeTreeViewItem::NodeTreeViewItem(const juce::String& name): name(name)
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
		bool ProjectTreeViewItem::mightContainSubItems()
		{
			return true;
		}
		void ProjectTreeViewItem::paintItem(juce::Graphics& g, int width, int height)
		{
			g.setColour(juce::Colours::grey);
			g.drawRect(0, 0, width, height);
			g.setColour(juce::Colours::lightgrey);
			g.drawText("Project", 0, 0, width, height, juce::Justification::centred);
		}
		MeshTreeViewItem::MeshTreeViewItem(const juce::String& name):name(name)
		{
		}
		bool MeshTreeViewItem::mightContainSubItems()
		{
			return false;
		}
		void MeshTreeViewItem::paintItem(juce::Graphics& g, int width, int height)
		{
			g.setColour(juce::Colours::grey);
			g.drawRect(0, 0, width, height);
			g.setColour(juce::Colours::lightgrey);
			g.drawText(name, 0, 0, width, height, juce::Justification::centred);
		}
	}
}