/*
  ==============================================================================

    Voice.cpp
    Created: 16 Sep 2015 7:55:11pm
    Author:  Matt

  ==============================================================================
*/

#include "Voice.h"

Voice::Voice(int const &note, Wavetable* osc) :
	note(note),
	osc(osc),
	offing(false),
	volume(1)
{	
	shift = pow(2, (note / 12));
	index = 0;
	
	
}

Voice::~Voice()
{
}

int Voice::operator==(const Voice &other) const
{
	if (this->note == other.note) return 1;
	else return 0;
}

float Voice::getNextSample()
{
	if (index > (*osc).table_length)
		index %= (*osc).table_length;

	float val = (*osc).table[index];
	index += shift;

	if (offing) {
		volume -= RELEASE_INC;
		return val * volume;
	} else {
		return val;
	}
}
		