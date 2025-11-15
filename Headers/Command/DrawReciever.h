#ifndef DRAWRECIEVER_H
#define DRAWRECIEVER_H

#include <QWidget>
#include <QColor>
#include <QPainterPath>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <deque>
#include <iostream>
#include "PainterPath.h"

using std::deque;
class CanvasCommand;


class Reciever {
public:
	Reciever();
	virtual void execute() = 0;
	virtual void undo() = 0;	
	virtual void redo() = 0;
	virtual ~Reciever();
};


class DrawOnCanvasReciever : public Reciever {
protected:
	static deque<Path*> drawHist;	
	static int currHistIndex;
	QWidget* parent;
	QMouseEvent* m_event;
public:
	DrawOnCanvasReciever();
	virtual void setFields(QWidget* parent, QMouseEvent* _m_event,
				QColor _penColor, int _penSize);
	virtual void setFields(QWidget* parent, QMouseEvent* _m_event,
				int _width, int _height, QString _name);
	virtual void setFields(QWidget* parent, QMouseEvent* _m_event, QString _text);
	virtual ~DrawOnCanvasReciever();	
};


class DrawWidgetReciever : public DrawOnCanvasReciever {
public:
	DrawWidgetReciever();
	virtual ~DrawWidgetReciever();
};


class BrushReciever : public DrawOnCanvasReciever {
protected:
	static QPainterPath path;	
	static QColor penColor;
	static int penSize;
public:
	BrushReciever();
	virtual void setFields(QWidget* parent, QMouseEvent* _m_event,
			QColor _penColor, int _penSize) override;
	virtual ~BrushReciever();
};


class DrawReciever : public BrushReciever {
public:
	DrawReciever();
	virtual void execute() override;
	virtual void undo() override;	
	virtual void redo() override;
	virtual ~DrawReciever();
};


class StartDrawReciever : public BrushReciever {
public:
	StartDrawReciever();
	virtual void execute() override;
	virtual void undo() override;	
	virtual void redo() override;
	virtual ~StartDrawReciever();
};


class EndDrawReciever : public BrushReciever {
public:
	EndDrawReciever();
	virtual void execute() override;
	virtual void undo() override;	
	virtual void redo() override;
	virtual ~EndDrawReciever();
};


class UpdateReciever : public BrushReciever {
public:
	UpdateReciever();
	virtual void execute() override;
	virtual void undo() override;	
	virtual void redo() override;
	virtual ~UpdateReciever();
};


class ImageReciever : public DrawWidgetReciever {
	int width, height;
	QString name;
public:
	ImageReciever();
	virtual void execute() override;
	virtual void undo() override;	
	virtual void redo() override;
	virtual void setFields(QWidget* _parent, QMouseEvent* _m_event,
				int _width, int _height, QString _name) override;
	virtual ~ImageReciever();
};


class TextReciever : public DrawWidgetReciever {
	QString text;
public:
	TextReciever();
	virtual void execute() override;
	virtual void undo() override;	
	virtual void redo() override;
	virtual void setFields(QWidget* _parent, QMouseEvent* _m_event, QString _text) override;
	virtual ~TextReciever();
};


#endif
