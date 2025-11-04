#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <QPushButton>
#include <QPalette>


class PushButton : public QPushButton {
	Q_OBJECT
	QColor color {};
public:
	PushButton(QWidget* parent=nullptr, QColor _color=Qt::white, const char text[]="");
	~PushButton();
};


#endif
