#include "Slider.h"

Slider::Slider(int minSize, int currSize,
		int maxSize, int stepSize, QWidget* parent) : QSlider(parent)
{
	this->setOrientation(Qt::Horizontal);
	this->setMinimum(minSize);
	this->setMaximum(maxSize);
	this->setSingleStep(stepSize);
	this->setValue(currSize);
}

Slider::~Slider()
{ }
