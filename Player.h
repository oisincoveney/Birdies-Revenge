#pragma once
#include "Character.h"

class Player : public Character
{
private:
	int key, mouseX, mouseY;
public:
	Player();
	void setKey(int key);
	void setMouseX(int mouseX);
	void setMouseY(int mouseY);
	void setAngle() const;
	void update() const override;
	Bullet shoot() const override;
	void reset();
};
