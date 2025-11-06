#include "Command/Commands.h"

Command::Command()
{ }
Command::~Command()
{ }


ComplexCommand::ComplexCommand() : reciever(nullptr)
{ }
ComplexCommand::~ComplexCommand()
{ }
void ComplexCommand::execute()
{
	reciever->execute();		
}
void ComplexCommand::undo()
{
	reciever->undo();		
}


StartDrawCommand::StartDrawCommand(Reciever* _reciever)
{
	Type = CommandType::STARTDRAW; reciever = _reciever; putInHist = false;
}
StartDrawCommand::~StartDrawCommand()
{ }


DrawCommand::DrawCommand(Reciever* _reciever)
{
	Type = CommandType::DRAW; reciever = _reciever; putInHist = false;
}
DrawCommand::~DrawCommand()
{ }


EndDrawCommand::EndDrawCommand(Reciever* _reciever)
{
	Type = CommandType::ENDDRAW; reciever = _reciever; putInHist = true;
}
EndDrawCommand::~EndDrawCommand()
{ }
