#include "Command/DrawReciever.h"

Reciever::Reciever()
{ }
Reciever::~Reciever()
{ }


DrawOnCanvasReciever::DrawOnCanvasReciever() : parent(nullptr), m_event(nullptr)
{ }
DrawOnCanvasReciever::~DrawOnCanvasReciever()
{ }
void DrawOnCanvasReciever::setFields(QWidget* _parent,
		QMouseEvent* _m_event, QColor _penColor, int _penSize)
{ }
void DrawOnCanvasReciever::setFields(QWidget* _parent,
		QMouseEvent* _m_event, int _width, int _height, QString _name)
{ }
void DrawOnCanvasReciever::setFields(QWidget* _parent,
		QMouseEvent* _m_event, QString _text)
{ }
deque<Path*> DrawOnCanvasReciever::drawHist {};
int DrawOnCanvasReciever::currHistIndex{-1};


DrawWidgetReciever::DrawWidgetReciever()
{ }
DrawWidgetReciever::~DrawWidgetReciever()
{ }


BrushReciever::BrushReciever()
{ }
BrushReciever::~BrushReciever()
{ }
void BrushReciever::setFields(QWidget* _parent,
		QMouseEvent* _m_event, QColor _penColor, int _penSize)
{
	parent = _parent;
	m_event = _m_event;
	penColor = _penColor;
	penSize = _penSize;
}
QColor BrushReciever::penColor{Qt::black};
int BrushReciever::penSize{15};
QPainterPath BrushReciever::path {QPainterPath()};


DrawReciever::DrawReciever() : BrushReciever()
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


StartDrawReciever::StartDrawReciever() : BrushReciever()
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


EndDrawReciever::EndDrawReciever() : BrushReciever()
{ }
void EndDrawReciever::execute()
{
	int histSize {static_cast<int>(drawHist.size())};

	Path* tmpPath;
	for(int i {++currHistIndex}; i < histSize; ++i) {
		tmpPath = drawHist.back();
		drawHist.pop_back();
		delete tmpPath;
	}

	drawHist.push_back(new PainterPath(penColor, path, penSize));

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
	int histSize {static_cast<int>(drawHist.size())};
	if(currHistIndex >= histSize - 1) return;
	++currHistIndex;
	parent->update();
}
EndDrawReciever::~EndDrawReciever()
{ }


UpdateReciever::UpdateReciever() : BrushReciever()
{ }
void UpdateReciever::execute()
{
	QPainter painter(parent);
	for(int i {0}; i <= currHistIndex; ++i) {
		drawHist[i]->draw(&painter);
	}
	QPen pen(penColor, penSize);
	pen.setCapStyle(Qt::RoundCap);
	pen.setJoinStyle(Qt::RoundJoin);
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

ImageReciever::ImageReciever() : DrawWidgetReciever()
{ }
void ImageReciever::execute()
{
	int histSize {static_cast<int>(drawHist.size())};

	Path* tmpPath;
	for(int i {++currHistIndex}; i < histSize; ++i) {
		tmpPath = drawHist.back();
		drawHist.pop_back();
		delete tmpPath;
	}

	drawHist.push_back(new ImagePath(m_event->x(), m_event->y(), width, height, name));
	parent->update();
}
void ImageReciever::undo()
{
	if(currHistIndex == -1) return;
	--currHistIndex;
	parent->update();
}
void ImageReciever::redo()
{
	int histSize {static_cast<int>(drawHist.size())};
	if(currHistIndex >= histSize - 1) return;
	++currHistIndex;
	parent->update();
}
void ImageReciever::setFields(QWidget* _parent, QMouseEvent* _m_event, int _width, int _height, QString _name)
{
	parent = _parent;
	m_event = _m_event;
	width = _width;
	height = _height;
	name = _name;
}
ImageReciever::~ImageReciever()
{ }


TextReciever::TextReciever() : DrawWidgetReciever()
{ }
void TextReciever::execute()
{
	int histSize {static_cast<int>(drawHist.size())};

	Path* tmpPath;
	for(int i {++currHistIndex}; i < histSize; ++i) {
		tmpPath = drawHist.back();
		drawHist.pop_back();
		delete tmpPath;
	}

	drawHist.push_back(new TextPath(m_event->x(), m_event->y(), text));
	parent->update();
}
void TextReciever::undo()
{
	if(currHistIndex == -1) return;
	--currHistIndex;
	parent->update();
}
void TextReciever::redo()
{
	int histSize {static_cast<int>(drawHist.size())};
	if(currHistIndex >= histSize - 1) return;
	++currHistIndex;
	parent->update();
}
void TextReciever::setFields(QWidget* _parent, QMouseEvent* _m_event, QString _text)
{
	parent = _parent;
	m_event = _m_event;
	text = _text;
}
TextReciever::~TextReciever()
{ }
