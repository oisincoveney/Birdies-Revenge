#include "Menu.h"
#include "ofAppNoWindow.h"
#include "ofEasyCam.h"

Menu::Menu() : Screen{ "Main Menu" }
{
	titleFont.load("header.ttf", 250);
	for (int i{}; i < 3; i++)
	{
		labels[i].load("header.ttf", 50);
	}
	help = headerFont.getStringMesh("Click one of the options\n  or press space to play", ofGetWidth() / 2 - 400, ofGetHeight() - 150);
	buttons[0] = getButton(ofGetWidth() / 2 - 200, ofGetHeight() - 800);
	buttons[1] = getButton(ofGetWidth() / 2 + 400, ofGetHeight() - 800);
	buttons[2] = getButton(ofGetWidth() / 2 - 800, ofGetHeight() - 800);
	tags[0] = "PLAY";
	tags[1] = "TUTORIAL";
	tags[2] = "CREDITS";
	title = titleFont.getStringMesh(" Birdie's\nRevenge", ofGetWidth() / 2 - 800, ofGetHeight() / 2 - 500);
}

int Menu::display()
{
	ofSetColor(ofColor::red);
	ofDrawRectangle(buttons[0]);
	ofDrawRectangle(buttons[1]);
	ofDrawRectangle(buttons[2]);

	ofSetColor(ofColor::yellow);
	titleFont.getFontTexture().bind();
	title.draw();
	titleFont.getFontTexture().unbind();

	headerFont.getFontTexture().bind();
	help.draw();
	headerFont.getFontTexture().unbind();

	labels[0].drawString(tags[0], buttons[0].getMinX() + 75, buttons[0].getMinY() + buttons[0].getWidth() / 2);
	labels[1].drawString(tags[1], buttons[1].getMinX() + 5, buttons[1].getMinY() + buttons[1].getWidth() / 2);
	labels[2].drawString(tags[2], buttons[2].getMinX() + 30, buttons[2].getMinY() + buttons[2].getWidth() / 2);

	return Screen::display();
}

int Menu::getClick()
{
	int x = 0;
	if (key == ' ' || buttons[0].inside(mouseX, mouseY)) //game
	{
		x = 1;
	}

	else if (buttons[1].inside(mouseX, mouseY))	//tutorial
	{
		x = 5;
	}

	else if (buttons[2].inside(mouseX, mouseY)) //credits
	{
		x = 4;
	}
	key = 0;
	mouseX = 0;
	mouseY = 0;
	return x;
}