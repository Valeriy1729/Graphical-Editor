#ifndef COMMANDS_H
#define COMMANDS_H

#include <QWidget>
#include <QColor>
#include "DrawReciever.h"

enum class CommandType { STARTDRAW, DRAW, ENDDRAW, UPDATE };


class Command {
protected:
	CommandType Type;
	bool putInHist;
public:
	Command();
	bool getHistoryFlag();
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual void redo() = 0;
	virtual ~Command();
};


class ComplexCommand : public Command {
protected:
	Reciever* reciever;	
public:
	ComplexCommand();
	virtual void execute() override;
	virtual void undo() override;
	virtual void redo() override;
	virtual ~ComplexCommand();
};


class CanvasCommand : public Command {
protected:
	CanvasReciever* canvasReciever;
	QWidget* parent;
	QMouseEvent* m_event;
	static QColor penColor;
	static int penSize;
public:
	CanvasCommand(CanvasReciever* _canvasReciever,
	      		QWidget* _parent, QMouseEvent* _m_event);
	CanvasCommand(CanvasReciever* _canvasReciever,
			QWidget* _parent, QColor _penColor, int _penSize);
	virtual void execute() override;
	virtual void undo() override;
	virtual void redo() override;
	virtual ~CanvasCommand();
};


class StartDrawCommand : public CanvasCommand {
public:
	StartDrawCommand(CanvasReciever* _canvasReciever, QWidget* _parent, QMouseEvent* _event);
	virtual ~StartDrawCommand();
};


class DrawCommand : public CanvasCommand {
public:
	DrawCommand(CanvasReciever* _canvasReciever, QWidget* _parent, QMouseEvent* _event);
	virtual ~DrawCommand();
};


class EndDrawCommand : public CanvasCommand {
public:
	EndDrawCommand(CanvasReciever* _canvasReciever, QWidget* _parent, QMouseEvent* _event);
	virtual ~EndDrawCommand();
};


class UpdateCommand : public CanvasCommand {
public:
	UpdateCommand(CanvasReciever* _canvasReciever, QWidget* _parent, QColor _penColor, int _penSize);
	virtual ~UpdateCommand();
};

#endif
