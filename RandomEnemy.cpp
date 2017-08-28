#include "RandomEnemy.h"
#include "ofAppNoWindow.h"

RandomEnemy::RandomEnemy() :
	Enemy(getRandomDelay(), 270, randomSpeed()) {}

RandomEnemy::RandomEnemy(float delay) :
	Enemy(delay, 270, randomSpeed()) {}

void RandomEnemy::setAngle() const
{
	xSpeed = -10;
	ySpeed = randomSpeed();
	angle = findAngle(-10, ySpeed);
}

float RandomEnemy::findAngle(float x, float y) const
{
	float a = atan2(abs(y), abs(x)) * 180 / PI;
	return y < 0 ? 270 + a : 270 - a;
}

float RandomEnemy::randomSpeed()
{
	float x = (rand() % 600 + 100) / 100;
	return rand() % 2 ? x : -x;
}

Bullet RandomEnemy::shoot() const
{
	if (!((ofGetFrameNum() - frameCreated + delay) % (rand() % 200 + 1)))
	{
		setAngle();
		return Character::shoot(-xSpeed * 30);
	}
	return Bullet(-1, -1, 0, 0);
}

string RandomEnemy::getType() const
{
	return "Random Enemy";
}