#include "Screen.h"
#include "ofEasyCam.h"

Screen::Screen() : key(0), mouseX(0), mouseY(0)
{
	ofBackground(ofColor::red);
	ofSetColor(ofColor::yellow);
	headerFont.load("header.ttf", 200);
	header = headerFont.getStringMesh("", ofGetWidth() / 2 - 100, ofGetHeight() / 2 - 100);
	bodyFont.load("body.ttf", 50);
}

Screen::Screen(string h) : key(0), mouseX(0), mouseY(0)
{
	ofBackground(ofColor::red);
	ofSetColor(ofColor::yellow);
	headerFont.load("header.ttf", 50);
	header = headerFont.getStringMesh(h, 100, 100);
	bodyFont.load("body.ttf", 50);
}

int Screen::getKey() const
{
	return key;
}
void Screen::setKey(int k)
{
	key = k;
}
int Screen::getMouseX() const
{
	return mouseX;
}
void Screen::setMouseX(int mouseX)
{
	this->mouseX = mouseX;
}
int Screen::getMouseY() const
{
	return mouseY;
}
void Screen::setMouseY(int mouseY)
{
	this->mouseY = mouseY;
}

int Screen::display()
{
	headerFont.getFontTexture().bind();
	header.draw();
	headerFont.getFontTexture().unbind();
	return getClick();
}

ofRectangle Screen::getButton(int x, int y)
{
	ofNoFill();
	ofSetLineWidth(6);
	ofRectangle r = ofRectangle(x, y, 400, 300);
	return r;
}