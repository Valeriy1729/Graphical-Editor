#include "PainterPath.h"

Path::Path()
{ }
Path::~Path()
{ }

PainterPath::PainterPath(QColor _color, QPainterPath _path, int _penSize) :
	color(_color), path(_path), penSize(_penSize)
{ }
void PainterPath::draw(QPainter* painter)
{
	QPen pen(color, penSize);
	pen.setCapStyle(Qt::RoundCap);
	pen.setJoinStyle(Qt::RoundJoin);
	painter->setPen(pen);
	painter->drawPath(path);
}
void PainterPath::undraw(QPainter* painter)
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


ImagePath::ImagePath(int _x_cor, int _y_cor, int _width, int _height, QString _name) : 
	x_cor(_x_cor), y_cor(_y_cor), width(_width), height(_height), name(_name)
{ }
void ImagePath::draw(QPainter* painter)
{
	QImage image(name);
	QImage simage = image.scaled(width, height);
	painter->drawImage(x_cor, y_cor, simage);
}
void ImagePath::undraw(QPainter* painter)
{ }
ImagePath::~ImagePath()
{ }


TextPath::TextPath(int _x_cor, int _y_cor, QString _text) :
	x_cor(_x_cor), y_cor(_y_cor), text(_text)
{ }
void TextPath::draw(QPainter* painter)
{
	QFont font {"Arial", 30};
	font.setBold(true);
	painter->setFont(font);
	painter->drawText(x_cor, y_cor, text);
}
void TextPath::undraw(QPainter* painter)
{ }
TextPath::~TextPath()
{ }
