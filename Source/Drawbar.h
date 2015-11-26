/*
  ==============================================================================

    Drawbar.h
    Created: 14 Oct 2015 5:11:12pm
    Author:  Matt

  ==============================================================================
*/

#ifndef DRAWBAR_H_INCLUDED
#define DRAWBAR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "DrawbarSettings.h"

//==============================================================================
/*
*/
class Drawbar    : public Component
{
public:
	Drawbar();

    ~Drawbar();

    void paint (Graphics&);
    void resized();

	void setLabel(const String label_text);
	float getValue();

	Slider drawbar;	

private:
	
	Label  drawbar_label;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Drawbar)
};


#endif  // DRAWBAR_H_INCLUDED
