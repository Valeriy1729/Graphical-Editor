#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QShortcut>
#include <QKeySequence>
#include <vector>
#include "MainWindow.h"
#include "ButtonPanel.h"
#include "Canvas.h"

using std::vector;


class Connector : public QWidget {
	Q_OBJECT

	const MainWindow* mainWindow;
	const ButtonPanel* buttonPanel;
	const Canvas* canvas;

public:
	Connector(MainWindow* _mainWindow);
	void Signals_Slots_Connect();		
	void Shortcuts_Connect();		

public slots:
	void slot_set_penColor();
	void slot_set_penSize();
	void slot_add_image();
	void slot_add_text();
};


#endif
