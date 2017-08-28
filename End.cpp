#include "End.h"
#include "of3dGraphics.h"
#include "ofCamera.h"

End::End() : Screen{ "" }
{
	the_end.load("header.ttf", 300);
	help_text.load("body.ttf", 50);
}
int End::display()
{
	ofSetColor(ofColor::yellow);
	the_end.drawString("END", ofGetWidth() / 2 - 150, ofGetHeight() / 2 - 150);
	help_text.drawString("Press space or click anywhere to return to the main menu.", 300, ofGetHeight() - 150);
	return Screen::display();
}
int End::getClick()
{
	int x = 3;
	if (mouseX > 0 || key == ' ') //main menu
	{
		x = 0;
	}
	key = 0;
	mouseX = 0;
	mouseY = 0;
	return x;
}