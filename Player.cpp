#include "Player.h"
#include "of3dGraphics.h"

Player::Player() : Character(ofGetWidth() / 4, ofGetHeight() / 2, 90, 0, EAGLE), key{}, mouseX{ 0 }, mouseY{ 0 } {}

void Player::setKey(int key) { this->key = key; }
void Player::setMouseX(int mouseX) { this->mouseX = mouseX; }
void Player::setMouseY(int mouseY) { this->mouseY = mouseY; }
void Player::setAngle() const
{
	int dx = abs(x) - abs(mouseX);
	int dy = abs(y) - abs(mouseY);

	int angle = atan2(dy, dx) * 180 / PI;

	x >= getX() ? Character::setAngle(angle - 90) : Character::setAngle(270 + angle);
}

void Player::update() const
{
	switch (key)
	{
	case 'w':
		ySpeed = -5;
		break;
	case 'a':
		xSpeed = -5;
		break;
	case 's':
		ySpeed = 5;
		break;
	case 'd':
		xSpeed = 5;
		break;
	default: break;
	}

	if (getX() <= 15)
	{
		xSpeed = abs(xSpeed);
	}
	if (getX() >= ofGetWidth() - 15)
	{
		xSpeed = -abs(xSpeed);
	}

	Character::update();
}

Bullet Player::shoot() const
{
	//shoot_sound();
	return Character::shoot(500);
}

void Player::reset()
{
	x = ofGetWidth() / 4;
	y = ofGetHeight() / 2;
	angle = 90;
	xSpeed = 0;
	ySpeed = 0;
	key = 0;
	mouseX = 0;
	mouseY = 0;
}