#pragma once
#include "Screen.h"

class Pause : public Screen
{
private:
	ofTrueTypeFont pause, help_text;
public:
	Pause();
	int display() override;
	int getClick() override;
};