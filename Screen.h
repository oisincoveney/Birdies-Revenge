#pragma once
#include "ofVboMesh.h"
#include "ofTrueTypeFont.h"

class Screen
{
protected:
	int key, mouseX, mouseY;
	ofVboMesh header;
	ofTrueTypeFont headerFont;
	ofTrueTypeFont bodyFont;

public:
	Screen();
	Screen(string h);
	virtual int display();
	virtual int getClick() = 0;

	int getKey() const;
	void setKey(int k);
	int getMouseX() const;
	void setMouseX(int mouseX);
	int getMouseY() const;
	void setMouseY(int mouseY);

	static ofRectangle getButton(int x, int y);
};
