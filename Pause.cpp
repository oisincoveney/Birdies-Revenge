#include "Pause.h"
#include "of3dGraphics.h"
#include "ofCamera.h"

Pause::Pause() : Screen{ "" }
{
	pause.load("header.ttf", 300);
	help_text.load("body.ttf", 50);
}
int Pause::display()
{
	ofSetColor(ofColor::yellow);
	pause.drawString("PAUSE", ofGetWidth() / 2 - 500, ofGetHeight() / 2 - 250);
	help_text.drawString("Press space or click anywhere to return to the game.", 300, ofGetHeight() - 150);
	return Screen::display();
}
int Pause::getClick()
{
	int x = 2;
	if (mouseX > 0 || key == ' ') //game
	{
		x = 1;
	}
	key = 0;
	mouseX = 0;
	mouseY = 0;
	return x;
}