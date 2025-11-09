#include "Command/Client.h"

Client::Client()
{ 
	DrawR = new DrawReciever();	
	StartDrawR = new StartDrawReciever();	
	EndDrawR = new EndDrawReciever();	
	UpdateR = new UpdateReciever();	
}

CanvasCommand* Client::getCanvasCommand(CommandType ReqType, QWidget* parent, QMouseEvent* event)
{
	switch(ReqType) {
		case CommandType::DRAW: return new DrawCommand(DrawR, parent, event);
		case CommandType::STARTDRAW: return new StartDrawCommand(StartDrawR, parent, event);
		case CommandType::ENDDRAW: return new EndDrawCommand(EndDrawR, parent, event);
		case CommandType::UPDATE: break;
	};
	throw std::exception();
}

CanvasCommand* Client::getCanvasCommand(CommandType ReqType, QWidget* parent, QColor penColor, int penSize)
{
	if(ReqType != CommandType::UPDATE) throw std::exception();
	return new UpdateCommand(UpdateR, parent, penColor, penSize);
}

Client::~Client()
{
	delete DrawR;
	delete StartDrawR;
	delete EndDrawR;
	delete UpdateR;
}
