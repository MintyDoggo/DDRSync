#pragma once
#include <JuceHeader.h>

struct Settings
{
    double readRate = 1.0; // it's possible to go faster but it won't be what you expect lol
    bool reSync = false;
};

juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
void addParameterListeners(juce::AudioProcessorValueTreeState& treeState, juce::AudioProcessorValueTreeState::Listener* listener);
void removeParameterListeners(juce::AudioProcessorValueTreeState& treeState, juce::AudioProcessorValueTreeState::Listener* listener);
Settings getSettings(juce::AudioProcessorValueTreeState& treeState);
