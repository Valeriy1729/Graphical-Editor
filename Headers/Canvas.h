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
#include <QInputDialog>
#include <QLineEdit>
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
	bool imageMode;
	bool textMode;
	int width, height;
	QString name;
	QString text;

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

public slots:
	void slot_add_image();
	void slot_add_text();
};


#endif
