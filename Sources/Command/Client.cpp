#include "Command/Client.h"

Client::Client()
{ 
	StartDrawR = new StartDrawReciever;	
	DrawR = new DrawReciever;	
	EndDrawR = new EndDrawReciever;	
}

ComplexCommand* Client::getCommand(CommandType ReqType)
{
	switch(ReqType) {
		case CommandType::STARTDRAW: return new StartDrawCommand(StartDrawR);
		case CommandType::DRAW: return new DrawCommand(DrawR);
		case CommandType::ENDDRAW: return new EndDrawCommand(EndDrawR);
	};
}

Client::~Client()
{
	delete StartDrawR;
	delete DrawR;
	delete EndDrawR;
}
