#pragma once
#include "Screen.h"

class Menu : public Screen
{
private:
	ofTrueTypeFont titleFont, labels[3];
	ofVboMesh title, help;
	ofRectangle buttons[3];
	string tags[3];
public:
	Menu();
	int display() override;
	int getClick() override;
};