/*
  ==============================================================================

    Drawbar.cpp
    Created: 14 Oct 2015 5:11:12pm
    Author:  Matt

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Drawbar.h"

//==============================================================================
Drawbar::Drawbar()
{
	addAndMakeVisible(drawbar);

	drawbar.setSliderStyle(Slider::LinearBarVertical);
	drawbar.setValue(0);		
	//drawbar.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
	drawbar.setRange(0, DRAWBAR_NOTCHES, 1);
	//drawbar.addListener(this);

	addAndMakeVisible(drawbar_label);
	drawbar_label.setText("", dontSendNotification);
	drawbar_label.attachToComponent(&drawbar, false);	

}

Drawbar::~Drawbar()
{
}

void Drawbar::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (Colours::white);   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::lightblue);
    g.setFont (14.0f);
    g.drawText ("Drawbar", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void Drawbar::resized()
{
	drawbar.setBounds(getLocalBounds());
}

void Drawbar::setLabel(const String label_text)
{
	drawbar_label.setText(label_text, dontSendNotification);
}

float Drawbar::getValue()
{
	return drawbar.getValue();
}