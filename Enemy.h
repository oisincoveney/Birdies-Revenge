#pragma once
#include "Character.h"

#define FPS 30.0f

class Enemy : public Character
{
protected:
	mutable int frameCreated, delay;  //delay: the number of seconds, converted into number of frames (delay * FPS)
public:
	Enemy();
	Enemy(float delay, float speed, float angle);
	Enemy(float x, float y, float angle, float speed, string filename);
	float getRandomDelay();
	static int calculateDelay(float d);
	float getDelay() const;
	Bullet shoot() const override;
	bool operator<(const Character& other) const override;
	friend ostream& operator<<(ostream& output, const Enemy& enemy);
	virtual string getType() const;
};