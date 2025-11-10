#include "PainterPath.h"

PainterPath::PainterPath(QColor _color, QPainterPath _path, int _penSize) :
	color(_color), path(_path), penSize(_penSize)
{ }

void PainterPath::draw(QWidget* canvas)
{ }

void PainterPath::undraw(QWidget* canvas)
{ }

QColor PainterPath::getColor()
{
	return color;	
}

QPainterPath PainterPath::getPath()
{
	return path;	
}

int PainterPath::getPenSize()
{
	return penSize;	
}

PainterPath::~PainterPath()
{ }
