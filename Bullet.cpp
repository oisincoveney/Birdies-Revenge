#include "Bullet.h"
#include "ofConstants.h"
#include "ofEasyCam.h"

Bullet::Bullet() :
	x{ 0 },
	y{ 0 },
	angle{ 90 },
	xSpeed{ static_cast<float>(10 * sin(angle * 0.0174533) * PI / 18) },
	ySpeed{ static_cast<float>(-10 * cos(angle * 0.0174533) * PI / 18) }
{}

Bullet::Bullet(float x, float y, float angle, float speed) :
	x{ x },
	y{ y },
	angle{ angle },
	xSpeed{ static_cast<float>(speed * sin(angle * 0.0174533) * PI / 18) },
	ySpeed{ static_cast<float>(-speed * cos(angle * 0.0174533) * PI / 18) }
{}

void Bullet::display() const
{
	ofSetColor(0, 0, 0);
	ofDrawCircle(x, y, 5);
	x += xSpeed;
	y += ySpeed;
}

float Bullet::getX() const { return x; }
float Bullet::getY() const { return y; }
void Bullet::setX(float x) const { this->x = x; }
void Bullet::setY(float y) const { this->y = y; }

bool Bullet::operator<(const Bullet& other) const
{
	return x < other.getX();
}