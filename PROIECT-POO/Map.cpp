#include "Map.h"
#include "TextureManager.h"
#include <fstream>



GameMap::GameMap() {
}

void GameMap::LoadMap(int level){
	
	ifstream fin("lvl1.txt");
	switch (level) {
	case 1:
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < 30; j++) {
				fin >> map[i][j];
			}
		}
		break;
	default:
		break;
	}
	
}

void setCollisionTile(bool colTile) {
}

void GameMap::afisareMap() {

	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < 30; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}

void GameMap::DrawMap() {
	int type = 0;
	Position a;
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < 30; j++) {
			type = map[i][j];

			a.setX(j * tileSize);
			a.setY(i * tileSize);

			switch (type) {
			case 10:
				TextureManager::tex.Draw("10", a, tileSize, tileSize, 0); break;
			case 11:
				TextureManager::tex.Draw("11", a, tileSize, tileSize, 0); break;	
			case 12:
				TextureManager::tex.Draw("12", a, tileSize, tileSize, 0); break;
			case 13:
				TextureManager::tex.Draw("13", a, tileSize, tileSize, 0); break;
			case 14:
				TextureManager::tex.Draw("14", a, tileSize, tileSize, 0); break;
			case 15:
				TextureManager::tex.Draw("15", a, tileSize, tileSize, 0); break;
			case 16:
				TextureManager::tex.Draw("16", a, tileSize, tileSize, 0); break;
			case 17:
				TextureManager::tex.Draw("17", a, tileSize, tileSize, 0); break;
			case 18:
				TextureManager::tex.Draw("18", a, tileSize, tileSize, 0); break;
			case 19:
				TextureManager::tex.Draw("19", a, tileSize, tileSize, 0); break;
			case 20:
				TextureManager::tex.Draw("20", a, tileSize, tileSize, 0); break;
			case 21:
				TextureManager::tex.Draw("21", a, tileSize, tileSize, 0); break;
			case 22:
				TextureManager::tex.Draw("22", a, tileSize, tileSize, 0); break;
			case 23:
				TextureManager::tex.Draw("23", a, tileSize, tileSize, 0); break;
			case 24:
				TextureManager::tex.Draw("24", a, tileSize, tileSize, 0); break;
			case 25:
				TextureManager::tex.Draw("25", a, tileSize, tileSize, 0); break;
			case 30:
				TextureManager::tex.Draw("30", a, tileSize, tileSize, 0); break;
			case 31:
				TextureManager::tex.Draw("31", a, tileSize, tileSize, 0); break;
			case 32:
				TextureManager::tex.Draw("32", a, tileSize, tileSize, 0); break;
			case 33:
				TextureManager::tex.Draw("33", a, tileSize, tileSize, 0); break;
			case 34:
				TextureManager::tex.Draw("34", a, tileSize, tileSize, 0); break;
			default:
				break;

			}
		}
	}
}