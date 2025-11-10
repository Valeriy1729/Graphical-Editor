#include "Command/Commands.h"

Command::Command()
{ }
bool Command::getHistoryFlag()
{
	return putInHist;	
}
Command::~Command()
{ }


ComplexCommand::ComplexCommand()
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
void ComplexCommand::redo()
{
	reciever->redo();	
}


DrawOnCanvasCommand::DrawOnCanvasCommand(BrushReciever* _brushReciever, QWidget* _parent, QMouseEvent* _m_event) :
	brushReciever(_brushReciever), parent(_parent), m_event(_m_event)
{ }
DrawOnCanvasCommand::~DrawOnCanvasCommand()
{ }


DrawWidgetCommand::DrawWidgetCommand(BrushReciever* _brushReciever, QWidget* _parent, QMouseEvent* _m_event) :
	DrawOnCanvasCommand(_brushReciever, _parent, _m_event)
{ }
DrawWidgetCommand::~DrawWidgetCommand()
{ }
void DrawWidgetCommand::execute()
{ }
void DrawWidgetCommand::undo()
{ }
void DrawWidgetCommand::redo()
{ }


BrushCommand::BrushCommand(BrushReciever* _brushReciever, QWidget* _parent, QMouseEvent* _m_event) :
	DrawOnCanvasCommand(_brushReciever, _parent, _m_event)
{ }
BrushCommand::BrushCommand(BrushReciever* _brushReciever, QWidget* _parent, QColor _penColor, int _penSize) :
	DrawOnCanvasCommand(_brushReciever, _parent, nullptr)
{
	penColor = _penColor; penSize = _penSize;
}
BrushCommand::~BrushCommand()
{ }
void BrushCommand::execute()
{
	brushReciever->setFields(parent, m_event, penColor, penSize);
	brushReciever->execute();
}
void BrushCommand::undo()
{
	brushReciever->undo();	
}
void BrushCommand::redo()
{
	brushReciever->redo();	
}
QColor BrushCommand::penColor {Qt::black};
int BrushCommand::penSize {15};


StartDrawCommand::StartDrawCommand(BrushReciever* _brushReciever, QWidget* _parent, QMouseEvent* _m_event) : 
	BrushCommand(_brushReciever, _parent, _m_event)
{
	Type = CommandType::STARTDRAW; putInHist = false;
}
StartDrawCommand::~StartDrawCommand()
{ }


DrawCommand::DrawCommand(BrushReciever* _brushReciever, QWidget* _parent, QMouseEvent* _m_event) :
	BrushCommand(_brushReciever, _parent, _m_event)
{
	Type = CommandType::DRAW; putInHist = false;
}
DrawCommand::~DrawCommand()
{ }


EndDrawCommand::EndDrawCommand(BrushReciever* _brushReciever, QWidget* _parent, QMouseEvent* _m_event) :
	BrushCommand(_brushReciever, _parent, _m_event)
{
	Type = CommandType::ENDDRAW; putInHist = true;
}
EndDrawCommand::~EndDrawCommand()
{ }


UpdateCommand::UpdateCommand(BrushReciever* _brushReciever, QWidget* _parent, QColor _penColor, int _penSize) :
	BrushCommand(_brushReciever, _parent, _penColor, _penSize)
{
	Type = CommandType::UPDATE; putInHist = false;
}
UpdateCommand::~UpdateCommand()
{ }


ImageCommand::ImageCommand(BrushReciever* _brushReciever, QWidget* _parent, QMouseEvent* _m_event) :
	DrawWidgetCommand(_brushReciever, _parent, _m_event)
{
	Type = CommandType::ADDIMAGE; putInHist = true;
}
ImageCommand::~ImageCommand()
{ }
