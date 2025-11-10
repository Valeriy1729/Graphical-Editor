#ifndef PAINTERPATH_H
#define PAINTERPATH_H

#include <QPainterPath>
#include <QColor>


class PainterPath {
	QColor color; 		
	QPainterPath path;	
	int penSize;
public:
	PainterPath(QColor _color, QPainterPath _path, int _penSize);
	QColor getColor();
	QPainterPath getPath();
	int getPenSize();
	~PainterPath();
};


#endif
