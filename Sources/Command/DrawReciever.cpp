#include "Command/DrawReciever.h"

Reciever::Reciever()
{ }
Reciever::~Reciever()
{ }

CanvasReciever::CanvasReciever() : parent(nullptr), m_event(nullptr)
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
deque<PainterPath> CanvasReciever::pathHist {};
QPainterPath CanvasReciever::path {QPainterPath()};
int CanvasReciever::currHistIndex{-1};
QColor CanvasReciever::penColor{Qt::black};
int CanvasReciever::penSize{15};


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

	for(int i {++currHistIndex}; i < histSize; ++i)
		pathHist.pop_back();

	pathHist.push_back(PainterPath(penColor, path, penSize));
	std::cout << (penColor == Qt::cyan) << std::endl;
	std::cout << "EndDraw: " << currHistIndex << std::endl;

	path.lineTo(m_event->pos());
	parent->update();
	path = QPainterPath();
}
void EndDrawReciever::undo()
{
	if(currHistIndex == -1) return;
	path = QPainterPath();
	--currHistIndex;
	parent->update();
}
void EndDrawReciever::redo()
{
	int histSize {static_cast<int>(pathHist.size())};
	if(currHistIndex >= histSize - 1) return;
	++currHistIndex;
	parent->update();
}
EndDrawReciever::~EndDrawReciever()
{ }


UpdateReciever::UpdateReciever() : CanvasReciever()
{ }
void UpdateReciever::execute()
{
	std::cout << "pathhist len: " << pathHist.size() << " currInd: " << currHistIndex << std::endl;
	QPainter painter(parent);
	for(int i {0}; i <= currHistIndex; ++i) {
		QPen pen(pathHist[i].getColor(), pathHist[i].getPenSize());
		painter.setPen(pen);
		painter.drawPath(pathHist[i].getPath());
	}
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
