#include "Enemy.h"
#include "ofAppNoWindow.h"

Enemy::Enemy() :
	Character(270, rand() % 20 + 20, BEAR),
	frameCreated{ static_cast<int>(ofGetFrameNum()) },
	delay{ calculateDelay(getRandomDelay()) }
{
	x += delay;
}

Enemy::Enemy(float delay, float speed, float angle) :
	Character{
	ofGetWidth() - 10 + calculateDelay(delay),
	100 + rand() % (ofGetHeight() - 200),
	speed,
	angle,
	BEAR },
	frameCreated{ static_cast<int> (ofGetFrameNum()) },
	delay{ calculateDelay(delay) }
{}

Enemy::Enemy(float x, float y, float angle, float speed, string filename) :
	Character{ x,y,angle,speed,filename },
	frameCreated{ static_cast<int>(ofGetFrameNum()) },
	delay{ calculateDelay(getRandomDelay()) }
{
	this->x += delay;
}

float Enemy::getRandomDelay()
{
	return ofRandom(0, 10);
}

int Enemy::calculateDelay(float d)
{
	return static_cast<int>(d * FPS);
}

float Enemy::getDelay() const
{
	return delay / FPS;
}
Bullet Enemy::shoot() const
{
	if (!((ofGetFrameNum() - frameCreated + delay) % 120))
	{
		return Character::shoot(-xSpeed * 30);
	}
	return Bullet(-1, -1, 0, 0);
}

bool Enemy::operator<(const Character& other) const
{
	return y < other.getY();
}

string Enemy::getType() const
{
	return "Simple Enemy";
}

ostream& operator<<(ostream& output, const Enemy& enemy) {
	output << "Type: " << enemy.getType() << "\t(" << enemy.x << ", " << enemy.y << ") \tdelay: " << enemy.delay << " \t xSpeed: " << enemy.xSpeed << "\t ySpeed: " << enemy.ySpeed << endl;
	return output;
}