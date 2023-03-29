#pragma once

#include "GameObject.h"

class Coin :public GameObject {
private:
public:
	Coin(string i, int x, int y, int a);
	void Update();
	void Render();
	void Clean();
	~Coin();
};