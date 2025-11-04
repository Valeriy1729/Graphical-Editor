#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGridLayout>
#include <QLabel>
#include "ButtonPanel.h"
#include "Canvas.h"


class MainWindow : public QWidget {
	Q_OBJECT

	QGridLayout* g_layout {nullptr};
	ButtonPanel* buttonPanel {nullptr};
	QLabel* title {nullptr};

	Canvas* canvas;

public:
	MainWindow(QWidget* parent=nullptr);	
	~MainWindow();
};


#endif
