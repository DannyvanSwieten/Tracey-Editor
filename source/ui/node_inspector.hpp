#pragma once

#include <JuceHeader.h>
#include <nlohmann/json.hpp>

namespace tracey::gui
{
	class NumberBox : public juce::Component
	{
	public:
		NumberBox(const juce::String& name);
		void resized() final;

	private:
		juce::Label label;
		juce::Label value;
	};
	class MaterialInspector : public juce::Component
	{
	public:
		MaterialInspector(const nlohmann::json& material);
		void resized() final;

	private:

		Label nameLabel;
		juce::ColourSelector colorPicker;
		juce::Slider roughnessFactor;
		juce::Slider metallicFactor;
	};
	class NodeInspector : public juce::Component 
	{
	public:
		NodeInspector(const nlohmann::json& node);
		void paint(juce::Graphics& g) final;
		void resized() final;

	private:

		Label nameLabel;
		std::unique_ptr<MaterialInspector> materialInspector;
	};
}