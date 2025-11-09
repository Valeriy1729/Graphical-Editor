#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGridLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QShortcut>
#include <QKeySequence>
#include <iostream>
#include "ButtonPanel.h"
#include "Canvas.h"
#include "Command/Invoker.h"
#include "Command/Client.h"


class MainWindow : public QWidget {
	Q_OBJECT

	QGridLayout* g_layout;
	ButtonPanel* buttonPanel;
	QLabel* title; 
	Canvas* canvas;
	Invoker* invoker;
	Client* client;

public:
	MainWindow(QWidget* parent=nullptr);	
	const ButtonPanel* getButtonPanel();
	const Canvas* getCanvas();
	~MainWindow();

public slots:
	void undo();
	void redo();
};


#endif
