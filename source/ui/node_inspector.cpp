#include "node_inspector.hpp"

namespace tracey::gui
{
	NodeInspector::NodeInspector(const nlohmann::json& node)
	{
		const std::string name = node["name"];
		nameLabel.setText(name, juce::NotificationType::dontSendNotification);
		nameLabel.setJustificationType(juce::Justification::centred);
		nameLabel.setColour(Label::ColourIds::backgroundColourId, juce::Colours::black);
		addAndMakeVisible(nameLabel);

		const auto& meshes = node["meshes"];
		if (meshes.is_array())
		{
			for (const auto& mesh : meshes)
			{
				materialInspector = std::make_unique<MaterialInspector>(mesh["material"]);
				addAndMakeVisible(*materialInspector);
			}
		}
	}
	void NodeInspector::paint(juce::Graphics& g)
	{
		g.setColour(juce::Colours::grey);
		g.drawRect(0, 0, getWidth(), getHeight());
	}

	void NodeInspector::resized()
	{
		nameLabel.setSize(getWidth(), 25);
		if (materialInspector) 
		{
			materialInspector->setSize(getWidth(), 325);
			materialInspector->setTopLeftPosition(0, nameLabel.getBottom());
		}
	}

	NumberBox::NumberBox(const juce::String& name)
	{
		label.setText(name, juce::NotificationType::dontSendNotification);
		addAndMakeVisible(label);
		value.setEditable(true);
		addAndMakeVisible(value);
	}

	void NumberBox::resized()
	{
	}
	MaterialInspector::MaterialInspector(const nlohmann::json& material)
	{
		const auto& baseColor = material["baseColor"];
		const auto c = juce::Colour::fromFloatRGBA(baseColor[0], baseColor[1], baseColor[2], baseColor[3]);
		colorPicker.setCurrentColour(c);
		roughnessFactor.setValue(material["roughness"]);
		roughnessFactor.setRange(0, 1);
		metallicFactor.setValue(material["metalness"]);
		metallicFactor.setRange(0, 1);
		nameLabel.setText("Material:", juce::NotificationType::dontSendNotification);
		addAndMakeVisible(nameLabel);
		addAndMakeVisible(colorPicker);
		addAndMakeVisible(roughnessFactor);
		addAndMakeVisible(metallicFactor);
	}
	void MaterialInspector::resized()
	{
		nameLabel.setSize(getWidth(), 25);
		colorPicker.setSize(getWidth(), 250);
		colorPicker.setTopLeftPosition(0, nameLabel.getBottom());
		roughnessFactor.setSize(getWidth(), 25);
		roughnessFactor.setTopLeftPosition(0, colorPicker.getBottom());
		metallicFactor.setSize(getWidth(), 25);
		metallicFactor.setTopLeftPosition(0, roughnessFactor.getBottom());
	}

}