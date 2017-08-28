#pragma once
#include "Character.h"
#include "Enemy.h"

class RandomEnemy : public Enemy
{
public:
	RandomEnemy();
	RandomEnemy(float delay);
	void setAngle() const;
	float findAngle(float x, float y) const;
	static float randomSpeed();
	Bullet shoot() const override;
	string getType() const override;
};