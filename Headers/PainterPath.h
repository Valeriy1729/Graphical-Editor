#ifndef PAINTERPATH_H
#define PAINTERPATH_H

#include <QPaintDevice>
#include <QPainter>
#include <QImage>
#include <QPen>
#include <QPainterPath>
#include <QColor>
#include <iostream>


class Path {
public:
	Path();
	virtual void draw(QPainter* painter) = 0;
	virtual void undraw(QPainter* painter) = 0;
	virtual ~Path();
};

class PainterPath : public Path {
	QColor color; 		
	QPainterPath path;	
	int penSize;

public:
	PainterPath(QColor _color={}, QPainterPath _path={}, int _penSize={});
	virtual void draw(QPainter* painter) override;
	virtual void undraw(QPainter* painter) override;
	virtual QColor getColor();
	virtual QPainterPath getPath();
	virtual int getPenSize();
	virtual ~PainterPath();
};


class ImagePath : public Path {
	int x_cor, y_cor;
	int width, height;
	QString name;
public:
	ImagePath(int _x_cor, int _y_cor, int _width, int _height, QString _name);
	virtual void draw(QPainter* painter) override;
	virtual void undraw(QPainter* painter) override;
	virtual ~ImagePath();
};


class TextPath : public Path {
	int x_cor, y_cor;
	QString text;
public:
	TextPath(int _x_cor, int _y_cor, QString _text);
	virtual void draw(QPainter* painter) override;
	virtual void undraw(QPainter* painter) override;
	virtual ~TextPath();
};
#endif
