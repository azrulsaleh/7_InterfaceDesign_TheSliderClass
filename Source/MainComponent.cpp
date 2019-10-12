/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    addAndMakeVisible(frequencySlider);
    frequencySlider.setRange(50, 5000.0);
    frequencySlider.setTextValueSuffix(" Hz");
//    frequencySlider.addListener(this);
    frequencySlider.onValueChange = [this] { durationSlider.setValue(1.0 / frequencySlider.getValue(), dontSendNotification); };
    frequencySlider.setValue(500.0);
    frequencySlider.setTextBoxStyle(Slider::TextBoxLeft, false, 160, frequencySlider.getTextBoxHeight());
    frequencySlider.setSkewFactorFromMidPoint(500);
    
    addAndMakeVisible(frequencyLabel);
    frequencyLabel.setText("Frequency", dontSendNotification);
    frequencyLabel.attachToComponent(&frequencySlider, true);
    
    addAndMakeVisible(durationSlider);
    durationSlider.setRange(1.0 / frequencySlider.getMaximum(), 1.0 / frequencySlider.getMinimum());
    durationSlider.setTextValueSuffix(" s");
//    durationSlider.addListener(this);
    durationSlider.onValueChange = [this] { frequencySlider.setValue(1.0 / durationSlider.getValue(), dontSendNotification); };
    durationSlider.setTextBoxStyle(Slider::TextBoxLeft, false, 160, frequencySlider.getTextBoxHeight());
    durationSlider.setSkewFactorFromMidPoint(0.002);
    
    addAndMakeVisible(durationLabel);
    durationLabel.setText("Duration", dontSendNotification);
    durationLabel.attachToComponent(&durationSlider, true);
    
    setSize (600, 90);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    auto sliderLeft = 120;
    frequencySlider.setBounds(sliderLeft, 20, getWidth() - sliderLeft - 10, 20);
    durationSlider.setBounds(sliderLeft, 50, getWidth() - sliderLeft - 10, 20);
}

//void MainComponent::sliderValueChanged(Slider* slider)
//{
//    if (slider == &frequencySlider)
//        durationSlider.setValue(1.0 / frequencySlider.getValue(), dontSendNotification);
//    else if (slider == &durationSlider)
//        frequencySlider.setValue(1.0 / durationSlider.getValue(), dontSendNotification);
//}
