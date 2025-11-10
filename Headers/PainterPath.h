#ifndef PAINTERPATH_H
#define PAINTERPATH_H

#include <QPainterPath>
#include <QColor>


class PainterPath {
	QColor color; 		
	QPainterPath path;	
public:
	PainterPath(QColor _color, QPainterPath _path);
	QColor getColor();
	QPainterPath getPath();
	~PainterPath();
};


#endif
