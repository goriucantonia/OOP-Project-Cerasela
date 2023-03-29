#include "TextureManager.h"
#include "Camera.h"
#include <map>

//SDL_Texture is used in a hardware rendering, textures are stored in VRAM 
//and you don't have access to it directly as with SDL_Surface. 

//Hardware rendering is by orders of magnitude faster than software rendering
//and should be always be considered as primary option.

void TextureManager::Init() {
	//Loading player images
	LoadTexture("WAIT", "Sprites/Nothing.png");
	LoadTexture("WALK", "Sprites/Walk.png");
	LoadTexture("JUMP", "Sprites/Jump1.png");
	LoadTexture("EMOTE", "Sprites/Emotes.png");
	LoadTexture("RUN", "Sprites/Run.png");
	LoadTexture("FALL", "Sprites/Fall.png");
	//Loading map images
	LoadTexture("10", "Sprites/10.png");
	collisionImage["10"] = 1;
	LoadTexture("11", "Sprites/11.png");
	collisionImage["11"] = 1;
	LoadTexture("12", "Sprites/12.png");
	collisionImage["12"] = 1;
	LoadTexture("13", "Sprites/13.png");
	collisionImage["13"] = 1;
	LoadTexture("14", "Sprites/14.png");
	collisionImage["14"] = 1;
	LoadTexture("15", "Sprites/15.png");
	collisionImage["15"] = 1;
	LoadTexture("16", "Sprites/16.png");
	collisionImage["16"] = 1;
	LoadTexture("17", "Sprites/17.png");
	collisionImage["17"] = 1;
	LoadTexture("18", "Sprites/18.png");
	collisionImage["18"] = 1;
	LoadTexture("19", "Sprites/19.png");
	collisionImage["19"] = 1;
	LoadTexture("20", "Sprites/20.png");
	collisionImage["20"] = 1;
	LoadTexture("21", "Sprites/21.png");
	collisionImage["21"] = 1;
	LoadTexture("22", "Sprites/22.png");
	collisionImage["22"] = 1;
	LoadTexture("23", "Sprites/23.png");
	collisionImage["23"] = 1;
	LoadTexture("24", "Sprites/24.png");
	collisionImage["24"] = 1;
	LoadTexture("25", "Sprites/25.png");
	collisionImage["25"] = 1;

	LoadTexture("30", "Sprites/iarba.png");
	collisionImage["30"] = 0;
	LoadTexture("31", "Sprites/flori.png");
	collisionImage["31"] = 1;
	LoadTexture("32", "Sprites/piatra.png");
	collisionImage["32"] = 0;
	LoadTexture("33", "Sprites/sageataDreapta.png");
	collisionImage["33"] = 0;
	LoadTexture("34", "Sprites/sageataStanga.png");
	collisionImage["34"] = 0;

	//Load level background
	LoadTexture("level1", "Sprites/LEVEL1.png");

	//Load game objects
	LoadTexture("crystal", "Sprites/coinPurple.png");
}

bool TextureManager::LoadTexture(string id, const char* name) {
	SDL_Surface* tmpSurface = IMG_Load(name);
	if (tmpSurface == NULL)
	{
		cout << "Unable to load image!" << SDL_GetError() << endl;
		return 0;
	}
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
	if (tex == NULL)
	{
		cout << "Unable to create texture!" << SDL_GetError() << endl;
		return 0;
	}
	SDL_FreeSurface(tmpSurface);
	images[id] = tex;
	return 1;
}

void TextureManager::Draw(string id, Position a, int wid, int hei, bool background) {
	Position cam = Camera::camera.getPosition();
	if (background == true) {
		cam = cam * 0.5;
		//pentru a injumatati timpul de randare al backgroundului, fata de randarea tile-urilor
	}
	
	SDL_Rect src = { 0, 0, wid, hei };
	SDL_Rect dest = { a.getX() - cam.getX(), a.getY() - cam.getY(), wid, hei };
	SDL_RenderCopy(Game::renderer, images[id], &src, &dest);
}

void TextureManager::DrawFrame(string id, Position* a, int size, int frame, int row, bool isPlayer) {
	Position cam = Camera::camera.getPosition();
	SDL_Rect src = { size*frame, size*(row-1), size, size };
	
	if (isPlayer == true) {
		size = 2 * tileSize;
	}
	else {
		size = tileSize;
	}
	SDL_Rect dest = { a->getX() - cam.getX(), a->getY() - cam.getY(), size, size };
	SDL_RenderCopy(Game::renderer, images[id], &src, &dest);
	//cout << " x este: " << a->getX() << "  Y ESTE:  " << a->getY();
}

void TextureManager::Drop(string id) {
	SDL_DestroyTexture(images[id]);
	images.erase(id);
}
void TextureManager::clean() {
	map<string, SDL_Texture*>::iterator it;
	for (it = images.begin(); it != images.end(); it++) {
		SDL_DestroyTexture(it->second);
	}
	images.clear();
}
