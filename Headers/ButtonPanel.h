#ifndef BUTTONPANEL_H
#define BUTTONPANEL_H

#include <iostream>
#include <QGridLayout>
#include <vector>
#include "PushButton.h"

using std::vector;


class ButtonPanel : public QWidget {
	Q_OBJECT

	enum { BUTTON_COUNT = 8, COLUMN_COUNT = 2, COLORS_COUNT = 8 };

	QGridLayout* g_layout {nullptr};
	vector<PushButton*> ColButtons {};
	PushButton* eraseBtn;
	int penSize;
	
	const QColor Colors[COLORS_COUNT] {
		Qt::red, QColor(0xff7700), Qt::yellow, Qt::green,
		Qt::cyan, Qt::blue, Qt::darkMagenta, QColor(0x222222)
	};
	
public:
	ButtonPanel(QWidget* parent=nullptr);	
	const vector<PushButton*>& getColButtons() const;
	QColor getPenColor() const;
	~ButtonPanel();
};


#endif
