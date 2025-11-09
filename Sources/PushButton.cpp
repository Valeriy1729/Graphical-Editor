#include "PushButton.h"

PushButton::PushButton(QWidget* parent, QColor _color, const char _text[]) : QPushButton(parent), color{_color}
{
	QPalette pal {this->palette()};
	pal.setColor(QPalette::Button, _color);
	this->setPalette(pal);
	this->setText(_text);
}
QColor PushButton::penColor {Qt::black};

QColor PushButton::getPenColor()
{
	return penColor;	
}

void PushButton::slot_set_penColor()
{
	penColor = color;	
	emit signal_set_penColor();
}

PushButton::~PushButton()
{ }
