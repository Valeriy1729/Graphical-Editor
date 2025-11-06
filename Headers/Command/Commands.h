#ifndef COMMANDS_H
#define COMMANDS_H

#include "DrawReciever.h"

enum class CommandType { STARTDRAW, DRAW, ENDDRAW };

class Command {
protected:
	CommandType Type;
	bool putInHist;
public:
	Command();
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual ~Command();
};


class ComplexCommand : public Command {
protected:
	Reciever* reciever;	
	
public:
	ComplexCommand();
	virtual void execute() override;
	virtual void undo() override;
	virtual ~ComplexCommand();
};


class StartDrawCommand : public ComplexCommand {
public:
	StartDrawCommand(Reciever* _reciever);
	virtual ~StartDrawCommand();
};


class DrawCommand : public ComplexCommand {
public:
	DrawCommand(Reciever* _reciever);
	virtual ~DrawCommand();
};


class EndDrawCommand : public ComplexCommand {
public:
	EndDrawCommand(Reciever* _reciever);
	virtual ~EndDrawCommand();
};


#endif
