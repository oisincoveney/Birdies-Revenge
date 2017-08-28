#pragma once
#include "Screen.h"

class Tutorial : public Screen
{
private:
	ofTrueTypeFont labels[3];
	ofRectangle button;
	string tags[3];
public:
	Tutorial();
	int display() override;
	int getClick() override;
};