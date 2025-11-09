#include <iostream>
#include <QApplication>
#include "MainWindow.h"
#include "Connector.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	MainWindow mainWindow;
	Connector connector(&mainWindow);

	mainWindow.setStyleSheet("QLabel { background-color: #dddddd; }");

	connector.Signals_Slots_Connect();
	connector.Shortcuts_Connect();
	
	mainWindow.show();

	app.exec();
	return 0;	
}
