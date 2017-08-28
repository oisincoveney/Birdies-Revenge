#include "Character.h"
#include "ofMatrixStack.h"
#include "ofAppNoWindow.h"

Character::Character() :
	x{ static_cast<float>(ofGetWidth() + 10) },
	y{ static_cast<float>(100 + rand() % (ofGetHeight() - 200)) },
	angle{ 270 },
	xSpeed{ static_cast<float>(sin(angle * 0.0174533) * PI / 18) },
	ySpeed{ static_cast<float>(cos(angle * 0.0174533) * PI / 18) }
{
	sprite.load(BEAR);
	sprite.setAnchorPercent(0.5, 0.5);
	sound.load("laser.mp3");
}

Character::Character(float angle, float speed, string filename) :
	x{ static_cast<float>(ofGetWidth() + 10) },
	y{ static_cast<float>(100 + rand() % (ofGetHeight() - 200)) },
	angle{ angle },
	xSpeed{ speed * static_cast<float>(sin(angle * 0.0174533) * PI / 18) },
	ySpeed{ speed * static_cast<float>(cos(angle * 0.0174533) * PI / 18) }
{
	sprite.load(filename);
	sprite.setAnchorPercent(0.5, 0.5);
	sound.load("laser.mp3");
}
Character::Character(float x, float y, float angle, float speed, string filename) :
	x{ x },
	y{ y },
	angle{ angle },
	xSpeed{ static_cast<float>(speed * sin(angle * 0.0174533) * PI / 180) },
	ySpeed{ static_cast<float>(speed * cos(angle *0.0174533) * PI / 180) }
{
	sprite.load(filename);
	sprite.setAnchorPercent(0.5, 0.5);
	sound.load("laser.mp3");
}

void Character::displayImage() const
{
	if (x < ofGetWidth() - 5)
	{
		ofPushMatrix();
		ofTranslate(x, y);
		ofRotateZ(angle);
		ofSetColor(255);
		sprite.draw(0, 0);
		ofPopMatrix();
	}
}
void Character::update() const
{
	if (getY() <= 0 | getY() >= ofGetHeight())
	{
		ySpeed = -ySpeed;
	}
	x += xSpeed;
	y += ySpeed;
}
void Character::display() const
{
	displayImage();
	update();
}

Bullet Character::shoot() const { return Bullet(x, y, angle, 50); }
Bullet Character::shoot(float speed) const { return Bullet(x, y, angle, speed); }
void Character::shoot_sound() const { sound.play(); }

ofImage Character::getSprite() const { return sprite; }
void Character::setSprite(ofImage image) { sprite = image; }

float Character::getAngle() const { return angle; }
void Character::setAngle(float angle) const { this->angle = angle; }

float Character::getX() const { return x; }
void Character::setX(float x) const { this->x = x; }

float Character::getY() const { return y; }
void Character::setY(float y) const { this->y = y; }

float Character::getXSpeed() const { return xSpeed; }
void Character::setXSpeed(float xSpeed) const { this->xSpeed = xSpeed; }

float Character::getYSpeed() const { return ySpeed; }
void Character::setYSpeed(float ySpeed) const { this->ySpeed = ySpeed; }

bool Character::operator<(const Character& other) const
{
	return x < other.getX() && y < other.getY();
}

bool Character::checkIfHit(int x, int y) const
{
	int minX = this->x - sprite.getWidth() / 2;

	if (minX < ofGetWidth() - 5)
	{
		int maxX = minX + sprite.getWidth();
		int minY = this->y - sprite.getHeight() / 2;
		int maxY = minY + sprite.getHeight();
		return (x - minX > 0 && maxX - x > 0) && (y - minY > 0 && maxY - y > 0);
	}
	return false;
}