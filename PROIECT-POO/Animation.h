#pragma once

#include "TextureManager.h"


class Animation {
private:
	string id;
	int spriteRow, spriteFrame;
	int animationSpeed, nrFrames;

public:
	Animation(int a);
	void Init(string i, int row, int frameCount);
	void Update();
	void Render(Position* pos, bool isPlayer);

};