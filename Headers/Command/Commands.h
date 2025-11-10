#ifndef COMMANDS_H
#define COMMANDS_H

#include <QWidget>
#include <QColor>
#include "DrawReciever.h"

enum class CommandType { STARTDRAW, DRAW, ENDDRAW, UPDATE, ADDIMAGE };


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


class DrawOnCanvasCommand : public Command {
protected:
	BrushReciever* brushReciever;
	QWidget* parent;
	QMouseEvent* m_event;
public:
	DrawOnCanvasCommand(BrushReciever* _brushReciever, QWidget* _parent, QMouseEvent* _m_event);
	virtual ~DrawOnCanvasCommand();
};


class DrawWidgetCommand : public DrawOnCanvasCommand {
public:
	DrawWidgetCommand(BrushReciever* _brushReciever, QWidget* _parent, QMouseEvent* _m_event);
	virtual void execute() override;
	virtual void undo() override;
	virtual void redo() override;
	virtual ~DrawWidgetCommand();
};


class ImageCommand : public DrawWidgetCommand {
	int width, heigth;
	int x_cor, y_cor;
public:
	ImageCommand(BrushReciever* _brushReciever, QWidget* _parent, QMouseEvent* _event);
	virtual ~ImageCommand();
};


class BrushCommand : public DrawOnCanvasCommand {
protected:
	static QColor penColor;
	static int penSize;
public:
	BrushCommand(BrushReciever* _brushReciever,
	      		QWidget* _parent, QMouseEvent* _m_event);
	BrushCommand(BrushReciever* _brushReciever,
			QWidget* _parent, QColor _penColor, int _penSize);
	virtual void execute() override;
	virtual void undo() override;
	virtual void redo() override;
	virtual ~BrushCommand();
};


class StartDrawCommand : public BrushCommand {
public:
	StartDrawCommand(BrushReciever* _brushReciever, QWidget* _parent, QMouseEvent* _event);
	virtual ~StartDrawCommand();
};


class DrawCommand : public BrushCommand {
public:
	DrawCommand(BrushReciever* _brushReciever, QWidget* _parent, QMouseEvent* _event);
	virtual ~DrawCommand();
};


class EndDrawCommand : public BrushCommand {
public:
	EndDrawCommand(BrushReciever* _brushReciever, QWidget* _parent, QMouseEvent* _event);
	virtual ~EndDrawCommand();
};


class UpdateCommand : public BrushCommand {
public:
	UpdateCommand(BrushReciever* _brushReciever, QWidget* _parent, QColor _penColor, int _penSize);
	virtual ~UpdateCommand();
};


#endif
