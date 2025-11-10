#ifndef PAINTERPATH_H
#define PAINTERPATH_H

#include <QPainterPath>
#include <QColor>
#include "Drawable.h"


class PainterPath : public Drawable {
	QColor color; 		
	QPainterPath path;	
	int penSize;
public:
	PainterPath(QColor _color, QPainterPath _path, int _penSize);
	void draw(QWidget* canvas) override;
	void undraw(QWidget* canvas) override;
	QColor getColor();
	QPainterPath getPath();
	int getPenSize();
	~PainterPath();
};


#endif
