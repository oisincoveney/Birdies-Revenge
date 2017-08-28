#pragma once
#include "ofImage.h"
#include "ofSoundPlayer.h"
#include "Bullet.h"

#define BEAR "Bear.png"
#define EAGLE "Eagle.png"

class Character
{
protected:
	ofImage sprite;
	mutable ofSoundPlayer sound;
	mutable float x, y, angle, xSpeed, ySpeed;
public:

	//constructors
	Character();
	Character(float angle, float speed, string filename);
	Character(float x, float y, float angle, float speed, string filename);

	//displays image and updates coordinates
	void displayImage() const;
	virtual void update() const;
	void display() const;

	//shooting mechanism
	virtual Bullet shoot() const;
	Bullet shoot(float speed) const;
	void shoot_sound() const;

	//getters and setters
	ofImage getSprite() const;
	void setSprite(ofImage image);
	float getAngle() const;
	void setAngle(float angle) const;
	float getX() const;
	void setX(float x) const;
	float getY() const;
	void setY(float y) const;
	float getXSpeed() const;
	void setXSpeed(float xSpeed) const;
	float getYSpeed() const;
	void setYSpeed(float ySpeed) const;

	//operator< overload
	virtual bool operator<(const Character& other) const;
	bool checkIfHit(int x, int y) const;
};
