/*
  ==============================================================================

    Voice.h
    Created: 16 Sep 2015 7:55:11pm
    Author:  Matt

  ==============================================================================
*/

#ifndef VOICE_H_INCLUDED
#define VOICE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Wavetable.h"

#define RELEASE_INC .001

class Voice
{
public:
	Wavetable* osc;
	int shift;
	int note;

	Voice(int const &note, Wavetable* osc);
	~Voice();

	int operator==(const Voice &other) const;

	float getNextSample();

	bool offing;
	float volume;

private:
	int index;

};



#endif  // VOICE_H_INCLUDED
