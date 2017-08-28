#include "Credits.h"
#include "of3dGraphics.h"
#include "ofCamera.h"

Credits::Credits() : Screen{ "Credits" }
{
	creditsFont.load("header.ttf", 100);
	label.load("header.ttf", 50);
	button = getButton(100, ofGetHeight() - 400);
	tag = "RETURN";
	credits = creditsFont.getStringMesh("                    Birdie's Revenge:\n       A game made by Oisin Coveney\n    as a final project for CSE 1342", 150, ofGetHeight() / 2 - 300);
}
int Credits::display()
{
	ofSetColor(ofColor::red);
	ofDrawRectangle(button);
	ofSetColor(ofColor::yellow);
	creditsFont.getFontTexture().bind();
	credits.draw();
	creditsFont.getFontTexture().unbind();
	label.drawString(tag, button.getMinX() + 35, button.getMinY() + button.getWidth() / 2);
	return Screen::display();
}
int Credits::getClick()
{
	int x = 4;
	if (button.inside(mouseX, mouseY)) //credits
	{
		x = 0;
	}
	key = 0;
	mouseX = 0;
	mouseY = 0;
	return x;
}