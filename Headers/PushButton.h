#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <QPushButton>
#include <QPalette>


class PushButton : public QPushButton {
	Q_OBJECT
	QColor color {};
	static QColor penColor;
public:
	PushButton(QWidget* parent=nullptr, QColor _color=Qt::white, const char text[]="");
	QColor getPenColor();
	~PushButton();
public slots:
	void slot_set_penColor();
signals:
	void signal_set_penColor();
};


#endif
