#pragma once

#include <SDL.h>
#include <iostream>
#include <map>
#include "Map.h"

using namespace std;

// global immutable variables
const int pixelsPerTile = 32;
const int playerSize = 64;
const int tileSize = pixelsPerTile * 2; //pixelsPerTile * scale = 64*64 pixels
const int rowCount = 15;
const int colCount = 18;
const int screenWid = tileSize * colCount; //dimensiune * numarul de coloare (lungimea ferestrei)
const int screenHei = tileSize * rowCount; //dimensiune * numarul de linii (latimea ferestrei)



class Game {

private:
	bool isRunning; // 1-daca jocul ruleaza; 0-daca jocul e oprit
	SDL_Window* window; //meniul ferestrei
	GameMap* levelMap;
	Game(); // contructor privat pentru a crea doar o instanta
	
public:
	int contor = 0;
	static SDL_Renderer* renderer; //interfata ferestrei
	static SDL_Event event;
	static Game game;

	~Game(); //destructor
	void init(const char* title, int x, int y, int width, int height); //initializarea jocului
	void events();
	void update();
	void render();
	void clean(); //distrugerea jocului
	bool running(); //returneaza daca jocul ruleaza

	GameMap* getMap() { return levelMap; }

	
	
	 

	//void timer();
	//static Game* Instance();
};