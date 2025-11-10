#include "PainterPath.h"

PainterPath::PainterPath(QColor _color, QPainterPath _path) : color(_color), path(_path)
{ }

QColor PainterPath::getColor()
{
	return color;	
}

QPainterPath PainterPath::getPath()
{
	return path;	
}

PainterPath::~PainterPath()
{ }
