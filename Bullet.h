#pragma once

class Bullet
{
private:
	mutable float x, y, angle, xSpeed, ySpeed;
public:
	//constructor
	Bullet();
	Bullet(float x, float y, float angle, float speed);

	//display
	void display() const;

	//getters & setters
	float getX() const;
	float getY() const;
	void setX(float x) const;
	void setY(float y) const;
	//operator< overload
	bool operator<(const Bullet& other) const;
};