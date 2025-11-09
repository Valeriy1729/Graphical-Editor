#include "Command/DrawReciever.h"

Reciever::Reciever()
{ }
Reciever::~Reciever()
{ }

CanvasReciever::CanvasReciever() : parent(nullptr), m_event(nullptr), currHistIndex(-1)
{ }
CanvasReciever::~CanvasReciever()
{ }
void CanvasReciever::setFields(QWidget* _parent, QMouseEvent* _m_event, QColor _penColor, int _penSize)
{
	parent = _parent;
	m_event = _m_event;
	penColor = _penColor;
	penSize = _penSize;
}
deque<QPainterPath> CanvasReciever::pathHist {};
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
void DrawReciever::redo()
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
void StartDrawReciever::redo()
{ }
StartDrawReciever::~StartDrawReciever()
{ }


EndDrawReciever::EndDrawReciever() : CanvasReciever()
{ }
void EndDrawReciever::execute()
{
	int histSize {static_cast<int>(pathHist.size())};
	int MAX_HIST_LEN {static_cast<int>(Reciever_Consts::MAX_HIST_LEN)};

	for(int i {++currHistIndex}; i < histSize; ++i)
		pathHist.pop_back();

	pathHist.push_back(path);
	if (histSize > MAX_HIST_LEN) {
		pathHist.pop_front();
		--currHistIndex;
	}

	path.lineTo(m_event->pos());
	parent->update();
}
void EndDrawReciever::undo()
{
	if(currHistIndex == -1) return;
	if(currHistIndex == 0) {
		path = QPainterPath();
		--currHistIndex;
	} else
		path = pathHist[--currHistIndex];
	parent->update();
}
void EndDrawReciever::redo()
{
	int histSize {static_cast<int>(pathHist.size())};
	if(currHistIndex >= histSize - 1) return;
	++currHistIndex;
	path = pathHist[currHistIndex++];
	--currHistIndex;
	parent->update();
}
EndDrawReciever::~EndDrawReciever()
{ }


UpdateReciever::UpdateReciever() : CanvasReciever()
{ }
void UpdateReciever::execute()
{
	QPainter painter(parent);
	QPen pen(penColor, penSize);
	painter.setPen(pen);
	painter.drawPath(path);
	painter.end();
}
void UpdateReciever::undo()
{ }
void UpdateReciever::redo()
{ }
UpdateReciever::~UpdateReciever()
{ }
