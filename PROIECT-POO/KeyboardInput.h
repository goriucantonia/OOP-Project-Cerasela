#pragma once

#include "Game.h"



class KeyboardInput {
private:
	KeyboardInput() {};

public:
	
	static KeyboardInput key;
	bool up, left, right, xkey, down;
	void updatePressed();
	void updateReleased();
};