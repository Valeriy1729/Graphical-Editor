#include "Command/Commands.h"

Command::Command()
{ }
bool Command::getHistoryFlag()
{
	return putInHist;	
}
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


CanvasCommand::CanvasCommand(CanvasReciever* _canvasReciever, QWidget* _parent, QMouseEvent* _m_event) :
	canvasReciever(_canvasReciever), parent(_parent), m_event(_m_event)
{ }
CanvasCommand::~CanvasCommand()
{ }
void CanvasCommand::execute()
{
	canvasReciever->setFields(nullptr, nullptr);

	canvasReciever->setFields(parent, m_event);
	canvasReciever->execute();
}
void CanvasCommand::undo()
{
	canvasReciever->undo();	
}


StartDrawCommand::StartDrawCommand(CanvasReciever* _canvasReciever, QWidget* _parent, QMouseEvent* _m_event) : 
	CanvasCommand(_canvasReciever, _parent, _m_event)
{
	Type = CommandType::STARTDRAW; putInHist = false;
}
StartDrawCommand::~StartDrawCommand()
{ }


DrawCommand::DrawCommand(CanvasReciever* _canvasReciever, QWidget* _parent, QMouseEvent* _m_event) :
	CanvasCommand(_canvasReciever, _parent, _m_event)
{
	Type = CommandType::DRAW; putInHist = false;
}
DrawCommand::~DrawCommand()
{ }


EndDrawCommand::EndDrawCommand(CanvasReciever* _canvasReciever, QWidget* _parent, QMouseEvent* _m_event) :
	CanvasCommand(_canvasReciever, _parent, _m_event)
{
	Type = CommandType::ENDDRAW; putInHist = true;
}
EndDrawCommand::~EndDrawCommand()
{ }


UpdateCommand::UpdateCommand(CanvasReciever* _canvasReciever, QWidget* _parent) :
	CanvasCommand(_canvasReciever, _parent)
{
	Type = CommandType::UPDATE; putInHist = false;
}
UpdateCommand::~UpdateCommand()
{ }
