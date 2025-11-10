#ifndef SLIDER_H
#define SLIDER_H

#include <QSlider>


class Slider : public QSlider {
	Q_OBJECT
public:
	Slider(int minSize, int currSize, int maxSize,
		int stepSize, QWidget* parent=nullptr);
	~Slider();	
};


#endif
