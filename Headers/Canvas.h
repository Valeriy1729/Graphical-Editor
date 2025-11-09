#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <chrono>
#include <thread>

#include <iostream>
#include <QMouseEvent>
#include <QPainter>
#include <QGridLayout>
#include <QPainterPath>
#include <vector>
#include "Command/Client.h"
#include "Command/Invoker.h"
#include "Command/DrawReciever.h"

using std::cout;
using std::endl;


class Canvas : public QWidget {
	Q_OBJECT
	Invoker* invoker;
	Client* client;
	QColor penColor;
	int penSize;
public:
	Canvas(QWidget* parent=nullptr);
	void setInvoker(Invoker* _invoker);
	void setClient(Client* _client);
	void setPenColor(QColor _penColor);
	void setPenSize(int _penSize);

	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void paintEvent(QPaintEvent* event) override;

	~Canvas();
};


#endif
