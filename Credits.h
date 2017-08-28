#pragma once
#include "Screen.h"

class Credits : public Screen
{
private:
	ofTrueTypeFont creditsFont, label;
	ofVboMesh credits;
	ofRectangle button;
	string tag;
public:
	Credits();
	int display() override;
	int getClick() override;
};