#include "ParameterRegistration.h"
#include "Utils.h"

juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
{
    std::vector<std::unique_ptr<juce::RangedAudioParameter>> parameters;

    // create parameters
    auto pReadRate = std::make_unique<juce::AudioParameterFloat>("readRate", "Read Rate", juce::NormalisableRange<float>(0.0f, 2.0f), 1.0);
    auto pReSync = std::make_unique<juce::AudioParameterBool>("reSync", "Re Sync", false);


    // add parameters to vector
    parameters.push_back(std::move(pReadRate));
    parameters.push_back(std::move(pReSync));

    return { parameters.begin(), parameters.end() };
}

void addParameterListeners(juce::AudioProcessorValueTreeState& treeState, juce::AudioProcessorValueTreeState::Listener* listener)
{
    // add parameter listeners
    treeState.addParameterListener("readRate", listener);
    treeState.addParameterListener("reSync", listener);

}

void removeParameterListeners(juce::AudioProcessorValueTreeState& treeState, juce::AudioProcessorValueTreeState::Listener* listener)
{
    // remove parameter listeners
    treeState.removeParameterListener("readRate", listener);
    treeState.removeParameterListener("reSync", listener);

}

Settings getSettings(juce::AudioProcessorValueTreeState& treeState)
{
    Settings settings;

    settings.readRate = treeState.getRawParameterValue("readRate")->load();
    settings.reSync = treeState.getRawParameterValue("reSync")->load();

    return settings;
}
