/*
  ==============================================================================

    Wavetable.h
    Created: 16 Sep 2015 6:45:20pm
    Author:  Matt

  ==============================================================================
*/

#ifndef WAVETABLE_H_INCLUDED
#define WAVETABLE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "DrawbarSettings.h"
#define NUM_OF_TABLES 12

class Wavetable
{
public:
	// Vars
	std::vector<float> table;
	int table_length;

	//Funcs
	Wavetable(double const &base_freq, double const &sample_rate, int* drawbar_values);
	Wavetable();
	~Wavetable();
	
	void checkTable(double const &base_freq, double const &sample_rate, int* drawbar_values);

private:
	
	// Vars
	double base_freq;
	double sample_rate;
	int* drawbar_values;

	// Funcs
	void updateTable();

};




#endif  // WAVETABLE_H_INCLUDED
