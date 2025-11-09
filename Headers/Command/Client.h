#ifndef CLIENT_H
#define CLIENT_H

#include <exception>
#include <QWidget>
#include "Command/Commands.h"
#include "Command/DrawReciever.h"


class Client {
	DrawReciever* DrawR;
	StartDrawReciever* StartDrawR;
	EndDrawReciever* EndDrawR;
	UpdateReciever* UpdateR;
public:
	Client();
	CanvasCommand* getCanvasCommand(CommandType ReqType, QWidget* parent, QMouseEvent* event);
	CanvasCommand* getCanvasCommand(CommandType ReqType, QWidget* parent);
	~Client();
};


#endif
