/*
  ==============================================================================

    Wavetable.cpp
    Created: 16 Sep 2015 6:45:20pm
    Author:  Matt

  ==============================================================================
*/

#include "Wavetable.h"

Wavetable::Wavetable(double const &base_freq, double const &sample_rate, int* drawbar_values) :
	base_freq(base_freq),
	sample_rate(sample_rate),
	drawbar_values(drawbar_values)
{
	updateTable();
}

Wavetable::Wavetable()
{	
}

Wavetable::~Wavetable()
{
}

void Wavetable::updateTable()
{	
	double period = sample_rate / base_freq;
	double coef = (base_freq / sample_rate) * 2 * double_Pi;

	table_length = (int)(period + .5) * 2; // Round up
	table.resize(table_length);

	double* drawbar_freq = new double[DRAWBAR_COUNT]DRAWBAR_FREQ;
		
	for (int i = 0; i < table_length; ++i)
	{
		table[i] = 0.0;
		for (int j = 0; j < DRAWBAR_COUNT; ++j)
			table[i] += sin(i * (drawbar_freq[j]) * coef) * (((double)drawbar_values[j]) / DRAWBAR_NOTCHES);
		
	}
}

void Wavetable::checkTable(double const &base_freq, double const &sample_rate, int* drawbar_values)
{
	if (true || base_freq != this->base_freq || sample_rate != this->sample_rate || drawbar_values != this->drawbar_values) {
		this->base_freq = base_freq;
		this->sample_rate = sample_rate;
		this->drawbar_values = drawbar_values;
		updateTable();
	}
}