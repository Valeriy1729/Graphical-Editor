#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) : QWidget(parent)
{
	g_layout = new QGridLayout(this);
	title = new QLabel("", this);
	buttonPanel = new ButtonPanel(this);
	canvas = new Canvas(this);

	g_layout->addWidget(title, 0, 0, 1, 10);
	g_layout->addWidget(canvas, 1, 0, 9, 9);
	g_layout->addWidget(buttonPanel, 1, 9, 1, 1);
	
	this->setFixedWidth(1024);
	this->setFixedHeight(768);
	title->setFixedHeight(20);
}

MainWindow::~MainWindow()
{ }
