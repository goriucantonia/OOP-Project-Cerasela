#pragma once


const int colCountLevel1 = 30;
const int colCountLevel2 = 40;
const int colCountLevel3 = 50;

class GameMap {

public:
	int map[20][50];
	GameMap();
	~GameMap(){}
	void LoadMap(int level);
	void DrawMap();
	void afisareMap();
};