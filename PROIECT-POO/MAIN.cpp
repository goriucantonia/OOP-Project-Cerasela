#include "Game.h"
#include "Map.h"
#include <iostream>

using namespace std;


/// <summary>
/// Phoenix MapleStory
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>


int main(int argc, char* argv[]) {
	const float FPS = 60.0f;
	const float DELAY = 1000.0f / FPS;

	Uint32 frameStart;
	int frameTime;

	Game::game.init("titlu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWid, screenHei);
	while (Game::game.running()) {
		frameStart = SDL_GetTicks(); //milisecunde
		Game::game.events();
		Game::game.update();
		Game::game.render();
		frameTime = SDL_GetTicks() - frameStart;

		if (DELAY > frameTime) {
			SDL_Delay(DELAY - frameTime);
		}
	}
	Game::game.clean();
	

	return 0;
}