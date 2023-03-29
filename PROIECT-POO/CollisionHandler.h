#pragma once
#include "Game.h"
#include "Map.h"

class CollisionHandler {
private:
	SDL_Rect collider;
	GameMap* tileMap;
	CollisionHandler();
public:

	static CollisionHandler colHandler;
	bool checkCollision(SDL_Rect a, SDL_Rect b);
	bool mapCollision(SDL_Rect a, int dir);
};