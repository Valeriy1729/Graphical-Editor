#include "Connector.h"

Connector::Connector(MainWindow* _mainWindow)
{
	mainWindow = const_cast<const MainWindow*>(_mainWindow);
	buttonPanel = _mainWindow->getButtonPanel();
	canvas = _mainWindow->getCanvas();
}

void Connector::Signals_Slots_Connect()
{
	const vector<PushButton*> ColButtons {buttonPanel->getColButtons()};
	for(PushButton* pButton : ColButtons) {
		connect(pButton, SIGNAL(clicked()), pButton, SLOT(slot_set_penColor()));
		connect(pButton, SIGNAL(signal_set_penColor()), this, SLOT(slot_set_penColor()));
	}
	
}

void Connector::slot_set_penColor()
{
	Canvas* _canvas = const_cast<Canvas*>(canvas);
	_canvas->setPenColor(buttonPanel->getPenColor());
}

void Connector::Shortcuts_Connect()
{
	new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), const_cast<MainWindow*>(mainWindow), SLOT(undo()));
	new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y), const_cast<MainWindow*>(mainWindow), SLOT(redo()));
}

