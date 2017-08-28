#include "Tutorial.h"
#include "of3dGraphics.h"
#include "ofCamera.h"

Tutorial::Tutorial() : Screen{ "Tutorial" }
{
	for (int i{}; i < 3; i++) labels[i].load("header.ttf", 35);
	button = getButton(100, ofGetHeight() - 400);

	tags[0] =
		"                      CONTROLS\n"
		"\n"
		"Birdie is controlled with both the\n"
		"mouse and the keyboard. Move Birdie\n"
		"in different directions using the \n"
		"WASD scheme, and direct Birdie's shots\n"
		"with the direction of your mouse.\n"
		"\n"
		"\n"
		"W: up\n"
		"A: left\n"
		"S: down\n"
		"D: right\n"
		"\n"
		"Mouse: rotation"
		;
	tags[1] =
		"                      SCORING\n"
		"\n"
		"Scoring in this game is a little\n"
		"funky. You start off with 10 points\n"
		"that serve as a buffer between you\n"
		"and 0 points, at which your game\n"
		"is over.\n"
		"\n"
		"How does this happen?\n"
		"If an enemy goes past you, \n"
		"   you lose 5 points.\n"
		"If an enemy hits you,\n"
		"   you lose 1 point. \n"
		"If you hit an enemy, \n"
		"   you get 1 point.  \n";
	tags[2] = "RETURN";
}
int Tutorial::display()
{
	ofSetColor(ofColor::red);
	ofDrawRectangle(button);
	ofSetColor(ofColor::yellow);
	labels[0].drawString(tags[0], 250, ofGetHeight() / 8);
	labels[1].drawString(tags[1], 3 * ofGetWidth() / 5, ofGetHeight() / 8);
	labels[2].drawString(tags[2], button.getMinX() + 35, button.getMinY() + button.getWidth() / 2);
	return Screen::display();
}
int Tutorial::getClick()
{
	int x = 5;
	if (button.inside(mouseX, mouseY)) //tutorial
	{
		x = 0;
	}
	key = 0;
	mouseX = 0;
	mouseY = 0;
	return x;
}