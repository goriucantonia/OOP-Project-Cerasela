#pragma once

#include "GameObject.h"

class Character : public GameObject {

protected:
	enum State {
		//numarul de frame-uri ale fiecarei stari
		WALK = 8,
		RUN = 8,
		JUMP = 2,
		EMOTE = 3,
		FALL = 2,
		WAIT = 3 //PERSOANJUL STA PE LOC
	};
	enum Direction {
		//linia din png-uri care corespunde cu directia data
		LEFT = 1,
		RIGHT = 2,
		FRONT = 3
	};
	
	int direction; //linia din png care corepunde animatiei dorite (enum direction)

public:
	Character(string i, int x, int y, int as);


	void Update() {}
	void Render() {}
	void Clean() {}
	~Character();
};