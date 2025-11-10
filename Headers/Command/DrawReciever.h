#ifndef DRAWRECIEVER_H
#define DRAWRECIEVER_H

#include <QWidget>
#include <QColor>
#include <QPainterPath>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
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


class CanvasReciever : public Reciever {
protected:
	static deque<PainterPath> pathHist;
	static QPainterPath path;	
	static int currHistIndex;
	static QColor penColor;
	static int penSize;
	QWidget* parent;
	QMouseEvent* m_event;
public:
	CanvasReciever();
	void setFields(QWidget* parent, QMouseEvent* _m_event,
			QColor _penColor, int _penSize);
	virtual ~CanvasReciever();
};


class DrawReciever : public CanvasReciever {
public:
	DrawReciever();
	virtual void execute() override;
	virtual void undo() override;	
	virtual void redo() override;
	virtual ~DrawReciever();
};


class StartDrawReciever : public CanvasReciever {
public:
	StartDrawReciever();
	virtual void execute() override;
	virtual void undo() override;	
	virtual void redo() override;
	virtual ~StartDrawReciever();
};


class EndDrawReciever : public CanvasReciever {
public:
	EndDrawReciever();
	virtual void execute() override;
	virtual void undo() override;	
	virtual void redo() override;
	virtual ~EndDrawReciever();
};


class UpdateReciever : public CanvasReciever {
public:
	UpdateReciever();
	virtual void execute() override;
	virtual void undo() override;	
	virtual void redo() override;
	virtual ~UpdateReciever();
};

#endif
