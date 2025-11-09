#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) : QWidget(parent)
{
	client = new Client;
	invoker = new Invoker;

	g_layout = new QGridLayout(this);
	title = new QLabel("", this);
	buttonPanel = new ButtonPanel(this);
	canvas = new Canvas(this);

	canvas->setInvoker(invoker);
	canvas->setClient(client);

	g_layout->addWidget(title, 0, 0, 1, 10);
	g_layout->addWidget(canvas, 1, 0, 9, 9);
	g_layout->addWidget(buttonPanel, 1, 9, 1, 1);
	
	this->setFixedWidth(1024);
	this->setFixedHeight(768);
	title->setFixedHeight(20);
}

void MainWindow::undo()
{
	invoker->undo();	
}

void MainWindow::redo()
{
	invoker->redo();	
}

const ButtonPanel* MainWindow::getButtonPanel()
{
	return const_cast<const ButtonPanel*>(buttonPanel);
}

const Canvas* MainWindow::getCanvas()
{
	return const_cast<const Canvas*>(canvas);
}

MainWindow::~MainWindow()
{
	delete client;
	delete invoker;
}
