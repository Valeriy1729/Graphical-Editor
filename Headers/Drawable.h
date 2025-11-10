#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <QWidget>


class Drawable {
public:
	Drawable();
	virtual void draw(QWidget* canvas) = 0;
	virtual void undraw(QWidget* canvas) = 0;	
	virtual ~Drawable();
};


#endif
