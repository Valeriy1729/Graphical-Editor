#include "Command/DrawReciever.h"

Reciever::Reciever()
{ }
Reciever::~Reciever()
{ }

CanvasReciever::CanvasReciever() : parent(nullptr), m_event(nullptr)
{ }
CanvasReciever::~CanvasReciever()
{ }
void CanvasReciever::setFields(QWidget* _parent, QMouseEvent* _m_event)
{
	parent = _parent;
	m_event = _m_event;
}
deque<QPainterPath> CanvasReciever::pathHist {QPainterPath()};
QPainterPath CanvasReciever::path {QPainterPath()};


DrawReciever::DrawReciever() : CanvasReciever()
{ }
void DrawReciever::execute()
{
	path.lineTo(m_event->pos());
	parent->update();
}
void DrawReciever::undo()
{ }
DrawReciever::~DrawReciever()
{ }


StartDrawReciever::StartDrawReciever() : CanvasReciever()
{ }
void StartDrawReciever::execute()
{
	path.moveTo(m_event->pos());
	path.lineTo(m_event->pos());
	parent->update();
}
void StartDrawReciever::undo()
{ }
StartDrawReciever::~StartDrawReciever()
{ }


EndDrawReciever::EndDrawReciever() : CanvasReciever()
{ }
void EndDrawReciever::execute()
{
	std::cout << "added to EndDrawReciever hist" << std::endl;
	pathHist.push_back(path);
	path.lineTo(m_event->pos());
	parent->update();
}
void EndDrawReciever::undo()
{
	if(pathHist.size() == 1) { std::cout << "nope" << std::endl; return; }
	pathHist.pop_back();
	path = pathHist.back();
	parent->update();
}
EndDrawReciever::~EndDrawReciever()
{ }


UpdateReciever::UpdateReciever() : CanvasReciever()
{ }
void UpdateReciever::execute()
{
	QPainter painter(parent);
	QPen pen(Qt::red, 50);
	painter.setPen(pen);
	painter.drawPath(path);
	painter.end();
}
void UpdateReciever::undo()
{ }
UpdateReciever::~UpdateReciever()
{ }
