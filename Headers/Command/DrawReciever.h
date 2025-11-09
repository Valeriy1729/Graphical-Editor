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

using std::deque;
class CanvasCommand;

enum class Reciever_Consts { MAX_HIST_LEN = 17 };


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
	static deque<QPainterPath> pathHist;
	static QPainterPath path;	
	QWidget* parent;
	QMouseEvent* m_event;
	QColor penColor;
	int penSize;
	int currHistIndex;
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
