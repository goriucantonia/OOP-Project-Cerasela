#include "Animation.h"

Animation::Animation(int a) {
	
	spriteRow = 0;
	spriteFrame = 0;
	nrFrames = 0;
	animationSpeed = a;
}

void Animation::Init(string i, int row, int frameCount) {
	id = i;
	spriteRow = row;
	nrFrames = frameCount;
}
void Animation::Update() {
	spriteFrame = (SDL_GetTicks() / animationSpeed) % nrFrames; //va avea rezultatele 0,1,...nr-1 in aceasta ordine
}
void Animation::Render(Position* pos, bool isPlayer) {

		TextureManager::tex.DrawFrame(id, pos, tileSize, spriteFrame, spriteRow, isPlayer);
}