#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>


class Canvas : public QWidget {
	Q_OBJECT
	QPainterPath path;
public:
	Canvas(QWidget* parent=nullptr);
	~Canvas();

};


#endif
