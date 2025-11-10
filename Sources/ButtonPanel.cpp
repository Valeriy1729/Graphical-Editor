#include "ButtonPanel.h"

ButtonPanel::ButtonPanel(QWidget* parent) : QWidget(parent)
{
	g_layout = new QGridLayout(this);
	eraseBtn = new PushButton(this, 0xeeeeee, "Eraser");
	sizeSlider = new Slider(1, 25, 50, 5, this);

	for(int i {0}; i < BUTTON_COUNT; ++i) {
		PushButton* btn {new PushButton(this, Colors[i])};
		g_layout->addWidget(btn, i / COLUMN_COUNT, i % COLUMN_COUNT, 1, 1);
		ColButtons.push_back(btn);
	}

	g_layout->addWidget(eraseBtn, BUTTON_COUNT / COLUMN_COUNT, 0, 1, 2);
	g_layout->addWidget(sizeSlider, BUTTON_COUNT / COLUMN_COUNT + 1, 0, 1, 2);
}

const vector<PushButton*>& ButtonPanel::getColButtons() const
{
	return const_cast<const vector<PushButton*>&>(ColButtons);
}

const PushButton* ButtonPanel::getEraseButton() const
{
	return const_cast<const PushButton*>(eraseBtn);
}

const Slider* ButtonPanel::getSizeSlider() const
{
	return const_cast<const Slider*>(sizeSlider);
}

int ButtonPanel::getPenSize() const
{
	return sizeSlider->value();	
}

QColor ButtonPanel::getPenColor() const
{
	return ColButtons[0]->getPenColor();	
}

ButtonPanel::~ButtonPanel()
{ }
