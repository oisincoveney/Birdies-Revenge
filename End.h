#pragma once
#include "Screen.h"

class End : public Screen
{
private:
	ofTrueTypeFont the_end, help_text;
public:
	End();
	int display() override;
	int getClick() override;
};