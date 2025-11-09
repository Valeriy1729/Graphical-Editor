#include "Canvas.h"

Canvas::Canvas(QWidget* parent) : QWidget(parent)
{ }

void Canvas::setInvoker(Invoker* _invoker)
{
	invoker = _invoker;	
}

void Canvas::setClient(Client* _client)
{
	client = _client;
}

void Canvas::mousePressEvent(QMouseEvent* event)
{
	if(event->button() == Qt::LeftButton)
		invoker->execute(client->getCanvasCommand(CommandType::STARTDRAW, this, event));
	else if(event->button() == Qt::RightButton)
		invoker->undo();
	else if(event->button() == Qt::MiddleButton)
		invoker->redo();
}

void Canvas::mouseMoveEvent(QMouseEvent* event)
{
	if(event->buttons() & Qt::LeftButton)
		invoker->execute(client->getCanvasCommand(CommandType::DRAW, this, event));
}

void Canvas::mouseReleaseEvent(QMouseEvent* event)
{
	if(event->button() == Qt::LeftButton)
		invoker->execute(client->getCanvasCommand(CommandType::ENDDRAW, this, event));
}

void Canvas::paintEvent(QPaintEvent* event)
{
	invoker->execute(client->getCanvasCommand(CommandType::UPDATE, this));
}

Canvas::~Canvas()
{ }
