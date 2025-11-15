#include "Command/Client.h"

Client::Client()
{ 
	DrawR = new DrawReciever;	
	StartDrawR = new StartDrawReciever;	
	EndDrawR = new EndDrawReciever;	
	UpdateR = new UpdateReciever;	
	ImageR = new ImageReciever;
	TextR = new TextReciever;
}

BrushCommand* Client::getBrushCommand(CommandType ReqType, QWidget* parent, QMouseEvent* event)
{
	switch(ReqType) {
		case CommandType::DRAW: return new DrawCommand(DrawR, parent, event);
		case CommandType::STARTDRAW: return new StartDrawCommand(StartDrawR, parent, event);
		case CommandType::ENDDRAW: return new EndDrawCommand(EndDrawR, parent, event);
		case CommandType::ADDIMAGE: break;
		case CommandType::UPDATE: break;
	};
	throw std::exception();
}

BrushCommand* Client::getBrushCommand(CommandType ReqType, QWidget* parent, QColor penColor, int penSize)
{
	if(ReqType != CommandType::UPDATE) throw std::exception();
	return new UpdateCommand(UpdateR, parent, penColor, penSize);
}

ImageCommand* Client::getImageCommand(QWidget* parent, int width, int height, QMouseEvent* event, QString name)
{
	return new ImageCommand(ImageR, parent, event, width, height, name);
}

TextCommand* Client::getTextCommand(QWidget* parent, QMouseEvent* event, QString text)
{
	return new TextCommand(TextR, parent, event, text);
}

Client::~Client()
{
	delete DrawR;
	delete StartDrawR;
	delete EndDrawR;
	delete UpdateR;
	delete ImageR;
	delete TextR;
}
