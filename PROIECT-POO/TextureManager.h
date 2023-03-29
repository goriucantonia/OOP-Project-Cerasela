#pragma once

#include "Position.h"
#include "SDL_image.h"
#include <map>

class TextureManager {
private:
	 TextureManager() {};
	 map<string, SDL_Texture*> images; //fiecare imagine va avea un id propriu
	 map<string, bool> collisionImage;

public:
	static TextureManager tex;
	bool returnColision(string i) { return collisionImage[i]; }
	void Init();
	bool LoadTexture(string id, const char* name); //incarcarea imaginilor in mapa
	void Draw(string id, Position a, int wid, int hei, bool background);
	void DrawFrame(string id, Position* a, int size, int frame, int row, bool isPlayer);
	void Drop(string id);
	void clean();

};