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


DrawOnCanvasCommand::DrawOnCanvasCommand(DrawOnCanvasReciever* _drawOnCavasReciever,
	QWidget* _parent, QMouseEvent* _m_event) :
	reciever(_drawOnCavasReciever), parent(_parent), m_event(_m_event)
{ }
DrawOnCanvasCommand::~DrawOnCanvasCommand()
{ }


DrawWidgetCommand::DrawWidgetCommand(DrawWidgetReciever* _drawWidgetReciever, QWidget* _parent, QMouseEvent* _m_event) :
	DrawOnCanvasCommand(_drawWidgetReciever, _parent, _m_event)
{ }
DrawWidgetCommand::~DrawWidgetCommand()
{ }
void DrawWidgetCommand::undo()
{
	reciever->undo();
}
void DrawWidgetCommand::redo()
{
	reciever->redo();
}


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
	reciever->setFields(parent, m_event, penColor, penSize);
	reciever->execute();
}
void BrushCommand::undo()
{
	reciever->undo();	
}
void BrushCommand::redo()
{
	reciever->redo();	
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


ImageCommand::ImageCommand(DrawWidgetReciever* _drawWidgetReciever, QWidget* _parent, QMouseEvent* _m_event,
				int _width, int _height, QString _name) :
	DrawWidgetCommand(_drawWidgetReciever, _parent, _m_event), width(_width), height(_height), name(_name)
{
	Type = CommandType::ADDIMAGE; putInHist = true;
}
void ImageCommand::execute()
{
	reciever->setFields(parent, m_event, width, height, name);
	reciever->execute();
}
ImageCommand::~ImageCommand()
{ }

TextCommand::TextCommand(DrawWidgetReciever* _drawWidgetReciever, QWidget* _parent,
		QMouseEvent* _m_event, QString _text) :
	DrawWidgetCommand(_drawWidgetReciever, _parent, _m_event), text(_text)
{
	Type = CommandType::ADDIMAGE; putInHist = true;
}
void TextCommand::execute()
{
	reciever->setFields(parent, m_event, text);
	reciever->execute();
}
TextCommand::~TextCommand()
{ }
