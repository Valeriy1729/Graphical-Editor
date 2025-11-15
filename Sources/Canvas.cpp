#include "Canvas.h"

Canvas::Canvas(QWidget* parent) : QWidget(parent)
{
	penColor = Qt::black;
	penSize = 15;
	imageMode = false;
}

void Canvas::setInvoker(Invoker* _invoker)
{
	invoker = _invoker;	
}

void Canvas::setClient(Client* _client)
{
	client = _client;
}

void Canvas::setPenColor(QColor _penColor)
{
	penColor = _penColor;	
}

void Canvas::setPenSize(int _penSize)
{
	penSize = _penSize;
}

void Canvas::slot_add_image()
{
	bool ok1, ok2, ok3;
	if(imageMode == true) return;
	imageMode = true;	
	name = QInputDialog::getText(this, tr("Image path"), tr("path:"), QLineEdit::Normal, "...", &ok1);
	width = QInputDialog::getText(this, tr("Image width"), tr("value:"), QLineEdit::Normal, "...", &ok2).toInt(&ok2);
	height = QInputDialog::getText(this, tr("Image height"), tr("value:"), QLineEdit::Normal, "...", &ok3).toInt(&ok3);
	if(!ok1 || !ok2 || !ok3) imageMode = false;
}

void Canvas::slot_add_text()
{
	bool ok;
	if(textMode == true) return;
	textMode = true;	
	text = QInputDialog::getText(this, tr("Text"), tr("text:"), QLineEdit::Normal, "...", &ok);
	if(!ok) textMode = false;
}

void Canvas::mousePressEvent(QMouseEvent* event)
{
	if(event->button() == Qt::LeftButton) {
		if(imageMode) {
			invoker->execute(client->getImageCommand(this, width, height, event, name));
		} else if(textMode) {
			invoker->execute(client->getTextCommand(this, event, text));
		} else {
			invoker->execute(client->getBrushCommand(CommandType::STARTDRAW, this, event));
		}
	}
	else if(event->button() == Qt::RightButton)
		invoker->undo();
	else if(event->button() == Qt::MiddleButton)
		invoker->redo();
}

void Canvas::mouseMoveEvent(QMouseEvent* event)
{
	if(event->buttons() & Qt::LeftButton)
		invoker->execute(client->getBrushCommand(CommandType::DRAW, this, event));
}

void Canvas::mouseReleaseEvent(QMouseEvent* event)
{
	if(event->button() == Qt::LeftButton) {
		if(imageMode) {
			imageMode = false;
			return;		
		} else if(textMode) {
			textMode = false;
			return;		
		} else if(textMode) {
		} else {
			invoker->execute(client->getBrushCommand(CommandType::ENDDRAW, this, event));
		}
	}
}

void Canvas::paintEvent(QPaintEvent* event)
{
	Q_UNUSED(event);
	invoker->execute(client->getBrushCommand(CommandType::UPDATE, this, penColor, penSize));
}

Canvas::~Canvas()
{ }
