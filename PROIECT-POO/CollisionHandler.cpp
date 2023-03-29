#include "CollisionHandler.h"
#include "TextureManager.h"
#include <string>

CollisionHandler::CollisionHandler() {
	tileMap = Game::game.getMap();
}
bool CollisionHandler::checkCollision(SDL_Rect a, SDL_Rect b) {
	bool X = (a.x < b.x + b.w) && (a.x + a.w > b.x);
	bool Y = (a.y < b.y + b.h) && (a.y + a.h > b.y);
	return (X && Y);
}
bool CollisionHandler::mapCollision(SDL_Rect a, int dir) {
	int left_tile = a.x / tileSize;
	int right_tile = (a.x + a.w) / tileSize;
	int top_tile = a.y / tileSize;
	int bottom_tile = (a.y + a.h) / tileSize;
	if (left_tile < 0) left_tile = 0;
	if (top_tile < 0) top_tile = 0;
	if (right_tile > colCountLevel1) right_tile = colCountLevel1;
	if (bottom_tile > rowCount) bottom_tile = rowCount;

	string c, b;
	int stg, dr;
	switch (dir) {
	case 1:
		//sus
		stg = tileMap->map[top_tile][left_tile];
		dr = tileMap->map[top_tile][right_tile];
		c = to_string(stg);
		b = to_string(dr);
		if (TextureManager::tex.returnColision(c) || TextureManager::tex.returnColision(b) || stg == 98 || dr == 98)
			return true;
		return 0;
		break;
	case 2:
		//jos
		stg = tileMap->map[bottom_tile][left_tile];
		dr = tileMap->map[bottom_tile][right_tile];
		c = to_string(stg);
		b = to_string(dr);
		if (TextureManager::tex.returnColision(c) || TextureManager::tex.returnColision(b) || stg == 98 || dr == 98)
			return true;
		return 0;
		break;
	case 3:
		//stanga
		stg = tileMap->map[top_tile][left_tile];
		dr = tileMap->map[bottom_tile][left_tile];
		c = to_string(stg);
		b = to_string(dr);
		if (TextureManager::tex.returnColision(c) == 1 || TextureManager::tex.returnColision(b) == 1 || stg == 98 || dr == 98)
			return true;
		return 0;
		break;
	case 4:
		//dreapta
		stg = tileMap->map[top_tile][right_tile];
		dr = tileMap->map[bottom_tile][right_tile];
		c = to_string(stg);
		b = to_string(dr);
		if (TextureManager::tex.returnColision(c) || TextureManager::tex.returnColision(b) || stg == 98 || dr == 98)
			return true;
		return 0;
		break;
	}

}