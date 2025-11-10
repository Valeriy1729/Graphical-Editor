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
	const PushButton* eraseBtn {buttonPanel->getEraseButton()};
	const Slider* sizeSlider {buttonPanel->getSizeSlider()};

	for(PushButton* pButton : ColButtons) {
		connect(pButton, SIGNAL(clicked()), pButton, SLOT(slot_set_penColor()));
		connect(pButton, SIGNAL(signal_set_penColor()), this, SLOT(slot_set_penColor()));
	}

	connect(eraseBtn, SIGNAL(clicked()), eraseBtn, SLOT(slot_set_penColor()));
	connect(eraseBtn, SIGNAL(signal_set_penColor()), this, SLOT(slot_set_penColor()));
	connect(sizeSlider, SIGNAL(sliderReleased()), this, SLOT(slot_set_penSize()));
}

void Connector::slot_set_penColor()
{
	Canvas* _canvas = const_cast<Canvas*>(canvas);
	_canvas->setPenColor(buttonPanel->getPenColor());
}

void Connector::slot_set_penSize()
{
	Canvas* _canvas = const_cast<Canvas*>(canvas);
	_canvas->setPenSize(buttonPanel->getPenSize());
}

void Connector::Shortcuts_Connect()
{
	new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), const_cast<MainWindow*>(mainWindow), SLOT(undo()));
	new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y), const_cast<MainWindow*>(mainWindow), SLOT(redo()));
}

